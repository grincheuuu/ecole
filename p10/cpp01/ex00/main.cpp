/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:02:21 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/15 15:02:29 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie  *newZombie( std::string name );
void    randomChump( std::string name);

int main(void)
{
    Zombie  *Zombiepointed = newZombie("heap");

    delete Zombiepointed;
    randomChump("stack");
    return (0);
}

