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
        
        float   toFloat( void ) const;
        int     toInt( void ) const;

        int     getRawBits( void ) const;
        void    setRawBits( int const raw);

    private:
        int _raw;
        static int const    _ifixe = 8;
};

std::ostream&   operator<<(std::ostream & o, Fixed const & rhs);

#endif

 