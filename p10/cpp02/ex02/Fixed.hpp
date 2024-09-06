/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:11:29 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/20 20:11:30 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
    public:
        Fixed(void);
        Fixed(int const raw);
        Fixed(float const raw);
        Fixed(Fixed const & src);
        ~Fixed(void);

        Fixed & operator=(Fixed const & rhs);

        Fixed   operator+(Fixed const & rhs) const;
        Fixed   operator-(Fixed const & rhs) const;
        Fixed   operator*(Fixed const & rhs) const;
        Fixed   operator/(Fixed const & rhs) const;
        
        bool   operator<(Fixed const & rhs) const;
        bool   operator>(Fixed const & rhs) const;
        bool   operator<=(Fixed const & rhs) const;
        bool   operator>=(Fixed const & rhs) const;
        bool   operator==(Fixed const & rhs) const;
        bool   operator!=(Fixed const & rhs) const;

        Fixed &  operator++(); //prefix
        Fixed & operator--(); //prefix

        Fixed  operator++(int n); //postfix
        Fixed  operator--(int n); //postfix
        
        float   toFloat( void ) const;
        int     toInt( void ) const;

        int     getRawBits( void ) const;
        void    setRawBits( int const raw);

        static Fixed &      min(Fixed & lhs, Fixed & rhs);
        static Fixed const &   min(Fixed const & lhs, Fixed const & rhs);
        static Fixed &      max(Fixed & lhs, Fixed & rhs);
        static Fixed const &    max(Fixed const & lhs, Fixed const & rhs);

    private:
        int _raw;
        static int const    _ifixe = 8;
};

std::ostream&   operator<<(std::ostream & o, Fixed const & rhs);

#endif

 