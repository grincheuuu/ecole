/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:31:51 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/15 16:31:54 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string const name, Weapon &weaponT) : _name(name), _weaponT(weaponT)
{
    return;
}

HumanA::~HumanA()
{
    return;
}

void    HumanA::attack() const
{
    std::cout << this->_name << " attacks with their " << _weaponT.getType() << std::endl;
    return;
}
