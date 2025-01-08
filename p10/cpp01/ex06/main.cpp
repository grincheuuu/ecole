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

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl    instance;

    if (argc != 2)
    {
        std::cout << "the programme need the level of Harl systeme" << std::endl;
        return (1);
    }
    std::string arv = std::string(argv[1]);
    instance.complain(arv);
    return 0;
}
