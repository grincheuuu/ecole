/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:57:46 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/14 18:57:49 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitCoinExchange::BitCoinExchange(void)
{
    return;
}

BitCoinExchange::BitCoinExchange(BitCoinExchange const & src)
{
    *this = src;
    return;
}

BitCoinExchange::~BitCoinExchange(void)
{
    return;
}

BitCoinExchange &       BitCoinExchange::operator=(BitCoinExchange const & rhs)
{
    (void)rhs;
    return (*this);
}

int     isInt(std::string ligne)
{
    int     nb;
    std::stringstream   string(ligne);
    std::string         reste;

    if (string >> nb)
    {
        if (string >> reste)
            return (1);
        return (0);
    }
    return (1);
}

int     isFloat(std::string ligne)
{
    float     n;
    std::stringstream   string(ligne);
    std::string         reste;

    if (string >> n)
    {
        if (string >> reste)
        {
//            std::cout << " " << reste << " ";
            return (1);
        }
//        std::cout << " " << n << " ";
        return (0);
    }
    return (1);    
}

int     ft_date(std::string ligne)
{
    std::string     s1 = ligne.substr(5, 2);
    int             month = atoi(s1.c_str());
    std::string     s2 = ligne.substr(8, 2);
    int             day = atoi(s2.c_str());
    std::string     s3 = ligne.substr(0, 4);
    int             year = atoi(s3.c_str());

    if ((month > 12) || (month <= 0) || (day <= 0))
        return (1);
    if (((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) && (day > 31))
        return (1);
    else if (((month == 4) || (month == 6) || (month == 9) || (month == 11)) && (day > 30))
        return (1);
    if ((month == 2) && (year % 4 != 0) && (day > 28))
        return (1);
    else if ((month == 2) && (year % 4 == 0) && (day > 29))
        return (1);
    return (0);
}

int     ft_date_deux(std::string ligne)
{
    if (ligne.size() < 10)
        return (1);
    std::string     s1 = ligne.substr(5, 2);
    int             month = atoi(s1.c_str());
    std::string     s2 = ligne.substr(8, 2);
    int             day = atoi(s2.c_str());
    std::string     s3 = ligne.substr(0, 4);
    int             year = atoi(s3.c_str());

    int     nb = year * 10000 + month * 100 + day;
    if ((month > 12) || (month <= 0) || (day <= 0))
        return (1);
    if (((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) && (day > 31))
        return (1);
    else if (((month == 4) || (month == 6) || (month == 9) || (month == 11)) && (day > 30))
        return (1);
    if ((month == 2) && (year % 4 != 0) && (day > 28))
        return (1);
    else if ((month == 2) && (year % 4 == 0) && (day > 29))
        return (1);
    return (nb);
}

int     ft_pars_ligne(std::string ligne)
{
    std::string::iterator   it = ligne.begin();
    int                     i = 0;
    std::string     s1;
    if (ligne.size() < 12)
        return (1);
    while (it != ligne.end())
    {
        if ((((i < 4) || (i > 4 && i < 7) || (i > 7 && i < 10)) && isdigit(*it) == 0) || ((i == 4 || i == 7) && *it != '-'))
        {
            s1 = ligne.substr(0, 11);
//            std::cout << "Error: bad format number => " << s1 << std::endl;
            return (1);
        }
        if ((((i == 10) || (i == 12)) && *it != ' ') || ((i == 11) && *it != '|'))
        {
            s1 = ligne.substr(0, 11);
//            std::cout << "Error: bad format => " << s1 << std::endl;
            return (1);
        }
        i++;
        it++;
    }
/*    std::string     s2 = ligne.substr(12);
    if ((isInt(s2) == 1) && (isFloat(s2) == 1))
    {
        std::cout << "Error: false number." << std::endl; // a revoir
        return (1);
    }
    long int nb = 0;
    if (isInt(s2) == 0)
        nb = strtol(s2.c_str(), NULL, 0);
    else
        nb = static_cast<long int>(atof(s2.c_str()));
    if ((nb < 0) || (nb > 1000))
    {
        std::cout << "Error: too large a number." << std::endl;
        return (1);
    }
    else if ((nb < 0))
    {
        std::cout << "Error: not a positive number." << std::endl;
        return (1);
    }
    if (ft_date(ligne) == 1)
    {
        s1 = ligne.substr(0, 10);
        std::cout << "Error: bad input" << " => " << s1 << std::endl;
        return (1);
    }*/
    return (0);
}

std::map<std::string, double>    ft_csv(std::string str)
{
    std::map<std::string, double>   tab;
    std::ifstream   ifsa(str.c_str());
    if (!ifsa)
    {
        std::cout << "open file CSV in lecture error" << std::endl;
        return tab;
    }
    std::string     ligne;
    while (std::getline(ifsa, ligne))
    {
        std::string         s3 = ligne.substr(11);
        std::string         s2 = ligne.substr(0, 10);
        tab[s2] = atof(s3.c_str());
    }
    ifsa.close();
    return (tab);
}

std::string     ft_to_string(int str)
{
    std::string     chr;
    std::stringstream   ii;

    int     day = (str) % 100;
    int     month = ((str) / 100) % 100;
    int     year = (str) / 10000;
//    std::cout << year << " " << month << " " << day << std::endl;;
    ii << year;
    ii << '-';
    ii << std::setfill('0') << std::setw(2) << month;
    ii << '-';
    ii << std::setfill('0') << std::setw(2) << day;
    ii >> chr;
    return (chr);
}

void    ft_compare(std::multimap<std::string, double> tab, std::map<std::string, double> csv)
{
    std::map<std::string, double>::iterator     it = tab.begin();
    std::map<std::string, double>::iterator     itcsv = csv.begin();
    while (it != tab.end())
    {
        if (it->first == "erreur")
        {
            if (it->second > 1)
            {
                std::string     nb = ft_to_string(static_cast<int>(it->second));
                std::cout << "Error: bad format input" << " => " << nb << std::endl;
            }
            else
                std::cout << "Error: bad format input " << std::endl;
        }
        else if ((it->second > 1000))
        {
            std::cout << "Error: too large a number." << std::endl;
        }
        else if (ft_date(it->first) == 1)
        {
            std::string     s1;
            s1 = it->first.substr(0, 10);
            std::cout << "Error: bad input" << " => " << s1 << std::endl;
        }
        else if ((it->second < 0))
        {
            std::cout << "Error: not a positive number." << std::endl;
        }
        else if (csv[it->first])
        {
            double nb = it->second * csv[it->first];
            std::cout << it->first << " => " << it->second << " = " << nb << std::endl;
        }
        else
        {
            std::string         s1 = it->first.substr(0, 4);
            std::string         s2 = it->first.substr(5, 2);
            std::string         s3 = it->first.substr(8, 2);
//            std::cout << " s1 " << atoi(s1.c_str()) << " s2 " << atoi(s2.c_str()) << " s3 " << atoi(s3.c_str()) << std::endl;
            int     nb = atoi(s1.c_str()) * 10000 + atoi(s2.c_str()) * 100 + atoi(s3.c_str());
//            std::cout << " nb " << nb << std::endl;
            while (itcsv != csv.end())
            {
                std::string         sa = itcsv->first.substr(0, 4);
                std::string         sb = itcsv->first.substr(5, 2);
                std::string         sc = itcsv->first.substr(8, 2);
                int     nbcsv = atoi(sa.c_str()) * 10000 + atoi(sb.c_str()) * 100 + atoi(sc.c_str());
//                std::cout << " nbcsv " << nbcsv << std::endl;
                if (nbcsv > nb)
                {
                    if (--itcsv == csv.begin())
                    {
                        std::cout << "Error: NO Date available in csv file" << " => " << it->first << std::endl;
                        break;
                    }
                    itcsv--;
                    double nb = it->second * itcsv->second;
                    std::cout << it->first << " => " << it->second << " = " << nb << std::endl;
                    break;
                }
                itcsv++;
            }
        }
        it++;
    }
}
