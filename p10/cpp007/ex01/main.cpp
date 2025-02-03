/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:15:42 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/03 15:15:43 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int     main(void)
{
    int     tab[3] = {5, 2, 3};
    char    cta[5] = {'a', 'b', 'c', 'd', 'e'};
    float   ft[] = {1.1, 4.9};

    size_t  l = sizeof(cta);
    size_t  li = sizeof(tab) / sizeof(int);
    size_t  lf = sizeof(ft) / sizeof(float);
//    std::cout << l << " " << li << " " << lf << " " << tab << std::endl;
    ::iter(tab, li, f<int>);
    ::iter(cta, l, f<char>);
    ::iter(ft, lf, f<float>);
    return (0);
}
