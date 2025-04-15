/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:57:38 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/14 18:57:40 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "BitcoinExchange.cpp"

int     main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "this program take one file on parameter" << std::endl;
        return (1); 
    }
    std::ifstream   ifs(argv[1]);
    if (!ifs)
    {
        std::cout << "open file in lecture error" << std::endl;
        return (1);
    }
    std::multimap<std::string, double>   tab;
    std::map<std::string, double>        csv;
    std::string     ligne;
    std::getline(ifs, ligne);
    while (std::getline(ifs, ligne))
    {
        if (::ft_pars_ligne(ligne) == 1)
            tab.insert(std::make_pair("erreur", ::ft_date_deux(ligne)));
        else
        {
            std::string         s3 = ligne.substr(12);
            std::string         s2 = ligne.substr(0, 10);
            tab.insert(std::make_pair(s2, atof(s3.c_str())));
        }
    }
    csv = ::ft_csv("data.csv");
    ::ft_compare(tab, csv);
    ifs.close();
    return (0);
}
