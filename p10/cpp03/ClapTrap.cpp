/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:07:26 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/02 15:07:30 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap( void ) : _name("default"), _hitPoints(0), _energyPoints(0), _attackDamage(0)
{
//    std::cout << "ClapTrap " << " hit points restant : " << _hitPoints << " energy points restants : " << _energyPoints << std::endl;
    std::cout << "default contructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10)
{
    std::cout << "assignement contructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
    std::cout << "copy contructor called" << std::endl;
    *this = src;
    return;
}

ClapTrap::~ClapTrap()
{
    std::cout << "destructor called" << std::endl;
}

std::string     ClapTrap::getName(void) const
{
    return this->_name;
}

unsigned int    ClapTrap::getHitPoints(void) const
{
    return (this->_hitPoints);
}

unsigned int    ClapTrap::getEnergyPoints(void) const
{
    return (this->_energyPoints);
}

unsigned int    ClapTrap::getAttackDamage(void) const
{
    return (this->_attackDamage);
}

ClapTrap &      ClapTrap::operator=(ClapTrap const & rhs)
{
    if (this != &rhs)
        this->_name = rhs.getName();
        this->_hitPoints = rhs.getHitPoints();
        this->_energyPoints = rhs.getEnergyPoints();
        this->_attackDamage = rhs.getAttackDamage();
    return (*this);
}

void    ClapTrap::attack(const std::string & target)
{
//    std::cout << "ClapTrap " << _name << " attack " << " hit points restant : " << _hitPoints << " energy points restants : " << _energyPoints << std::endl;
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " has been destroyed, he can't attack" << std::endl;
        return;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy points, he can't attack" << std::endl;
        return;
    }
    if (target == this->_name)
    {
        std::cout << "ClapTrap " << _name << " can't attack him self, choose another ClapTrap" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attack " << target;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= amount)
    {
        std::cout << ", causing " << _hitPoints << " points of damage!" << std::endl;
        std::cout << "ClapTrap " << _name << " has been destroyed" << std::endl;
        this->_hitPoints = 0;
        return;
    }
    else
    {
        std::cout << ", causing " << amount << " points of damage!" << std::endl;
        this->_hitPoints -= amount;
        return;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " has no more energy points, he can't repair" << std::endl;
        return;
    }
    if (_hitPoints == 10)
    {
        std::cout << "ClapTrap " << _name;
        std::cout << ", " << _hitPoints << " is already at maximum" << std::endl;
        std::cout << " 0, " << " points has been repaired!" << std::endl;
        this->_energyPoints -= 1;
        return;
    }
    else
    {
        if (amount + _hitPoints <= 10)
        {
            std::cout << "ClapTrap " << _name;
            std::cout << ", " << amount << " points has been repaired!";
            this->_hitPoints += amount;
            std::cout << ", his life is " << _hitPoints << std::endl;
            this->_energyPoints -= 1;
            return;
        }
        else
        {
            std::cout << "ClapTrap " << _name;
            std::cout << ", " <<  - _hitPoints << " has been repaired";
            this->_hitPoints += amount;
            std::cout << ", his life his : " << _hitPoints << std::endl;
            this->_energyPoints -= 1;
            return;
        }
    }
}