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
#include "FragTrap.hpp"

int main()
{
    ScavTrap    a1("david");
    ScavTrap    a2("superman");
    FragTrap    l1("Dell");
    FragTrap    l2("Pluto");

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
    std::cout << std::endl;
    l1.attack(l2.getName());
    l2.takeDamage(l1.getAttackDamage());
    l2.beRepaired(1);
    l1.highFivesguys();
    l1.attack(l2.getName());
    l2.takeDamage(l1.getAttackDamage());
    l2.beRepaired(1);
    l1.highFivesguys();
    l1.attack(l2.getName());
    l2.takeDamage(l1.getAttackDamage());
    l2.beRepaired(1);
    l1.highFivesguys();
    l1.attack(l2.getName());
    l2.takeDamage(l1.getAttackDamage());
    l2.beRepaired(1);
    l1.highFivesguys();
    l1.attack(l2.getName());
    l2.takeDamage(l1.getAttackDamage());
    l2.beRepaired(1);
    l1.highFivesguys();
    l1.attack(l2.getName());
    l2.takeDamage(l1.getAttackDamage());
    l2.beRepaired(1);
    l1.highFivesguys();
    l1.attack(l2.getName());
    l2.takeDamage(l1.getAttackDamage());
    l2.beRepaired(1);
    l1.highFivesguys();

    return 0;
}
