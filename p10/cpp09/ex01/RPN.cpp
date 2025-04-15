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

void    RPN::ft_calcul(std::queue<int> nb, std::queue<char> chr)
{
    double     stock = static_cast<double>(nb.front());
    nb.pop();
    double     n = static_cast<double>(nb.front());
    char    ct = chr.front();
    while(!nb.empty())
    {
//        std::cout << "stock " << stock << " n " << n << " ct " << ct << std::endl;
        if (!chr.empty())
        {
            switch (ct)
            {
                case '*':
                {
                    stock *= n;
                    break;
                }
                case '/':
                {
                    stock /= n;
                    break;
                }
                case '-':
                {
                    stock -= n;
                    break;
                }
                case '+':
                {
                    stock += n;
                    break;
                }
                default:
                    break;
            }
            chr.pop();
            ct = chr.front();
        }
        nb.pop();
        n = static_cast<double>(nb.front());
    }
    std::cout << stock << std::endl;
}

int     RPN::ft_pars(std::string ligne)
{
    std::queue<int>       nb;
    std::queue<char>      operateur;
    int                     i = 1;
    for(std::string::iterator it = ligne.begin(); it != ligne.end(); it++)
    {
        if (i % 2 != 0)
        {
            if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
            {
                operateur.push(*it);
            }
            else if (*it >= '0' && *it <= '9')
            {
                nb.push(static_cast<int>(*it) - '0');
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
