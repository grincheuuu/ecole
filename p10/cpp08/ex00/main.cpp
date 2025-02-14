/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:44:57 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/07 16:44:59 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main(void)
{
    std::vector<int>        tab;
    std::vector<int>        vec; 

    for (int i = 0; i < 5; i++)
        tab.push_back(i++);

    vec.push_back(2 + 3);
    vec.push_back(3 + 3);
    vec.push_back(4 + 3);

/*  t = 0;
    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        vec.push_back(t + 3);
        t++;
        std::cout << *it << " ";
    }
    std::cout << std::endl;*/

    std::vector<int>::const_iterator  it;
    try
    {
        it = easyfind(tab, 4);
        std::cout << *it << std::endl;
        it = easyfind(vec, 4);
        std::cout << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
