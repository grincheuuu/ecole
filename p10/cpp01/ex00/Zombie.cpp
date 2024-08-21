/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:03:07 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/15 15:03:09 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string  name) : _name(name)
{
    return;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << _name << " has been destroyed, youpiiiiii" << std::endl;
    return;
}

void    Zombie::annonce()
{
    std::cout << _name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
    return;
}