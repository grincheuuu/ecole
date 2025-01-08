/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:08:04 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/24 18:08:06 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>
# include <string>

class Point
{
    public:
        Point(void);
        Point(Fixed const a, Fixed const b);
        Point(Point const & src);
        ~Point(void);

        Point & operator=(Point const & rhs);

        Fixed   get_x(void) const;
        Fixed   get_y(void) const;

    private:
        Fixed const  _x;
        Fixed const  _y;
};

#endif
