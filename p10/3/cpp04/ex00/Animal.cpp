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

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : _type("Animal, type ?? unknown")
{
    std::cout << "default constructor animal" << std::endl;
}

Animal::Animal(std::string const & type) : _type(type)
{
    std::cout << "assignement constructor animal" << std::endl;
}

Animal::Animal(Animal const & src)
{
    std::cout << "copy constructor animal" << std::endl;
    *this = src;
    return;
}

Animal::~Animal()
{
    std::cout << "destructor animal" << std::endl;
    return;
}

std::string const & Animal::getType(void) const
{
    return (this->_type);
}

Animal &    Animal::operator=(Animal const & rhs)
{
    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}

void    Animal::makeSound(void) const
{
    std::cout << "houbaaaaaaa" << std::endl;
    return;
}
