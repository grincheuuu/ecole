/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:15:30 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/05 15:15:32 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
    std::cout << "default constructor Cure call" << std::endl;
    return;
}

Cure::Cure(Cure const & src) : AMateria(src._type)
{
    std::cout << "copy constructor Cure call" << std::endl;
    *this = src;
    return;
}

Cure::~Cure(void)
{
    std::cout << "destructor Cure call" << std::endl;
    return;
}

Cure &   Cure::operator=(Cure const & rhs)
{
    if (this != &rhs)
        AMateria::operator=(rhs);
        this->_type = rhs._type;
    return (*this);
}

AMateria*   Cure::clone(void) const
{
    AMateria*   Cure_clone = new Cure(*this);
    return (Cure_clone );
}

void        Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "�s wounds *" << std::endl;
    return;
}
