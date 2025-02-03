/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:29:35 by gschwart          #+#    #+#             */
/*   Updated: 2025/01/30 18:29:37 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template< typename T >
void     swap(T & a, T & b)
{
    T   temp;

    temp = a;
    a = b;
    b = temp;
    return;
}

template< typename T >
T const &    min(T const & a, T const & b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

template< typename T >
T const &    max(T const & a, T const & b)
{
    if (a > b)
        return (a);
    else
        return (b);
}
