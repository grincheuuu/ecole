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
# include <stdlib.h>
# include <time.h>

template < typename T >
class Array
{
    public:
        Array(void) : _i(0)
        {
            _A = new T[0];
            return;
        }
        Array(unsigned int i) : _i(i)
        {
            _A = new T[i];
            return;
        }
        Array(Array const & src) : _i(src._i), _A(new T[src._i])
        {
            for (unsigned int i = 0; i < _i; i++)
                _A[i] = src._A[i];
            *this = src;
            return;
        }
        ~Array(void)
        {
            delete [] _A;
            _A = 0;
        }

        Array < T > &     operator=(Array < T > const & rhs)
        {
            if (this != &rhs)
            {
                this->_i = rhs._i;
                delete [] _A;
                _A = new T[rhs._i];
                for (unsigned int i = 0; i < rhs._i; i++)
                    _A[i] = rhs._A[i];
            }
            return *this;
        }

        std::size_t      size(void) const
        {
            return (_i);
        }

        class ArrayOutOfBounds : public std::exception
        {
            public:
                virtual const char * what () const throw ()
                {
                    return "index is out of bounds Exception";
                }
        };

        T &     operator[](const unsigned int location)
        {
            if (location < 0 || location >= _i)
                throw ArrayOutOfBounds();
            else
                return _A[location];
        }

//        T &     operator[](const int location) throw (const char *); 

    private:
        unsigned int              _i;
        T *                       _A;
};

/*
template <class T> T &     Array<T>::operator[](const int location) throw (const char *)
 {
    if (location < 0 || location >= _i)
        throw "invalid array access";
    else
        return _A[location];
 }
 */