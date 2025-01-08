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

Fixed::Fixed( int const raw ) : _raw(raw << _ifixe)
{
    std::cout << "Int constructor called" << std::endl;
    return;
}

Fixed::Fixed( float const raw ) : _raw(roundf(raw * (1 << _ifixe)))
{
    std::cout << "Float constructor called" << std::endl;
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

Fixed& Fixed::operator=(Fixed const & rhs)
{
    std::cout << "assignement operator call" << std::endl;
    if (this != &rhs)
        this->_raw = rhs.getRawBits();
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    return (this->_raw);
}

void    Fixed::setRawBits(int const raw)
{
    this->_raw = raw;
    return;
}

std::ostream&   operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return (o);
}

float   Fixed::toFloat( void ) const
{
    float   raw;

    raw = (float)this->_raw / (1 << _ifixe);
    return (raw);
}

int Fixed::toInt( void ) const
{
    return (this->_raw >> _ifixe);
}