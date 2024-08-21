/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:03:31 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/15 15:03:32 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie( std::string name )
{
    Zombie  *Zombiepointed = new Zombie(name);

    Zombiepointed->annonce();
    return (Zombiepointed);
}
