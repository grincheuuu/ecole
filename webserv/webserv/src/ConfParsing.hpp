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
# include <stack>

#include "Utils.hpp"

class ConfParsing
{
    private:
        std::list< std::multimap< std::string, std::vector<std::string> > > _def;
        std::string _path;

    public:
        ConfParsing(std::string arg);
        ConfParsing(const ConfParsing &copy);
		ConfParsing &operator=(const ConfParsing &copy);
        ~ConfParsing();

        // Other function
        void ParseConfigurationFile(void);
        std::string parsConfDeux(std::string ligne);
		const std::list< std::multimap< std::string, std::vector<std::string> > > &getConf(void) const;
        static std::list<std::map<std::string, std::string> > getLocation(const std::multimap< std::string, std::vector<std::string> > &configMap);

		// Exceptions
		class BadParsingException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("\033[0;31mConfiguration parsing error\033[0m");
				}
		};
};

std::ostream &operator<<(std::ostream &, ConfParsing const &src);