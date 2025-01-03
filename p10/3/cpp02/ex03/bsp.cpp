/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:09:29 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/24 18:09:31 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool    bsp(Point const a, Point const b, Point const c, Point const m)
{
    Fixed i = 0;
    Fixed j = 0;
    Fixed k = 0;

    i = (((a.get_x() - m.get_x()) * (b.get_y() - m.get_y())) - ((a.get_y() - m.get_y()) * (b.get_x() - m.get_x())));
    j = (b.get_x() - m.get_x()) * (c.get_y() - m.get_y()) - (b.get_y() - m.get_y()) * (c.get_x() - m.get_x());
    k = (c.get_x() - m.get_x()) * (a.get_y() - m.get_y()) - (c.get_y() - m.get_y()) * (a.get_x() - m.get_x());

    std::cout << "bst i : " << i << " j : " << j << " k : " << k << std::endl; 
    if ((i >= 0 && j >= 0 && k >= 0) || (i <= 0 && j <= 0 && k <= 0))
        return (true);
    else
        return (false);
}
