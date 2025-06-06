#include "Utils.hpp"

#include "ConfParsing.hpp"
#include "Server.hpp"

int main(int argc, char**argv)
{
    // check args
    if (argc != 2)
    {
        std::cerr << Deny << Red << "Error wrong args\n" << Yellow << "Try : ./webserv [file].conf" << Reset_Color << std::endl;
        return (1);
    }

    try {
        ConfParsing configuration(argv[1]);				// Lire le fichier et mettre les infos dans les private du server

        Server server;
        server.InitSocket(configuration.getConf());		// Initialiser les sockets pour chaque server et les mettres en ecoute
        server.ManageConnection();						// Gerer les connections (plusieurs clients), differentes requetes http (get, post, etc ...), reponses http et CGI
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }

	return (0);
}
