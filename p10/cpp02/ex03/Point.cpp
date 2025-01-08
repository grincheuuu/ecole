/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:08:45 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/24 18:08:47 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
    return;
}

Point::Point(Fixed const a, Fixed const b) : _x(a), _y(b)
{
    std::cout << "contructor Point x, y : " << _x << " " << _y << std::endl;
    return;
}

Point::Point(Point const & src) : _x(src._x), _y(src._y)
{
    *this = src;
    return;
}

Point::~Point(void)
{
    std::cout << "destructor Point x, y : " << _x << " " << _y << std::endl;
    return;
}

Point & Point::operator=(Point const &rhs)
{
    if (this->_x != rhs.get_x())
        std::cerr << "operator de comparaison error" << std::endl;
    return (*this);
}

Fixed   Point::get_x(void) const
{
    return (this->_x);
}

Fixed Point::get_y(void) const
{
    return (this->_y);
}
