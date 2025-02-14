/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:44:07 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/07 16:44:09 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>

int main()
{
    Span    sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span    spp = Span(1);

    try
    {
        std::cout << spp.shortestSpan() << std::endl;
        std::cout << spp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Span    sp2 = Span(100);

    try
    {
        sp2.addNumber(5);
        sp2.addNumber(9);
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Span    sp3 = Span(10);
    std::vector<int>    tab (9, 100);
    try 
    {
        sp3.addNumber(9);
        sp3.AddNumberRange(tab.begin(), tab.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << sp3;

    unsigned int     i = 90;
    Span            sp4 = Span(i);
    unsigned int    j = 0;
    try
    {
        while (j < (i))
        {
            sp4.addNumber(0 + j);
            j++;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << sp4;

    return 0;
}