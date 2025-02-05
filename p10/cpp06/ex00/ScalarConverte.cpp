/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverte.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:27:45 by gschwart          #+#    #+#             */
/*   Updated: 2025/01/24 16:27:46 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverte.hpp"
#include <string.h>

ScalarConverter::ScalarConverter()
{
    return;
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
    *this = src;
    return;
}

ScalarConverter::~ScalarConverter(void)
{
    return;
}

void    ft_int(std::string const type) // danger int max int min
{
    long int   n = atol(type.c_str());
    if (n < INT_MIN || n > INT_MAX)
    {
        std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: Non displayable" << std::endl;
    }
    else
    {
        int n = atoi(type.c_str());
        if (n > 31 && n < 127)
        {
            char a = static_cast<char>(n);;
            std::cout << "char: " << a << std::endl;
        }
        else
        {
            std::cout << "char: Non displayable" << std::endl;
        }
        std::cout << "int: " << n << std::endl;
    }

    float   c = static_cast<float>(n);
    std::cout << "float: " << std::fixed << std::setprecision(1) << c << "f" << std::endl;
    double  d = static_cast<double>(n);
    std::cout << "double: "<< std::fixed << std::setprecision(1) << d << std::endl;

}

void    ft_float(std::string const type) // danger int max int min
{
    char *  pend;
    float    c = strtof(type.c_str(), &pend);
//    float c = atof(type.c_str());

    if (c > 31 && c < 127)
    {
        char a = static_cast<char>(c);;
        std::cout << "char: " << a << std::endl;
    }
    else
        std::cout << "char: Non displayable" << std::endl;

    double  d = static_cast<double>(c);

    if (d < -2147483648 || d > 2147483647)
        std::cout << "int: Non displayable" << std::endl;
    else
    {
        int  b = static_cast<int>(c);
        std::cout << "int: " << b << std::endl;
    }
    std::cout << "float: " << std::fixed << std::setprecision(1) << c << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;

}

void    ft_double(std::string const type) // danger int max int min
{
    double d = atof(type.c_str());

    if (d > 31 && d < 127)
    {
        char a = static_cast<char>(d);;
        std::cout << "char: " << a << std::endl;
    }
    else
        std::cout << "char: Non displayable" << std::endl;


    float   c = static_cast<float>(d);
    if (d < -2147483648 || d > 2147483647)
        std::cout << "int: Non displayable" << std::endl;
    else
    {
        int  b = static_cast<int>(d);
        std::cout << "int: " << b << std::endl;
    }
    std::cout << "float: " << std::fixed << std::setprecision(1) << c << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;

}

void                ScalarConverter::convert(std::string const type)
{
    std::string        tab[] = {"-inff", "+inff", "-inf", "+inf", "nanf", "nan"};
    int i = 0;

    if (type.empty())
        return;
    while (i < 6)
    {
        if (tab[i] == type)
        {
            if (i < 4)
            {
                    std::cout << "char: impossible" << std::endl;
                    std::cout << "int: impossible" << std::endl;
                    std::cout << "float: " << tab[i] << std::endl;
                    std::cout << "double: " << tab[i] << std::endl;
                    return;
            }
            else
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: nanf" << std::endl;
                std::cout << "double: nan" << std::endl;
                return;
            }
        }
        i++;
    }
    if (isascii(type[0]))
    {
        i = 0;
        while (type[i] != '\0')
        {
            if (!isspace(type[i]))
                break;
            i++;
        }
        if (((type[i] == '+' || type[i] == '-' || type[i] == '.') && isdigit(type[i + 1])) || isdigit(type[i])) // chiffre
        {
            if (type[i] == '+' || type[i] == '-')
                i++;
            while (isdigit(type[i]))
                i++;
            if (type[i] == '\0')
            {
                ft_int(type); // attention au char
                return;
            }
            else if (type[i] == '.')
            {
                i++;
                while (isdigit(type[i]))
                    i++;
                if (type[i] == 'f' && type[i + 1] == '\0')
                {
                    ft_float(type);
                    return;
                }
                else if (type[i] == '\0')
                {
                    ft_double(type);
                    return;
                }
            }
        }
        else if (!isdigit(type[i])) // 1er  caracter pas un chiffre
        {
            if (type[i + 1] == '\0') //char
            {
                char a = type[0];
                int  b = static_cast<int>(a);
                float   c = static_cast<float>(a);
                double  d = static_cast<double>(a);
                std::cout << "char: " << a << std::endl;
                std::cout << "int: " << b << std::endl;
                std::cout << "float: " << c << std::endl;
                std::cout << "double: " << d << std::endl;
            }
        }
    }
}

ScalarConverter &   ScalarConverter::operator=(ScalarConverter const & rhs)
{
    if (this != &rhs)
        *this = rhs;
    return *this;
}