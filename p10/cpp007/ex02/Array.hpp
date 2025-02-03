/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:24:34 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/03 17:24:36 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <stdexcept>

template < typename T >
class Array
{
    public:
        Array(void)
        {
            _A = new tab[];
            return;
        }
        Array(unsigned int i)
        {
            _A = new tab[i];
            return;
        }
        Array(Array const & src)
        {
            return;
        }
        ~Array(void);

        Array &     opreator=(Array const & rhs);

        size_t      size(void) const;

        class ArrayOutOfBounds : public std::exception
        {
            public:
                virtual const char * what () const throw ();
        };

    private:
        unsigned int     _i;
        T *              _A;
};