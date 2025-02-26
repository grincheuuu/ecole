/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:20:42 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/20 18:20:45 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2 || argv[1] == NULL)
    {
        std::cout << "This program requires one argument: a mathematical expression in RPN" << std::endl;
        return (1);
    }
    if (RPN::ft_pars(argv[1]) == 1)
    {
        std::cout << "Error : argument : this program need one argument which is an mathematical expression in RPN" << std::endl;
        return (1);       
    }
    return (0);
}
