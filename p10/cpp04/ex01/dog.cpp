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

Dog::Dog(void) : Animal("Dog"), _Brain(new Brain())
{
    std::cout << "default constructor dog" << std::endl;
    return;
}

Dog::Dog(std::string const & type) : Animal(type)
{
    std::cout << "assignement constructor dog" << std::endl;
    return;
}

Dog::Dog(Dog const & src) : Animal(src)
{
    std::cout << "copy constructor dog" << std::endl;
    this->_Brain = new Brain(*src._Brain);
    *this = src;
    return;
}

Dog::~Dog(void)
{
    delete _Brain;
    std::cout << "destructor dog" << std::endl;
    return;
}

Dog &   Dog::operator=(Dog const & rhs)
{
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        delete rhs._Brain;
        this->_Brain = new Brain(*rhs._Brain);
        this->_type = rhs._type;
    }
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "OUAF OUAFFFFFF" << std::endl;
    return;
}
