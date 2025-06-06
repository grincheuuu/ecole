#include "Server.hpp"


// Constructor & Destructor
Server::Server(void)
{
}

Server::Server(const Server &copy)
{
	*this = copy;
}

Server &Server::operator=(const Server &copy)
{
	(void)copy;
	return (*this);
}

Server::~Server(void)
{
}


// Other function
bool hasBlaExtension(const std::string &filename)
{
    size_t pos = filename.rfind(".bla");
    return (pos != std::string::npos) && (pos + 4 == filename.size());
}
std::string trim(std::string str)
{
    size_t first = str.find_first_not_of(" \r\n\t");
    if (first == std::string::npos)
        return ("");
    else
    {
        size_t last = str.find_last_not_of(" \r\n\t");
        return (str.substr(first, (last - first + 1)));
    }
}
bool HasPyExtension(const std::string &url, const std::string &ext)
{
    size_t lastSlashPos = url.find_last_of('/');
    std::string filename;
    (void)ext;
    lastSlashPos = url.find("CGI");
    if (lastSlashPos != std::string::npos)
        filename = url.substr(lastSlashPos + 1);
    else
        filename = url;
    size_t dotPos = filename.find_last_of('.');
    if (dotPos != std::string::npos)
    {
        std::string extension = filename.substr(dotPos, 3);
        return (extension == ext);
    }
    return (false);
}
bool running = true;
void handle_signal(int signal)
{
    if (signal == SIGINT)
        running = false;
}
void Server::InitSocket(const std::list< std::multimap< std::string, std::vector<std::string> > > &conf)
{
	signal(SIGINT, handle_signal);

    // Création de l'instance epoll
    epoll_fd = epoll_create1(0);
    if (epoll_fd < 0)
		throw EpollException();

    std::list< std::multimap<std::string, std::vector<std::string> > >::const_iterator it = conf.begin();
    while(it != conf.end())
    {
        std::multimap< std::string, std::vector<std::string> > vi = *it;
        // port
        std::multimap<std::string, std::vector<std::string> >::const_iterator it_port = vi.find("listen");
        if (it_port == vi.end())
        {
            ++it;
            continue;
        }
        std::vector<std::string> recup_port = it_port->second;
        int port = std::atoi(recup_port[0].c_str());
        // adress
        std::multimap<std::string, std::vector<std::string> >::const_iterator it_host = vi.find("host");
        if (it_host == vi.end())
        {
            ++it;
            continue;
        }
        std::vector<std::string> recup_host = it_host->second;
        std::string host = recup_host[0];

        // 1. Création du socket
        int server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd == 0)
            throw SocketException();
        int flags = fcntl(server_fd, F_GETFL, 0);
        fcntl(server_fd, F_SETFL, flags | O_NONBLOCK);

        // 2. Configuration de l'adresse
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = inet_addr(host.c_str());
        address.sin_port = htons(port);
        addrlen = sizeof(address);

        // 3. Liaison du socket au port
        int opt = 1;
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
            throw SetsockoptException();
        if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0)
            throw BindException();

        // 4. Mise en écoute
        if (listen(server_fd, SOMAXCONN) < 0)
            throw ListenException();

        // 5. Ajout du socket serveur à epoll
        struct epoll_event ev;
        ev.events = EPOLLIN;
        ev.data.fd = server_fd;
        if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_fd, &ev) < 0)
            throw EpollException();

        _server_fds.push_back(server_fd);
        _serv_info[server_fd] = *it;

        char draw_host[NI_MAXHOST];
        if (getnameinfo((struct sockaddr*)&address, sizeof(address), draw_host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST) != 0)
            std::cerr << "Error getting address" << std::endl;
        else
            std::cout << Green << "Serveur listen : " << server_fd << " - " << draw_host << ":" << port << Reset_Color << std::endl;

        it++;
    }
    std::cout << std::endl;
}

void Server::ManageConnection(void)
{
	// 7. Boucle principale
    struct epoll_event events[MAX_EVENTS];
    while (running)
	{
        int event_count = epoll_wait(epoll_fd, events, MAX_EVENTS, 60000);
        if (event_count < 0)
		{
			if (errno == EINTR)
				continue;
			throw EpollWaitException();
		}
        time_t now = time(NULL);
        for (std::map<int, time_t>::iterator it = _client_last_active.begin(); it != _client_last_active.end();)
        {
            if (now - it->second > 59)
            {
                std::cout << Red << Server::GetTime() << " " << "Timeout, client disconnect " << it->first << Reset_Color << std::endl;
                epoll_ctl(epoll_fd, EPOLL_CTL_DEL, it->first, NULL);
                close(it->first);
                _client_last_active.erase(it++);
            }
            else
                ++it;
        }

        // 8. Parcours des événements détectés
        for (int i = 0; i < event_count; i++)
		{
            int event_fd = events[i].data.fd;

            // 8.1 Nouvelle connexion entrante
            if (std::find(_server_fds.begin(), _server_fds.end(), event_fd) != _server_fds.end())
			{
                int new_socket = accept(event_fd, (struct sockaddr*)&address, &addrlen);
                if (new_socket < 0)
				{
                    std::cerr << "Accept error" << std::endl;
                    continue;
                }
                _client_last_active[new_socket] = time(NULL);
                std::cout << Green << Server::GetTime() << " " << "New connection from : " << new_socket << Reset_Color << std::endl;

                // Met le client en mode non-bloquant
				int flags = fcntl(new_socket, F_GETFL, 0);
    			fcntl(new_socket, F_SETFL, flags | O_NONBLOCK);

                // Ajoute le client à epoll
                struct epoll_event client_ev;
                client_ev.events = EPOLLIN; // EPOLLET| EPOLLONESHOT
                client_ev.data.fd = new_socket;
                epoll_ctl(epoll_fd, EPOLL_CTL_ADD, new_socket, &client_ev);

                _serv_info[new_socket] = _serv_info[event_fd];
            }
            // 8.2 Requête d'un client existant
            else {
                char buffer[BUFFER_SIZE] = {0};
                int valread = read(event_fd, buffer, sizeof(buffer) - 1);

                if (valread <= 0)
				{
                    std::cout << Red << Server::GetTime() << " " << "Client disconnect " << event_fd << Reset_Color << std::endl;
                    epoll_ctl(epoll_fd, EPOLL_CTL_DEL, event_fd, NULL);
                    close(event_fd);
                }
				else {
                    static std::map<int, std::string> client_buffers;
                    client_buffers[event_fd] += std::string(buffer, valread);

                    std::string &full_request = client_buffers[event_fd];
                    size_t request_end_pos = full_request.find("\r\n\r\n");

                    if (request_end_pos != std::string::npos)
                    {
                        // Get config info for the socket
                        std::string bodymax;
                        std::string error404;
                        std::string error500;
                        std::list<std::map<std::string, std::string> > locations;
                        std::map<int, std::multimap<std::string, std::vector<std::string> > >::const_iterator map_it = _serv_info.find(event_fd);
                        if (map_it != _serv_info.end())
                        {
                            std::multimap<std::string, std::vector<std::string> > mmap = map_it->second;

                            locations = ConfParsing::getLocation(mmap);

                            std::multimap<std::string, std::vector<std::string> >::const_iterator it_bodymax = mmap.find("body-max");
                            if (it_bodymax != mmap.end())
                                bodymax = it_bodymax->second[0];
                            std::multimap<std::string, std::vector<std::string> >::const_iterator it_error404 = mmap.find("error_page404");
                            if (it_error404 != mmap.end())
                                error404 = it_error404->second[0];
                            std::multimap<std::string, std::vector<std::string> >::const_iterator it_error500 = mmap.find("error_page500");
                            if (it_error500 != mmap.end())
                                error500 = it_error500->second[0];
                        }

                        // Parsing Http request
                        HttpRequest request;
                        try {
                            request.ParseRequest(full_request);
                        } catch (std::exception &e) {
                            std::cerr << e.what() << std::endl;
                            epoll_ctl(epoll_fd, EPOLL_CTL_DEL, event_fd, NULL);
                            close(event_fd);
                            continue;
                        }
                        client_buffers[event_fd].clear();

                        // Check path for choice the location
                        std::string path = request.GetPath();
                        std::string parse_path;
                        if (path == "/")
                            parse_path = "/";
                        else
                        {
                            std::size_t pos = path.find('/', 1);
                            // parse_path = path.substr(0, pos + 1);
                            // if (pos == std::string::npos)
                            //     parse_path = path;
                            // else
                            //     parse_path = path.substr(0, pos + 1);
                            if (pos == std::string::npos)
                                parse_path = path + "/";
                            else
                                parse_path = path.substr(0, pos + 1);
                        }
                        std::map<std::string, std::string> selected_location;
                        for (std::list<std::map<std::string, std::string> >::const_iterator it_locations = locations.begin(); it_locations != locations.end(); ++it_locations)
                        {
                            if (!it_locations->empty())
                            {
                                std::map<std::string, std::string>::const_iterator it_location = it_locations->find("location");
                                if (it_location != it_locations->end() && trim(it_location->second) == parse_path.c_str())
                                {
                                    for (std::map<std::string, std::string>::const_iterator it_map = it_locations->begin(); it_map != it_locations->end(); ++it_map)
                                        selected_location = *it_locations;
                                    break;
                                }
                            }
                        }
                        if (!selected_location.empty())
                        {
                            if (path.length() != parse_path.length() - 1 && path != "/")
                            {
                                std::string file = path.substr(parse_path.length());
                                if (!file.empty())
                                    path = selected_location["root"] + file;
                            }
                            else
                            {
                                std::map<std::string, std::string>::const_iterator it_root = selected_location.find("root");
                                std::map<std::string, std::string>::const_iterator it_default = selected_location.find("index");

                                if (it_root != selected_location.end() && it_default != selected_location.end())
                                    path = it_root->second + it_default->second;
                            }
                        }

                        // Init response str
                        std::string responseStr;

                        // Limit body size
                        static std::map<int, int> clientBodySize;
                        clientBodySize[event_fd] = request_end_pos;
                        std::istringstream iss(bodymax);
                        int result = 0;
                        iss >> result;
                        if (clientBodySize[event_fd] > result)
                        {
                            HttpResponse response;
                            response.SetStatus(413);
                            response.SetKeepAlive(false);
                            std::string responseStr = response.ToString();
                            // send(event_fd, responseStr.c_str(), responseStr.size(), 0);
                            if (send(event_fd, responseStr.c_str(), responseStr.size(), 0) < 0)
                                continue;

                            std::cout << Red << Server::GetTime() << " " << "Body too large from client " << event_fd << Reset_Color << std::endl;
                            epoll_ctl(epoll_fd, EPOLL_CTL_DEL, event_fd, NULL);
                            close(event_fd);
                            clientBodySize.erase(event_fd);
                            continue;
                        }

                        // Check si keep-alive est dans les headers
                        const std::map<std::string, std::string> &headers = request.GetHeaders();
                        bool keep_alive = false;
                        std::map<std::string, std::string>::const_iterator it = headers.find("Connection");  
                        if (it != headers.end() && it->second == "keep-alive")
                            keep_alive = true;

                        // std::string responseStr;
                        // Check if method is ok
                        if (!selected_location["allow_methods"].empty())
                        {
                            std::set<std::string> allowed_methods;
                            std::istringstream methods_stream(selected_location["allow_methods"]);
                            std::string method;
                            while (methods_stream >> method)
                                allowed_methods.insert(method);
                            if (allowed_methods.find(request.GetMethod()) == allowed_methods.end())
                            {
                                HttpResponse response;
                                response.SetStatus(405);
                                response.SetHeader("Allow", selected_location["allow_methods"]);
                                std::string responseStr = response.ToString();
                                // send(event_fd, responseStr.c_str(), responseStr.size(), 0);
                                if (send(event_fd, responseStr.c_str(), responseStr.size(), 0) < 0)
                                    continue;
                                std::cout << Red << Server::GetTime() << " " << "Client disconnect " << event_fd << Reset_Color << std::endl;
                                epoll_ctl(epoll_fd, EPOLL_CTL_DEL, event_fd, NULL);
                                close(event_fd);
                                clientBodySize.erase(event_fd);
                                continue;
                            }
                        }

                        // Cgi exec
                        if (HasPyExtension(path, selected_location["cgi_extension"]) == true)
                        {
                            CgiExecution abc(selected_location["root"], selected_location["index"], selected_location["cgi_path"], request.GetMethod(), request.GetPath(), request.GetBody(), request.GetVersion(), request.GetHeaders());
                            abc.methodeType(path);
                            responseStr = abc.getResponseCgi();
                        }
                        else
                        {
                            // Http response
                            HttpResponse response;
                            try {
                                response.ServeFile(path, selected_location["index"], error404, error500);
                                if (keep_alive == true)
                                    response.SetKeepAlive(true);
                                else
                                    response.SetKeepAlive(false);
                                response.SetCookieSession(request);
                            } catch (std::exception &e) {
                                std::cerr << e.what() << std::endl;
                                epoll_ctl(epoll_fd, EPOLL_CTL_DEL, event_fd, NULL);
                                close(event_fd);
                                clientBodySize.erase(event_fd);
                            }
                            responseStr = response.ToString();
                        }

                        // send(event_fd, responseStr.c_str(), responseStr.size(), 0);
                        if (send(event_fd, responseStr.c_str(), responseStr.size(), 0) < 0)
                                continue;
                        if (keep_alive == false)
                        {
                            std::cout << Red << Server::GetTime() << " " << "Client disconnect " << event_fd << Reset_Color << std::endl;
                            epoll_ctl(epoll_fd, EPOLL_CTL_DEL, event_fd, NULL);
                            close(event_fd);
                            clientBodySize.erase(event_fd);
                        }
                    }
                    else
                        continue;
                }
            }
        }
    }
    
    // 9. Fermeture du socket client
    for (std::vector<int>::iterator it = _server_fds.begin(); it != _server_fds.end(); ++it)
        close(*it);
    close(epoll_fd);
	std::cout << std::endl << std::endl << Deny << Red << " Server close" << Reset_Color << std::endl << std::endl;
}

std::string Server::GetTime(void)
{
    time_t actuel = time(0);
    tm *ltm = localtime(&actuel);
    std::ostringstream timeStr;
    timeStr << "[" 
               << (1900 + ltm->tm_year) << "-"  // Année
               << std::setw(2) << std::setfill('0') << (1 + ltm->tm_mon) << "-"  // Mois avec 0 devant
               << std::setw(2) << std::setfill('0') << ltm->tm_mday << " "       // Jour avec 0 devant
               << ltm->tm_hour << ":"          // Heure
               << ltm->tm_min << ":"           // Minute
               << ltm->tm_sec << "]";          // Seconde

    return (timeStr.str());
}
