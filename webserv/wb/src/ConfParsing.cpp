#include "ConfParsing.hpp"


// Constructor & Destructor
ConfParsing::ConfParsing(std::string arg) : _path(arg)
{
    ParseConfigurationFile();
}

ConfParsing::ConfParsing(const ConfParsing &copy)
{
    *this = copy;
}

ConfParsing &ConfParsing::operator=(const ConfParsing &copy)
{
    if (this != &copy)
    {
        *this = copy; 
    }
    return (*this);
}

ConfParsing::~ConfParsing(void)
{
}


// Other function
void ConfParsing::ParseConfigurationFile(void)
{
    std::ifstream ifs;

    ifs.open(_path.c_str(), std::ifstream::in);
    if (!ifs)
        throw BadParsingException();
    std::string ligne;
    std::multimap< std::string, std::vector<std::string> > confDeux;
    while (std::getline(ifs, ligne))
    {
        size_t j = 0;
        size_t p = ligne.size();
        if (p == 1 && ligne.find('}') != std::string::npos)
        {
            _def.push_back(confDeux);
            confDeux.clear();
            continue;
        }
        for (std::string::iterator at = ligne.begin(); at != ligne.end() ; at++)
        {
            if (!(isspace(*at)))
            {
                std::string ligne2;
                size_t s = ligne.find(" ", j);
                if (s != std::string::npos)
                    ligne2 = ligne.substr(j, (s - j));
                while ((s < ligne.size()) && isspace(ligne[s]))
                    s++;
                if (s == std::string::npos)
                    break;
                std::string ligne3 = ligne.substr(s);
                size_t f = ligne3.find(";");
                if (f != std::string::npos)
                    ligne3 = ligne3.substr(0, f);
                size_t end = ligne3.find('{');
                std::vector<std::string> v3;
                if ((end != std::string::npos) && (j != 0))
                {
                    ligne3 = ligne3.substr(0, end);
                    v3.push_back(ligne3);
                    while (std::getline(ifs, ligne))
                    {
                        size_t c = ligne.find('}');
                        if (c != std::string::npos)
                            break;
                        v3.push_back(ConfParsing::parsConfDeux(ligne));
                    }
                }
                else
                    v3.push_back(ligne3);
                confDeux.insert(std::make_pair(ligne2, v3));
                break;
            }
            j++;
        }
    }
    ifs.close();

    std::cout << Green << "Configuration file : " << _path << " parsed" << Reset_Color << std::endl;
}

std::string ConfParsing::parsConfDeux(std::string ligne)
{
    size_t j = 0;
    for (std::string::iterator at = ligne.begin(); at != ligne.end() ; at++)
    {
        if (!(isspace(*at)))
        {
            std::string ligne2;
            size_t s = ligne.find(" ", j);
            if (s != std::string::npos)
                ligne2 = ligne.substr(j, (s - j));
            while ((s < ligne.size()) && isspace(ligne[s]))
                s++;
            if (s == std::string::npos)
                break;
            std::string ligne3 = ligne.substr(s);
            size_t f = ligne3.find(";");
            if (f != std::string::npos)
                ligne3 = ligne3.substr(0, f);
            ligne2 = ligne2 + ';' + ligne3;
            return (ligne2);
            break;
        }
        j++;
    }
    return (ligne);
}

const std::list< std::multimap< std::string, std::vector<std::string> > > &ConfParsing::getConf(void) const
{
    return (_def);
}

std::list<std::map<std::string, std::string> > ConfParsing::getLocation(const std::multimap< std::string, std::vector<std::string> >&configMap)
{
    std::list<std::map<std::string, std::string> > result2;

/*    if (conf.getConf().empty()) 
    {
        throw std::runtime_error("Erreur: La liste de configurations est vide.");
    }*/
//     conf.getConf().front();

    // Vérifier si la clé "location" existe
    std::pair< std::multimap<std::string, std::vector<std::string> >::const_iterator, 
            std::multimap< std::string, std::vector<std::string> >::const_iterator> range = configMap.equal_range("location");
    if (range.first == range.second) 
    {
        throw std::runtime_error("Erreur: Aucune clé 'location' trouvée dans la configuration.");
    }

    // Afficher toutes les valeurs associées à "location"
    for (std::multimap< std::string, std::vector<std::string> >::const_iterator it = range.first; it != range.second; it++)
    {
        std::string                             temp;
        std::map<std::string, std::string>      zap;
        for (std::vector<std::string>::const_iterator vit = it->second.begin(); vit != it->second.end(); vit++)
        {
            temp = *vit;
            size_t  t = temp.find(';');
            if (t == std::string::npos)
                zap["location"] = temp;
            else
            {
                std::string ttl = temp.substr(0, t);
                std::string jh = temp.substr(t + 1);
                zap[ttl] = jh;
            }
        }
        result2.push_back(zap);
        zap.clear();
    }
    return (result2);
}

std::ostream &operator<<(std::ostream &o, const ConfParsing &src)
{
    const std::list< std::multimap< std::string, std::vector<std::string> > > &def = src.getConf(); //stock la reference

    std::list< std::multimap<std::string, std::vector<std::string> > >::const_iterator it = def.begin();
    while(it != def.end())
    {
        std::multimap< std::string, std::vector<std::string> >::const_iterator vi = it->begin();
        while (vi != it->end())
        {
            o << vi->first << "  ->  ";
            for (std::vector<std::string>::const_iterator it = vi->second.begin(); it != vi->second.end(); it++)
                o << *it << "  =>  ";
            o << std::endl;
            vi++;
        }
        o << std::endl << " list " << std::endl << std::endl;
        it++;
    }
    return (o);
}