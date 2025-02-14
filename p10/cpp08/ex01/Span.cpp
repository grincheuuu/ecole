/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:44:37 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/07 16:44:38 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <climits>

Span::Span(void) : _n(0)
{
    return;
}

Span::Span(unsigned int n) : _n(n)
{
    return;
}

Span::Span(Span const & src) : _n(src._n), _tab(src._tab)
{
    return;
}

Span &      Span::operator=(Span const & src)
{
    if (this->_n != src._n)
    {
        this->_n = src._n;
        _tab.clear();
        _tab = src._tab;
    }
/*    std::vector<int>::iterator  it;
    it = std::search(_tab.begin(), _tab.end(), src._tab.begin(), src._tab.end());
    if (it != _tab.end())
    {
        _tab.clear();
        for (std::vector<int>::iterator it2 = src._tab.begin(); it2 != src._tab.end(); it2++)
        {
            _tab.push_back(*it2);
        }
    }*/
    return *this;
}

void        Span::addNumber(int i)
{
    if (_tab.size() >= _n)
    {
        throw Span::BadNumberException();
        return;
    }
    _tab.push_back(i);
    return;
}

const char *    Span::BadNumberException::what () const throw ()
{
    return ("Exception N number are already stock");
}

unsigned int      Span::shortestSpan(void) const
{
    std::vector<int>    t2 = _tab;
    std::sort (t2.begin(), t2.end());

    int     nb = INT_MAX;
    int     temp = 0;
    int     nbt = 0;
    int     i = 0;
    if (_tab.size() <= 1)
    {
        throw Span::LengthNullException();
        return (0);
    }
    for (std::vector<int>::iterator it = t2.begin(); it != t2.end(); it++)
    {
        if (i != 0)
        {
            temp = *it - nbt;
            if (temp < nb)
                nb = temp;
        }
        nbt = *it;
        i++;
    }
    return (nb);
}

unsigned int      Span::longestSpan(void) const
{
    if (_tab.size() <= 1)
    {
        throw Span::LengthNullException();
        return (0);
    } // const iterator car la fonction est const
    std::vector<int>::const_iterator  a = std::min_element(_tab.begin(), _tab.end());
    std::vector<int>::const_iterator  b = std::max_element(_tab.begin(), _tab.end());
    return (static_cast<unsigned int>(*b - *a));
}

const char *    Span::LengthNullException::what () const throw ()
{
    return ("Exception distance between number, can't be found");
}

std::vector<int> const &       Span::getTab(void) const
{
    return (this->_tab);
}

std::ostream &      operator<<(std::ostream & o, Span const & rhs)
{
    for (std::vector<int>::const_iterator it = rhs.getTab().begin(); it != rhs.getTab().end(); it++)
    {
        o << " " << *it << " ";
    }
    o << std::endl;
    return o;
}