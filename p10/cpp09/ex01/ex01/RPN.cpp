/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:21:07 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/20 18:21:08 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
    return;
}

RPN::RPN(RPN const & src)
{
    *this = src;
    return;
}

RPN::~RPN(void)
{
    return;
}

RPN &       RPN::operator=(RPN const & rhs)
{
    if (this != &rhs)
        *this = rhs;
    return (*this);
}

void    RPN::ft_calcul(std::vector<int> nb, std::vector<char> chr)
{
    std::vector<int>::iterator  it = nb.begin();
    std::vector<char>::iterator ct = chr.begin();
    int     stock = *it;
    it++;
    while(it != nb.end())
    {
        if (ct != chr.end())
        {
            switch (*ct)
            {
                case '*':
                {
                    stock *= *it;
                    break;
                }
                case '/':
                {
                    stock /= *it;
                    break;
                }
                case '-':
                {
                    stock -= *it;
                    break;
                }
                case '+':
                {
                    stock += *it;
                    break;
                }
                default:
                    break;
            }
            ct++;
        }
        it++;
    }
    std::cout << stock << std::endl;
}

int     RPN::ft_pars(std::string ligne)
{
    std::vector<int>       nb;
    std::vector<char>      operateur;
    int                     i = 1;
    for(std::string::iterator it = ligne.begin(); it != ligne.end(); it++)
    {
        if (i % 2 != 0)
        {
            if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
            {
                operateur.push_back(*it);
            }
            else if (*it >= '0' && *it <= '9')
            {
                nb.push_back(static_cast<int>(*it) - '0');
            }
            else
            {
                return (1);                
            }
        }
        i++;
    }
    if (nb.size() != (operateur.size() + 1))
    {
        return (1);                
    }
    ft_calcul(nb, operateur);
    return (0);
}
