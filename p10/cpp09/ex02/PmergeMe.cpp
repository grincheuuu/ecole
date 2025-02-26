/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:40:29 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/26 15:40:30 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
    return;
}

PmergeMe::PmergeMe(PmergeMe const & rhs)
{
    *this = rhs;
    return;
}

PmergeMe::~PmergeMe(void)
{
    return;
}

PmergeMe &      PmergeMe::operator=(PmergeMe const & src)
{
    (void)src;
    return *this;
}

int     PmergeMe::ft_unsigned_int(std::string str)
{
    std::stringstream   string(str);
    std::string         reste;
    unsigned int            nb;

    if(string >> nb)
    {
        if(string >> reste)
            return (1);
        return (0);
    }
    return (1);
}

void     PmergeMe::ft_recursive_un(std::vector<unsigned int> & vi, unsigned int b)
{
    std::vector<unsigned int>::iterator     it = vi.begin();
    unsigned int     i;
    int     t = 0;
    int     v = 0;
    unsigned int     n;
    b++;
    while (it != vi.end())
    {
        unsigned int    z = 0;
        std::vector<unsigned int>::iterator w = it;
        while (z < ((b * 4) / 2))
        {
            for (unsigned int f = 0; f < z; f++)
                w++;
            n = *w;
            v = t;
            i = 0;
            for (unsigned int j = z; j < ((b * 4) / 2); j++)
                w++;
            while (w != vi.end() && i < (b * 4) && n > *w)
            {
                w++;
                if (w == vi.end())
                    return;
                i++;
                t++;
            }
            if (std::max(*w, n) == n)
                std::swap(vi[t - 1], vi[v]);
            z++;
        }
        it = w;
    }
    if ((b * 4) > vi.size())
        return;
    ft_recursive_un(vi, b);  
    return;
}

void    PmergeMe::ft_sort_suite(std::vector<unsigned int> & vi)
{
/*    std::vector<unsigned int>   deux;
    int     i = 0;

    for (std::vector<unsigned int>::iterator it = vi.begin(); it != vi.end();)
    {
        if (i % 2 == 0)
        {
            deux.push_back(*it);
            it = vi.erase(it);
        }
        else
            ++it;
        i++;       
    }*/
    unsigned int    b = 1;
    PmergeMe::ft_recursive_un(vi, b);
}

void    PmergeMe::ft_sort_un(std::vector<unsigned int> & vi)
{
    std::vector<unsigned int>::iterator     it = vi.begin();
    int     i = 0;
    unsigned int     n;
    while (it != vi.end())
    {
        if (i % 2 == 0)
        {
            n = *it;
            if (++it == vi.end())
                break;
            i++;
            if (std::max(*it, n) == n)
                std::swap(vi[i - 1], vi[i]);
        }
        i++;
        it++;
    }
    for (std::vector<unsigned int>::iterator it = vi.begin(); it != vi.end(); it++)
    {
        std::cout << *it << " "; 
    }
    std::cout << std::endl;
    ft_sort_suite(vi);
}

std::ostream &      operator<<(std::ostream & o, PmergeMe const & rhs)
{
    (void)rhs;
/*    for (std::vector<unsigned int>::iterator it = getVi.begin(); it != getVi.end(); it++)
    {

    }*/
   return o;
}