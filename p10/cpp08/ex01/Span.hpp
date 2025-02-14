/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:44:21 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/07 16:44:22 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <stdexcept>
# include <string>

class Span
{
    public:
        Span(void);
        Span(unsigned int n);
        Span(Span const & src);

        Span &      operator=(Span const & rhs);

        void        addNumber(int i);

        class BadNumberException : public std::exception
        {
            public:
                virtual const char * what () const throw ();
        };

        unsigned int      shortestSpan(void) const;
        unsigned int      longestSpan(void) const;

        class LengthNullException : public std::exception
        {
            public:
                virtual const char * what () const throw ();
        };

        template < typename Iterateur >
        void    AddNumberRange(Iterateur a, Iterateur b)
        {
            int i = std::distance(a, b);
//            Iterateur   it = a;
/*          int i = 0;
            while (it != b)
            {
                i++;
                it++;
            }*/
            size_t  nb = _tab.size();
            std::cout << "i " << i << " nb " << nb << " _n " << _n << std::endl;
            if (i + nb > _n)
                throw Span::BadNumberException();
            _tab.insert(_tab.end(), a, b); //debute l'insertion a end de _tab
            return;
        }

        std::vector<int> const &       getTab(void) const;

    private:
        unsigned int        _n;
        std::vector<int>    _tab;
};

std::ostream &      operator<<(std::ostream & o, Span const & rhs);

#endif
