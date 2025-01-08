/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:31:00 by gschwart          #+#    #+#             */
/*   Updated: 2024/10/11 18:31:01 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

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

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal(src)
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
    {
        WrongAnimal::operator=(rhs);
        this->_type = rhs._type;
    }
    return (*this);
}

void    WrongCat::makeSound(void) const
{
    std::cout << "ccccc aaaaa oooooo ooooooooo oo oo" << std::endl;
    return;
}
