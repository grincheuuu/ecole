#pragma once

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <stdexcept>
# include <algorithm>
# include <map>
# include <vector>
# include <ctype.h>
# include <list>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <string.h>
# include <fstream>
# include <vector>

# include "Utils.hpp"


class CgiExecution
{
	private:
        std::string _roothtml;
        std::string _defaut;
        std::string _pythonPath;
        std::string _realPath;
        std::string _method;
        std::string _path;
        std::vector<char> _body;
        std::string _version;
        std::string _responseCgi;
        std::map<std::string, std::string> const &_header;
    public:
        CgiExecution(const std::string &roothtml, const std::string &defaut, const std::string &pathPython, const std::string &method, const std::string &path, const std::vector<char> &body, const std::string &version, const std::map<std::string, std::string> &header);
        CgiExecution(const CgiExecution &src);
		CgiExecution &operator=(const CgiExecution &copy);
        ~CgiExecution(void);

		// Other function
        void methodeType(std::string &path);
        void parsQueryString(std::string &str);
        void parsBody(std::vector<char> &str);
        void executeCgi(char **envp, std::string &path);
        void functionDelete(void);
        std::string getResponseCgi(void) const;
        std::string      ft_script_path(std::string env);
};

void        ft_fre(char **str);
char*       ft_strdup(const char * str);