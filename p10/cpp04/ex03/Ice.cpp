/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:15:16 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/05 15:15:17 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
    std::cout << "default constructor Ice call" << std::endl;
    return;
}

Ice::Ice(Ice const & src) : AMateria(src._type)
{
    std::cout << "copy constructor Ice call" << std::endl;
    *this = src;
    return;
}

Ice::~Ice(void)
{
    std::cout << "destructor Ice call" << std::endl;
    return;
}

Ice &   Ice::operator=(Ice const & rhs)
{
    if (this != &rhs)
        AMateria::operator=(rhs);
        this->_type = rhs._type;
    return (*this);
}

AMateria*   Ice::clone() const
{
    return ( new Ice(*this) );
}

void        Ice::use(ICharacter& target)
{
    std::cout << "* shoots an Ice bolt at " << target.getName() << " *" << std::endl;
    return;
}
