/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:34:08 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/17 19:34:10 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
    return;
}

Harl::~Harl()
{
    return;
}

void    Harl::_debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "Debug messages contain contextual information" << std::endl;
    std::cout << "I really do!" << std::endl;
}

void    Harl::_info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "These messages contain extensive information" << std::endl;
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::_warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::_error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    int i = 1;
    
    std::string  tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    while (i <= 4)
    {
        if (level ==  tab[i - 1])
            break;
        i++;
    }
    switch(i)
    {
        case 1:
            _debug();
            _info();
            _warning();
            _error();
            break;
        case 2:
           _info();
           _warning();
           _error();                     
            break;
        case 3:
          _warning();
          _error();          
            break;
        case 4:
           _error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }

    return;
}
