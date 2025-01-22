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
    FragTrap    l1("Dell");
    FragTrap    l2("Pluto");

    l1.attack(l2.getName());
    l2.takeDamage(l1.getAttackDamage());
    l2.beRepaired(1);
    l1.highFivesGuys();
    l1.attack(l2.getName());
    l2.takeDamage(l1.getAttackDamage());
    l2.beRepaired(1);
    l1.highFivesGuys();
    l1.attack(l2.getName());
    l2.takeDamage(l1.getAttackDamage());
    l2.beRepaired(1);
    l1.highFivesGuys();
    l1.attack(l2.getName());
    l2.takeDamage(l1.getAttackDamage());
    l2.beRepaired(1);
    l1.highFivesGuys();
    l1.attack(l2.getName());
    l2.takeDamage(l1.getAttackDamage());
    l2.beRepaired(1);
    l1.highFivesGuys();
    l1.attack(l2.getName());
    l2.takeDamage(l1.getAttackDamage());
    l2.beRepaired(1);
    l1.highFivesGuys();
    l1.attack(l2.getName());
    l2.takeDamage(l1.getAttackDamage());
    l2.beRepaired(1);
    l1.highFivesGuys();

    return 0;
}
