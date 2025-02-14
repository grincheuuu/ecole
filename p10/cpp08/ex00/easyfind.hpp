/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:44:50 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/07 16:44:52 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <algorithm>
# include <vector>


template< typename T >
typename T::const_iterator     easyfind(T & a, int b)
{
    typename T::iterator    it; //iterator de type template ici int
    it = std::find(a.begin(), a.end(), b);
    if (it == a.end())
        throw std::runtime_error("number not found");
    return (it);
}
