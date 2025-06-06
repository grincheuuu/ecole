#include "CgiExecution.hpp"


// Constructor & Destructor
CgiExecution::CgiExecution(const std::string &roothtml, const std::string &defaut, const std::string &pathPython, const std::string &method, const std::string &path, const std::vector<char> &body, const std::string &version, const std::map<std::string, std::string> &header) : _roothtml(roothtml), _defaut(defaut), _pythonPath(pathPython), _realPath(""), _method(method), _path(path), _body(body), _version(version), _responseCgi("unknow"), _header(header)
{
}

CgiExecution::CgiExecution(const CgiExecution &copy) : _roothtml(copy._roothtml), _defaut(copy._defaut), _pythonPath(copy._pythonPath), _realPath(copy._realPath), _method(copy._method), _path(copy._path), _body(copy._body), _version(copy._version), _responseCgi(copy._responseCgi), _header(copy._header)
{
    *this = copy;
}

CgiExecution &CgiExecution::operator=(const CgiExecution &copy)
{
    if (this != &copy)
        *this = copy;
    return (*this);
}

CgiExecution::~CgiExecution(void)
{
}


// Other function
void CgiExecution::methodeType(std::string &path)
{
    char **envp;

    envp = (char **)malloc(12 * sizeof(char *));
    if (envp == NULL)
        return;
    envp[11] = NULL;
    std::map<std::string, std::string>::const_iterator it3 = _header.find("Content-Length");
    if (it3 == _header.end())
        envp[0] = strdup("CONTENT_LENGTH=0");
    else
    {
        std::string temp = "CONTENT_LENGTH=" + it3->second;
        envp[0] = strdup(temp.c_str());
    }
    if (_method == "GET")
        this->parsQueryString(_path);
   else if (_method == "POST")
       this->parsBody(_body);
    else if (_method == "DELETE")
        this->functionDelete();
    envp[1] = strdup(("QUERY_STRING=" + _realPath).c_str());
    envp[2] = strdup(("REQUEST_METHOD=" + _method).c_str());
    envp[3] = strdup(("SERVER_SOFTWARE=" + _version).c_str());
    std::map<std::string, std::string>::const_iterator it2 = _header.find("User-Agent");
    if (it2 != _header.end())
        envp[4] = strdup(("REMOTE_USER=" + it2->second).c_str());
    else
        envp[4] = strdup("REMOTE_USER=");
    std::map<std::string, std::string>::const_iterator it = _header.find("Host");
    if (it != _header.end())
        envp[5] = strdup(("SERVER_NAME=" + it->second).c_str());
    else
        envp[5] = strdup("SERVER_NAME=");
    std::map<std::string, std::string>::const_iterator itm = _header.find("Content-Type");
    if (itm != _header.end())
        envp[6] = strdup(("CONTENT_TYPE=" + itm->second).c_str());
    else
        envp[6] = strdup("CONTENT_TYPE=");
    envp[7] = strdup("SERVER_PORT=");
    envp[8] = strdup(("PATH_INFO=" + _pythonPath).c_str());
    envp[9] = strdup("");
    std::map<std::string, std::string>::const_iterator itr = _header.find("Referer");
    if (itr != _header.end())
        envp[9] = strdup(("SCRIPT_NAME=" + itr->second).c_str());
    else
        envp[9] = strdup("SCRIPT_NAME=");
    envp[10] = strdup("REMOTE_ADDR=");
    for(int i = 0; envp[i] != NULL; i++)
        printf("%s\n", envp[i]);
    executeCgi(envp, path);
    ft_fre(envp);
}

void CgiExecution::functionDelete()
{
    return;
}

void ft_fre(char **str)
{
    if (str == NULL)
        return;
    for(int i = 0; str[i] != NULL; i++)
        free(str[i]);
    free(str);
}

char *ft_strdup(const char *str)
{
    int i = 0;
    char *result;
    if (str == NULL)
        return (NULL);
    while (str[i] != '\0')
        i++;
    result = (char *)malloc((i + 1) * sizeof(char));
    if (!result)
        return (NULL);
    i = 0;
    while (str[i] != '\0')
    {
        result[i] = str[i];
        i++;
    }
    result[i] = '\0';
    return (result);
}

void CgiExecution::parsQueryString(std::string &str)
{
    (void)str;
    // std::string _path = "sfgfgfs?name=guigui&comment=pars";
    size_t t = str.find('?');
    if (t != std::string::npos && ++t != std::string::npos)
    {
        std::string path = str.substr(t);
        _realPath = path;
    }
}

void CgiExecution::parsBody(std::vector<char> &str)
{
    (void)str;
    if (str.empty())
    {
        write(1, "", 1);
        return;
    }
    // write(0, str.c_str(), str.size());
}

std::string       CgiExecution::ft_script_path(std::string env)
{
    std::string     script = _defaut;
    if (env.empty())
    {
        script = "hello.py";
        std::string  path = _roothtml + '/' + script;
        return (path);
    }
    size_t  lastslash = env.find_last_of('/');
    size_t  end = env.find_last_of('_');
    std::string     temp = env.substr(lastslash + 1, end - lastslash - 1);
    
    if (temp == "t2")
        script = "world.py";
    else if (temp == "televerser")
        script = "televerser.py";
    else if (temp == "delete")
        script = "delete.py";
    else
        script = "hello.py";
    std::string  path = _roothtml + '/' + script;
    return (path);
}

void CgiExecution::executeCgi(char **envp, std::string &path)
{
    int pipe_fd[2];
    int pipe_in[2];
    pid_t pid;

    (void)path;
    if (pipe(pipe_fd) == -1 || pipe(pipe_in) == -1)
    {
        printf("pipe :%s", strerror(errno));
        ft_fre(envp);
        return;
    }
    pid = fork();
    if (pid < 0)
    {
        printf("fork :%s", strerror(errno));
        ft_fre(envp);
        return;
    }
    if (pid == 0)
    {
        dup2(pipe_in[0], STDIN_FILENO);
        close(pipe_in[0]);
        close(pipe_in[1]);
        close(pipe_fd[0]);
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(pipe_fd[1]);
        char **tab;
        tab = (char **)malloc(2 * sizeof(char*));
        tab[0] = ft_strdup(ft_script_path(envp[9]).c_str());
        tab[1] = NULL;
        if (access(tab[0], X_OK) == -1)
        {
            std::cerr << "Erreur d'accès à script cgi : " << strerror(errno) << std::endl;
            printf("ubuntu %s\n", tab[0]);
            ft_fre(envp);
            return;
        }
        execve(tab[0], tab, envp);
        ft_fre(envp);
        ft_fre(tab);
        std::cout << "echec execute" << std::endl;
    }
    else
    {
        close(pipe_in[0]);
        close(pipe_fd[1]);
        write(pipe_in[1], _body.data(), _body.size());
        close(pipe_in[1]);
        std::string     output_cgi = "";
        char            buf[10];
        ssize_t         bytes_read;
        while((bytes_read = read(pipe_fd[0], buf, sizeof(buf) - 1)) > 0)
        {
            buf[bytes_read] = '\0';
            output_cgi += buf;
        }
        if (!output_cgi.empty())
            _responseCgi = output_cgi;
        else
            std::cout << Red << "output_cgi erreur " << std::endl << Reset_Color << std::endl;
        close(pipe_fd[0]);      
    }
    wait(NULL);
}

std::string CgiExecution::getResponseCgi(void) const
{
    return (this->_responseCgi);
}
