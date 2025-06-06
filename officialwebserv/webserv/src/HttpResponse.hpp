#pragma once

#include <iostream>  	// base
#include <sstream>		// text gestion
#include <map> 			// map
#include <sstream>		// file etc
#include <algorithm> 	// algo
#include <fstream>
#include <sys/stat.h>
#include <string>
#include <ctime>
#include <cstdlib>

#include "HttpRequest.hpp"
#include "Utils.hpp"


class HttpResponse
{
	private:
		int _code;
		std::string _msg;
		std::map<std::string, std::string> _headers;
		std::map<std::string, std::string> _session_map;
		std::string _body;
	public:
		HttpResponse();
		HttpResponse(const HttpResponse &copy);
		HttpResponse &operator=(const HttpResponse &copy);
		~HttpResponse();

		// Other function
		void SetStatus(const int code);
		void SetHeader(const std::string &key, const std::string &value);
		void SetBody(const std::string &body);
		void SetKeepAlive(const bool keepAlive);
		void SetCookieSession(HttpRequest &request);
		void ServeFile(const std::string &file_path, const std::string &index, const std::string &error404, const std::string &error500);
		std::string ToString() const;

		// Exceptions
		class MessageStatusNotFoundException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("\033[0;31mMessage status not found\033[0m");
				}
		};
};
