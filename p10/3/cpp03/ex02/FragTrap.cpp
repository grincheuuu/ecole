/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:07:42 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/02 15:07:55 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
    std::cout << "Fragggggg  default contructor called" << std::endl;
    return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    this->_MaxHitPoints = 100;
    std::cout << "Fraggggggg  assignement contructor called" << std::endl;
    return;
}

FragTrap::FragTrap(FragTrap const & src)
{
    std::cout << "Fraggggggg  copy contructor called" << std::endl;
    *this = src;
    return;
}

FragTrap::~FragTrap()
{
    std::cout << "Fraggggggg  destructor called" << std::endl;
}

FragTrap&  FragTrap::operator=(FragTrap const & rhs)
{
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
        this->_hitPoints = rhs.getHitPoints();
        this->_energyPoints = rhs.getEnergyPoints();
        this->_attackDamage = rhs.getAttackDamage();
        this->_MaxHitPoints = rhs.getMaxHitPoints();        
    }
    return (*this);
}

void    FragTrap::highFivesguys(void)
{
    if (getHitPoints() == 0)
    {
        std::cout << "FragTrap can't be high five, Fragtrap " << getName() << " has already been destroyed" << std::endl;
        return;
    }
    std::cout << "FragTrap take a high five to Fragtrap " << getName() << std::endl;
    return;
}
