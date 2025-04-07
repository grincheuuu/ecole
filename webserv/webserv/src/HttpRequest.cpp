#include "HttpRequest.hpp"
#include "Server.hpp"


// Constructor & Destructor
HttpRequest::HttpRequest(void) : _method(""), _path(""), _version("")
{
}

HttpRequest::HttpRequest(const HttpRequest &copy)
{
	*this = copy;
}

HttpRequest &HttpRequest::operator=(const HttpRequest &copy)
{
	(void)copy;
	return (*this);
}

HttpRequest::~HttpRequest(void)
{
}


// Other function
void trim(std::string &str)
{
    // Supprimer les espaces et les retours à la ligne en début et fin de chaîne
    size_t first = str.find_first_not_of(" \r\n\t");
    if (first == std::string::npos) {
        str = "";  // La chaîne ne contient que des espaces blancs
    } else {
        size_t last = str.find_last_not_of(" \r\n\t");
        str = str.substr(first, (last - first + 1));
    }
}
void HttpRequest::ParseRequest(std::string buffer)
{
    std::stringstream ss(buffer);
    std::string method, path, version;

    // 1. Request Line
    std::getline(ss, method, ' ');
    std::getline(ss, path, ' ');
    std::getline(ss, version, '\r');
    ss.get();
    trim(version);

    if (method.empty() || path.empty() || version.empty())
        throw HttpRequestLineException();
    if (method != "GET" && method != "POST" && method != "DELETE" && method != "HEAD")
        throw MethodException();
    if (version != "HTTP/1.1")
        throw HttpVersionException();

    this->_method = method;
    this->_path = path;
    this->_version = version;

    // 2. Parse headers
    std::string header_line;
    bool isChunked = false;

    while (std::getline(ss, header_line, '\r'))
    {
        ss.get(); // Discard '\n'
        trim(header_line);
        if (header_line.empty()) break;

        size_t split_pos = header_line.find(':');
        if (split_pos != std::string::npos && split_pos + 1 < header_line.size())
        {
            std::string key = header_line.substr(0, split_pos);
            std::string value = header_line.substr(split_pos + 1);
            trim(key);
            trim(value);
            this->_headers[key] = value;

            if (key == "Transfer-Encoding" && value == "chunked")
                isChunked = true;
        }
        else
        {
            throw HeadersException();
        }
    }

    // 3. Get body (binary-safe)
    std::vector<char> body_content((std::istreambuf_iterator<char>(ss)), std::istreambuf_iterator<char>());

    if (isChunked)
        this->_body = decodeChunkedBody(body_content);
    else
        this->_body = body_content;

    std::cout << Purple << Server::GetTime() << " " << this->_method << " " << this->_path << " " << this->_version << Reset_Color << std::endl;
}

std::vector<char> HttpRequest::decodeChunkedBody(const std::vector<char> &body)
{
    std::istringstream stream(std::string(body.begin(), body.end()));
    std::vector<char> decodedBody;
    std::string chunkSizeStr;
    size_t chunkSize = 0;

    while (std::getline(stream, chunkSizeStr)) // Lire la taille du chunk
    {
        trim(chunkSizeStr);
        chunkSize = std::strtol(chunkSizeStr.c_str(), NULL, 16);
        if (chunkSize == 0)
            break;

        std::vector<char> chunkData(chunkSize); // Stocker les données du chunk
        stream.read(chunkData.data(), chunkSize);
        decodedBody.insert(decodedBody.end(), chunkData.begin(), chunkData.end());

        // Passer le CRLF après le chunk (vérification plus sûre)
        if (stream.peek() == '\r') stream.get();
        if (stream.peek() == '\n') stream.get();
    }
    return decodedBody;
}

const std::string HttpRequest::GetMethod(void)
{
    return (this->_method);
}
const std::string HttpRequest::GetPath(void)
{
    return (this->_path);
}
const std::string HttpRequest::GetVersion(void)
{
    return (this->_version);
}
const std::map<std::string, std::string> &HttpRequest::GetHeaders(void)
{
    return (this->_headers);
}
const std::vector<char> HttpRequest::GetBody(void)
{
    return (this->_body);
}
