/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:15:47 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/05 15:15:49 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("??")
{
//    std::cout << BLUE "default constructor AMateria call" RESET << std::endl;
    return;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
//    std::cout << BLUE "affectation constructor AMateria call" RESET << std::endl;
    return;
}

AMateria::AMateria(AMateria const & src) : _type(src._type)
{
//    std::cout << BLUE "copy constructor AMateria call" RESET << std::endl;
    *this = src;
    return;
}

AMateria::~AMateria()
{
//    std::cout << YELLO "destructor AMateria call" RESET << std::endl;
    return;
}

AMateria &  AMateria::operator=(AMateria const & rhs)
{
    if (this != &rhs)
        this->_type = rhs._type;
    return (*this);
}

std::string const &  AMateria::getType() const
{
    return (this->_type);
}

void    AMateria::use(ICharacter& target)
{
    std::cout << GREEN "AMateria target is : " << target.getName() << RESET << std::endl;
    return;
}
