/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:08:16 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/02 17:19:32 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap    j1("david");
    ClapTrap    j2("orlondo");


  
    if (j1.getEnergyPoints() != 0)
    {
   	j1.attack(j2.getName());
    	j2.takeDamage(5);
    }
    else
    	j1.attack(j2.getName());
    j2.beRepaired(1);
    if (j1.getEnergyPoints() != 0)
    {
   	j1.attack(j2.getName());
    	j2.takeDamage(5);
    }
    else
    	j1.attack(j2.getName());
    if (j1.getEnergyPoints() != 0)
    {
   	j1.attack(j2.getName());
    	j2.takeDamage(5);
    }
    else
    	j1.attack(j2.getName());
    j2.beRepaired(1);
    if (j1.getEnergyPoints() != 0)
    {
   	j1.attack(j2.getName());
    	j2.takeDamage(5);
    }
    else
    	j1.attack(j2.getName());
    j2.beRepaired(1);

    return 0;
}
