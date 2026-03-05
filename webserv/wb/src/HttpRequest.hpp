#pragma once

#include <iostream>  	// base
#include <sstream>		// text gestion
#include <map> 			// map
#include <vector> 		// vector
#include <algorithm> 	// algo
#include <vector>

#include "Utils.hpp"


class HttpRequest
{
	private:
		std::string _method;
		std::string _path;
		std::string _version;
		std::map<std::string, std::string> _headers;
		std::vector<char> _body;
	public:
		HttpRequest();
		HttpRequest(const HttpRequest &copy);
		HttpRequest &operator=(const HttpRequest &copy);
		~HttpRequest();

		// Other function
        void ParseRequest(std::string buffer);

		std::vector<char> decodeChunkedBody(const std::vector<char> &body);
		const std::string GetMethod(void);
		const std::string GetPath(void);
		const std::string GetVersion(void);
		const std::map<std::string, std::string> &GetHeaders(void);
		const std::vector<char> GetBody(void);

		// Exceptions
		class HttpRequestLineException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("\033[0;31mHttp request line error\033[0m");
				}
		};
		class MethodException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("\033[0;31mMethod request error\033[0m");
				}
		};
		class HttpVersionException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("\033[0;31mHttp version error\033[0m");
				}
		};
		class HeadersException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("\033[0;31mHeaders error\033[0m");
				}
		};
};
