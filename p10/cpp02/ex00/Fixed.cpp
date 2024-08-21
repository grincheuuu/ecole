/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:11:12 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/20 20:11:14 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _raw(0)
{
    std::cout << "Default constructor called" << std::endl;
    return;   
}

Fixed::Fixed( int const raw ) : _raw(raw)
{
    std::cout << "contructeur int call" << std::endl;
    return;
}

Fixed::Fixed( float const f) : 
{
    std::cout << "contructeur float call" << std::endl;
    return;
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy contructor called" << std::endl;
    *this = src;
    return;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    return;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
    std::cout << "assignement contructor call" << std::endl;
    if (this != &rhs)
        this->_raw = rhs.getRawBits();
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_raw);
}

void    Fixed::setRawBits(int const raw)
{
    this->_raw = raw;
    return;
}

float   toFloat( void ) const
{

}

Integer toInt(void) const
{

}