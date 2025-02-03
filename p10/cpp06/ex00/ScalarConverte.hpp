/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverte.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:27:34 by gschwart          #+#    #+#             */
/*   Updated: 2025/01/24 16:27:36 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string.h>
#include <cctype>
#include <cstdlib>
#include <stdlib.h>
#include <climits>
#include <cfloat>
#include <iomanip>

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(ScalarConverter const & src);
        ~ScalarConverter(void);

        ScalarConverter &   operator=(ScalarConverter const & rhs);

    public:
        static void                convert(std::string const type);
};