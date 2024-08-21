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
    std::cout << "DEBUG level:" << std::endl;
    std::cout << "Debug messages contain contextual information" << std::endl;
}

void    Harl::_info(void)
{
    std::cout << "INFO level: " << std::endl;
    std::cout << "These messages contain extensive information" << std::endl;
}

void    Harl::_warning(void)
{
    std::cout << "WARNING level: " << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
}

void    Harl::_error(void)
{
    std::cout << "ERROR level: " << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    int i = 0;
    
//    void        (Harl::*fonction[])(void);
//    fonction    {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

    std::string  tab[4] = {"debug", "info", "warning", "error"};
    void        (Harl::*tabp[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

    while (i < 4)
    {
        if (level ==  tab[i])
        {
            (this->*tabp[i])();
            return;
        }
        i++;
    }
    return;
}
