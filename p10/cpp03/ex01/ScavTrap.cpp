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

void    ScavTrap::attack(const std::string & target)
{
    if (_hitPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " has been destroyed, he can't attack" << std::endl;
        return;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " has no energy points, he can't attack" << std::endl;
        return;
    }
    if (target == this->_name)
    {
        std::cout << "ScavTrap " << _name << " can't attack him self, choose another ScavTrap " << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name << " attack " << target;
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
