/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:08:16 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/02 15:08:19 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap    j1("arthur");
    ClapTrap    j2("orlondo");
    ScavTrap    a1("david");
    ScavTrap   a2("superman");

/*    j1.attack(j2.getName());
    j2.takeDamage(5);
    j2.beRepaired(1);*/
    a1.attack(a2.getName());
    a2.takeDamage(a1.getAttackDamage());
    a1.guardGate();
    a2.beRepaired(1);
    a1.attack(a2.getName());
    a2.takeDamage(a1.getAttackDamage());
    a2.beRepaired(1);
    a1.attack(a2.getName());
    a2.takeDamage(a1.getAttackDamage());
    a2.beRepaired(1);
    a1.attack(a2.getName());
    a2.takeDamage(a1.getAttackDamage());
    a2.guardGate();
    a2.beRepaired(1);

    return 0;
}
