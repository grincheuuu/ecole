/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:07:35 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/02 15:07:37 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CLASS_HPP
# define CLAPTRAP_CLASS_HPP

# include <iostream>
# include <string>

class ClapTrap
{
public:

    ClapTrap( void );
    ClapTrap(std::string name);
    ClapTrap(ClapTrap const & src);
    ~ClapTrap(void);

    ClapTrap &      operator=(ClapTrap const & rhs);

    void    attack(const std::string & target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

    std::string     getName(void) const;
    unsigned int    getHitPoints(void) const;
    unsigned int    getEnergyPoints(void) const;
    unsigned int    getAttackDamage(void) const;

    unsigned int    getMaxHitPoints(void) const;

protected:
    unsigned int _MaxHitPoints;
    unsigned int _MaxEnergyPoints;

    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
};

#endif
