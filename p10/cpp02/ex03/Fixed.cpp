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
    return;   
}

Fixed::Fixed( int const raw ) : _raw(raw << _ifixe)
{
    return;
}

Fixed::Fixed( float const raw ) : _raw(roundf(raw * (1 << _ifixe)))
{
    return;
}

Fixed::Fixed(Fixed const & src)
{
    *this = src;
    return;
}

Fixed::~Fixed()
{
    return;
}

Fixed& Fixed::operator=(Fixed const & rhs)
{
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

Fixed   Fixed::operator+(Fixed const & rhs) const
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed   Fixed::operator-(Fixed const & rhs) const
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed   Fixed::operator*(Fixed const & rhs) const
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed   Fixed::operator/(Fixed const & rhs) const
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed &   Fixed::operator++()
{
    this->_raw++;
    return (*this);
}

Fixed &  Fixed::operator--()
{
    this->_raw--;
    return (*this);
}

Fixed   Fixed::operator++(int n)
{
    Fixed   temp = *this; // copie l objet actuel
    ++*this;              // incremente l objet actuel
    return (temp);        // renvoie la copie
}

Fixed   Fixed::operator--(int n)
{
    Fixed   temp = *this;
    --*this;
    return (temp);
}

bool   Fixed::operator<(Fixed const & rhs) const
{
    if (this->_raw < rhs.getRawBits())
        return (1);
    return (0);
}

bool   Fixed::operator>(Fixed const & rhs) const
{
    if (this->_raw > rhs.getRawBits())
        return (1);
    return (0);
}

bool   Fixed::operator<=(Fixed const & rhs) const
{
    if (this->_raw <= rhs.getRawBits())
        return (1);
    return (0);
}

bool   Fixed::operator>=(Fixed const & rhs) const
{
    if (this->_raw >= rhs.getRawBits())
        return (1);
    return (0);
}

bool   Fixed::operator==(Fixed const & rhs) const
{
    if (this->_raw == rhs.getRawBits())
        return (1);
    return (0);
}

bool   Fixed::operator!=(Fixed const & rhs) const
{
    if (this->_raw != rhs.getRawBits())
        return (1);
    return (0);
}

Fixed &      Fixed::min(Fixed & lhs, Fixed & rhs)
{
    if (lhs <= rhs)
        return (lhs);
    return (rhs);
}

Fixed const &  Fixed::min(Fixed const & lhs, Fixed const & rhs)
{
    if (lhs <= rhs)
        return (lhs);
    return (rhs);
}

Fixed &      Fixed::max(Fixed & lhs, Fixed & rhs)
{
    if (lhs >= rhs)
        return (lhs);
    return (rhs);
}

Fixed const &   Fixed::max(Fixed const & lhs, Fixed const & rhs)
{
    if (lhs >= rhs)
        return (lhs);
    return (rhs);
}