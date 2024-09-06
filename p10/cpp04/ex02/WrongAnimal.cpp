/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:41:55 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/02 17:41:57 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal, type alienn??")
{
    std::cout << "default constructor WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(std::string const & type) : _type(type)
{
    std::cout << "assignement constructor WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
    std::cout << "copy constructor WrongAnimal" << std::endl;
    *this = src;
    return;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "destructor WrongAnimal" << std::endl;
    return;
}

std::string const & WrongAnimal::getType(void) const
{
    return (this->_type);
}

WrongAnimal &    WrongAnimal::operator=(WrongAnimal const & rhs)
{
    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "aaaaaaannnnn!!!!!!!!!!!!!!" << std::endl;
    return;
}

WrongCat::WrongCat(void) : WrongAnimal("Wrongcat")
{
    std::cout << "default constructor Wrongcat" << std::endl;
    return;
}

WrongCat::WrongCat(std::string const & type) : WrongAnimal(type)
{
    std::cout << "assignement constructor Wrongcat" << std::endl;
    return;
}

WrongCat::WrongCat(WrongCat const & src)
{
    std::cout << "copy constructor Wrongcat" << std::endl;
    *this = src;
    return;
}

WrongCat::~WrongCat(void)
{
    std::cout << "destructor Wrongcat" << std::endl;
    return;
}

WrongCat &    WrongCat::operator=(WrongCat const & rhs)
{
    if (this != &rhs)
        WrongAnimal::operator=(rhs);
        this->_type = rhs._type;
    return (*this);
}

void    WrongCat::makeSound(void) const
{
    std::cout << "ccccc aaaaa oooooo ooooooooo oo oo" << std::endl;
    return;
}
