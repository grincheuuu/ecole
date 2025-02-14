/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:06:15 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/14 17:06:17 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define    MUTANTSTACK_HPP

# include <iostream>
# include <iterator>
# include <stack>

template < typename T >
class MutantStack : public std::stack<T>
{
    public:
        MutantStack(void) {};
        MutantStack(MutantStack<T> const & a) : std::stack<T>(a) {};
        ~MutantStack(void) {};

        MutantStack<T> &        operator=(MutantStack<T> const & rhs)
        {
            if (this != &rhs)
            {
                std::stack<T>::operator=(rhs);
            }
            return (*this);
        }

    // defini les iterateurs en utilisant ::std::stack::c (c est le container sous-jacent)
    typedef typename std::stack<T>::container_type::iterator        iterator;
    typedef typename std::stack<T>::container_type::const_iterator  const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator    reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator  const_reverse_iterator;

    iterator    begin() //definition de fonction avec l'iterateur
    {
        return (this->c.begin());
    }
    iterator    end()
    {
        return (this->c.end());
    }

    const_iterator    begin() const
    {
        return (this->c.begin());
    }
    const_iterator    end() const
    {
        return (this->c.end());
    }

    reverse_iterator    rbegin()
    {
        return (this->c.rbegin());
    }
    reverse_iterator    rend()
    {
        return (this->c.rend());
    }

    const_reverse_iterator    rbegin() const
    {
        return (this->c.rbegin());
    }
    const_reverse_iterator    rend() const
    {
        return (this->c.rend());
    }
};

#endif
