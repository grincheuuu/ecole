/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:03:07 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/15 15:03:09 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
    return;
}

Weapon::Weapon(std::string  type) : _type(type)
{
    return;
}

Weapon::~Weapon()
{
    return;
}

std::string const   Weapon::getType(void) const
{
    return (_type);
}

void    Weapon::setType(std::string const type)
{
    _type = type;
    return;
}