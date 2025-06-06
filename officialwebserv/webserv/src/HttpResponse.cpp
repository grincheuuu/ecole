#include "HttpResponse.hpp"


// Constructor & Destructor
HttpResponse::HttpResponse(void) : _code(0), _msg(""), _body("")
{
}

HttpResponse::HttpResponse(const HttpResponse &copy)
{
	*this = copy;
}

HttpResponse &HttpResponse::operator=(const HttpResponse &copy)
{
	(void)copy;
	return (*this);
}

HttpResponse::~HttpResponse(void)
{
}


// Other function
void HttpResponse::SetStatus(const int code)
{
    this->_code = code;

    std::map<int, std::string> messages;
    messages[200] = "OK";
    messages[201] = "Created";
    messages[204] = "No Content";
    messages[301] = "Moved Permanently";
    messages[400] = "Bad Request";
    messages[401] = "Unauthorized";
    messages[403] = "Forbidden";
    messages[404] = "Not Found";
    messages[405] = "Method Not Allowed";
    messages[413] = "Request Entity Too Large";
    messages[500] = "Internal Server Error";
    messages[503] = "Service Unavailable";
    if (messages.find(code) != messages.end())
        this->_msg = messages[code];
    else
        throw MessageStatusNotFoundException();
}

void HttpResponse::SetHeader(const std::string &key, const std::string &value)
{
    this->_headers[key] = value;
}

void HttpResponse::SetBody(const std::string &body)
{
    this->_body = body;
    std::ostringstream size;
    size << body.size();
    SetHeader("Content-Length", size.str());
}

void HttpResponse::SetKeepAlive(const bool keepAlive)
{
    if (keepAlive == true)
        SetHeader("Connection", "keep-alive");
    else
        SetHeader("Connection", "close");
}

void initRandom() {
    static bool initialized = false;
    if (!initialized)
    {
        srand(time(0));
        initialized = true;
    }
}
std::string generateSessionId(void)
{
    initRandom();
    std::ostringstream oss;
    oss << "session_" << (rand() % 100000);
    return (oss.str());
}
void HttpResponse::SetCookieSession(HttpRequest &request)
{
    std::map<std::string, std::string> headers = request.GetHeaders();
    std::string session_id;
    if (headers.find("Cookie") != headers.end())
    {
        std::string cookies = headers["Cookie"];
        size_t pos = cookies.find("session_id=");
        if (pos != std::string::npos)
        {
            session_id = cookies.substr(pos + 11);
            size_t end = session_id.find(";");
            if (end != std::string::npos)
                session_id = session_id.substr(0, end);
        }
    }
    // if (session_id.empty() || this->_session_map.find(session_id) == this->_session_map.end())
    if (session_id.empty())
    {
        session_id = generateSessionId();
        this->_session_map[session_id] = "UserData";
    }
    if (headers.find("Cookie") == headers.end())
        SetHeader("Set-Cookie", "session_id=" + session_id + "; Path=/; HttpOnly");
}

bool FileExists(const std::string &filename)
{
    // struct stat buffer;
    // return (stat(filename.c_str(), &buffer) == 0);

    struct stat s;
    if (stat(filename.c_str(), &s) == 0)
        return S_ISREG(s.st_mode);
    return false;
}
std::string GetMimeType(const std::string &filePath)
{
    size_t dotPos = filePath.find_last_of(".");
    if (dotPos == std::string::npos) return "application/octet-stream";

    std::string ext = filePath.substr(dotPos);
    if (ext == ".html" || ext == ".htm") return "text/html";
    if (ext == ".css") return "text/css";
    if (ext == ".js") return "application/javascript";
    if (ext == ".png") return "image/png";
    if (ext == ".jpg" || ext == ".jpeg") return "image/jpeg";
    if (ext == ".gif") return "image/gif";
    if (ext == ".svg") return "image/svg+xml";
    return "application/octet-stream";
}
void HttpResponse::ServeFile(const std::string &file_path, const std::string &index, const std::string &error404, const std::string &error500)
{
    std::string fullPath = file_path;
    // std::cout << fullPath << std::endl;

    struct stat s;
    if (stat(fullPath.c_str(), &s) == 0 && S_ISDIR(s.st_mode))
    {
        std::string indexFile = fullPath + "/" + index;
        if (stat(indexFile.c_str(), &s) == 0 && S_ISREG(s.st_mode))
            fullPath = indexFile;
        else
        {
            fullPath = error404;
            std::ifstream file(fullPath.c_str(), std::ios::binary);
            std::ostringstream buffer;
            buffer << file.rdbuf();
            file.close();

            SetStatus(404);
            SetBody(buffer.str());
            SetHeader("Content-Type", GetMimeType(fullPath));
            return;
        }
    }

    if (!FileExists(fullPath))
    {
        fullPath = error404;
        std::ifstream file(fullPath.c_str(), std::ios::binary);
        std::ostringstream buffer;
        buffer << file.rdbuf();
        file.close();

        SetStatus(404);
        SetBody(buffer.str());
        SetHeader("Content-Type", GetMimeType(fullPath));
        return;
    }

    std::ifstream file(fullPath.c_str(), std::ios::binary);
    if (!file.is_open())
    {
        fullPath = error500;
        file.open(fullPath.c_str(), std::ios::binary);
        std::ostringstream buffer;
        buffer << file.rdbuf();
        file.close();

        SetStatus(500);
        SetBody(buffer.str());
        SetHeader("Content-Type", GetMimeType(fullPath));
        return;
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();
    file.close();

    SetStatus(200);
    SetBody(buffer.str());
    SetHeader("Content-Type", GetMimeType(fullPath));
}

std::string HttpResponse::ToString() const
{
    std::ostringstream response;

    response << "HTTP/1.1 " << this->_code << " " << this->_msg << "\r\n";
    for (std::map<std::string, std::string>::const_iterator it = this->_headers.begin(); it != this->_headers.end(); ++it) {
        response << it->first << ": " << it->second << "\r\n";
    }
    response << "\r\n";
    response << this->_body;

    return (response.str());
}
