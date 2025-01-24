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

void                ScalarConverter::convert(std::string type)
{

    if (type.empty() || type[0] == NULL)
        return;
    if (isalpha(type[0]))
    {
        char a = type[0];
        if (isprint(a))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << a << std::endl;

        int  b = static_cast<int>(a);
        float   c = static_cast<float>(a);
        double  d = static_cast<double>(a);
        std::cout << "int: " << c << std::endl;
        std::cout << "float: " << c << std::endl;
        std::cout << "double: " << c << std::endl;

    }
    else if (isalnum(type[0]))
    {

    }


    char a = static_cast<char>(type);
    int  b = static_cast<int>(type);
    float   c = static_cast<float>(type);
    double  d = static_cast<double>(type);
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << c << std::endl;
    std::cout << "float: " << c << std::endl;
    std::cout << "double: " << c << std::endl;
}

ScalarConverter &   ScalarConverter::operator=(ScalarConverter const & rhs)
{
    if (this != &rhs)
        *this = rhs;
    return *this;
}
