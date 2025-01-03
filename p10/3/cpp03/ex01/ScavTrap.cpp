/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:08:25 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/02 15:08:27 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
    std::cout << "Scavvvv  default contructor called " << _name << std::endl;
    return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_MaxHitPoints = 100;
    std::cout << "Scavvvv  assignement contructor called " << _name << std::endl;
    return;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src)
{
    std::cout << "Scavvvvvv  copy contructor called " << _name << std::endl;
    *this = src;
    return;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Scavvvvvv  destructor called " << _name << std::endl;
}

ScavTrap&  ScavTrap::operator=(ScavTrap const & rhs)
{
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
        this->_hitPoints = rhs.getHitPoints();
        this->_energyPoints = rhs.getEnergyPoints();
        this->_attackDamage = rhs.getAttackDamage();
    }
    return (*this);
}

void    ScavTrap::guardGate()
{
    if (getHitPoints() == 0)
    {
        std::cout << "ScavTrap can't be in keeper mode, Claptrap " << getName() << " has already been destroyed" << std::endl;
        return;
    }
    std::cout << "ScavTrap is now in Gate keeper mode, Claptrap " << getName() << std::endl;
    return;
}
