/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:40:29 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/02 17:40:31 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void) : _type("Animal, type ?? unknown")
{
    std::cout << "default constructor animal" << std::endl;
}

AAnimal::AAnimal(std::string const & type) : _type(type)
{
    std::cout << "assignement constructor animal" << std::endl;
}

AAnimal::AAnimal(AAnimal const & src)
{
    std::cout << "copy constructor aanimal" << std::endl;
    *this = src;
    return;
}

AAnimal::~AAnimal()
{
    std::cout << "destructor animal" << std::endl;
    return;
}

std::string const & AAnimal::getType(void) const
{
    return (this->_type);
}

AAnimal &    AAnimal::operator=(AAnimal const & rhs)
{
    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}
