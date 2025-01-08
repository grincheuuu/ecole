/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:32:42 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/15 16:32:45 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"

HumanB::HumanB(std::string const name) : _weaponT(NULL),  _name(name)
{
    return;
}

HumanB::~HumanB()
{
    return;
}

void   HumanB::setWeapon(Weapon &weapon)
{
    _weaponT = &weapon;
    return;
}

void    HumanB::attack() const
{
    std::cout << this->_name << " attacks with their " << _weaponT->getType() << std::endl;
    return;
}