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
//    std::cout << BLUE "default constructor Cure call" RESET << std::endl;
    return;
}

Cure::Cure(Cure const & src) : AMateria(src._type)
{
//    std::cout << BLUE "copy constructor Cure call" RESET << std::endl;
    *this = src;
    return;
}

Cure::~Cure(void)
{
//    std::cout << YELLO "destructor Cure call" RESET << std::endl;
    return;
}

Cure &   Cure::operator=(Cure const & rhs)
{
    if (this != &rhs)
    {
        AMateria::operator=(rhs);
        this->_type = rhs._type;
    }
    return (*this);
}

AMateria*   Cure::clone(void) const
{
    AMateria*   Cure_clone = new Cure(*this);
    return (Cure_clone );
}

void        Cure::use(ICharacter& target)
{
    std::cout << GREEN "* heals " << target.getName() << "'s wounds *" RESET << std::endl;
    return;
}
