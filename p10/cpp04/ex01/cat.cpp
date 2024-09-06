/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:40:47 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/02 17:40:49 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat(void) : Animal("cat"), _Brain(new Brain())
{
    std::cout << "default constructor cat" << std::endl;
    return;
}

Cat::Cat(std::string const & type) : Animal(type)
{
    std::cout << "assignement constructor cat" << std::endl;
    return;
}

Cat::Cat(Cat const & src) : Animal("cat")
{
    std::cout << "copy constructor cat" << std::endl;
    this->_Brain = new Brain(*src._Brain);
    *this = src;
    return;
}

Cat::~Cat(void)
{
    delete _Brain;
    std::cout << "destructor cat" << std::endl;
    return;
}

Cat &    Cat::operator=(Cat const & rhs)
{
    if (this != &rhs)
        Animal::operator=(rhs);
        delete this->_Brain;
        this->_Brain = new Brain(*rhs._Brain);
        this->_type = rhs._type;
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << "Miaouuuuuuuuuuuuuuu" << std::endl;
    return;
}