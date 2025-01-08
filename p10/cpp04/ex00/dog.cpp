/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:41:01 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/02 17:41:03 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog(void) : Animal("Dog")
{
    std::cout << "default constructor dog" << std::endl;
    return;
}

Dog::Dog(std::string const & type) : Animal(type)
{
    std::cout << "assignement constructor dog" << std::endl;
    return;
}

Dog::Dog(Dog const & src) : Animal("cat")
{
    std::cout << "copy constructor dog" << std::endl;
    *this = src;
    return;
}

Dog::~Dog(void)
{
    std::cout << "destructor dog" << std::endl;
    return;
}

Dog &   Dog::operator=(Dog const & rhs)
{
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        this->_type = rhs._type;
    }
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "OUAF OUAFFFFFF" << std::endl;
    return;
}
