/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:15:48 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/03 15:15:49 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


template < typename T >
void    f(T & p)
{
    std::cout << p << std::endl;
    return;
}


template < typename T>
void   iter(T * p, size_t const l, void (*f)(T &))
{
    size_t i = 0;

    while (p != NULL && i < l)
    {
        f(p[i]);
        i++;
    }
    std::cout << std::endl;
    return;
}