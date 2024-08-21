/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:38:45 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/15 15:38:46 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name)
{
    int i = 0;
    if (N <= 0)
        return (NULL);
    Zombie  *zhorde = new Zombie[N];

    while (i < N)
    {
        zhorde[i].set_name(name);
        i++;
    }
    return (zhorde);
}

