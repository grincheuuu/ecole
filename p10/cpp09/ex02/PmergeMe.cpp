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

/*
void     PmergeMe::ft_recursive_un(std::vector<unsigned int> & vi, unsigned int b)
{
    std::vector<unsigned int>::iterator     it = vi.begin();
    unsigned int     t = 0;
    unsigned int     v = 0;
    unsigned int     n = *it;
    while (it != vi.end())
    {
        unsigned int    z = 0;
        std::vector<unsigned int>::iterator w = it;
        
        while (z < ((b * 4) / 2))
        {
            t = 0;
            while (w != vi.end() && t < z)
            {
                w++;
                t++;
                std::cout << " t " << t << std::endl;
                n = *w;
            }
            std::vector<unsigned int>::iterator e = w;
            v = t;
//            std::cout << "b " << b << " n " << n << " v " << v << " i " << i << std::endl;
            while (w != vi.end() && t < (b * 4) / 2)
            {
                w++;
                t++;
//                std::cout << " t " << t;
            }
            while (w != vi.end() && t < (b * 4) && n < *w)
            {
//                std::cout << " w " << *w << " n " << n << "   ";
                w++;
                if (w == vi.end())
                    return;
                t++;
            }
//            std::cout << " t " << t << " v " << v << " t - 1 " << (t - 1) << "vi t-1 " << vi[t - 1] << " vi v " << vi[v] << std::endl << std::endl;
            if (w != vi.end() && (v != (t)) && (std::max(*w, n) == n))
            {
//                std::cout << " swap " << *w << " " << vi[t] << " n " << n << " " << vi[v] << std::endl << std::endl;
                unsigned int    tt = *w;
                if (w != vi.end() && std::max(*it, n) == n)
                {
                    w = vi.erase(w);
                    (void)e;                 
                    vi.insert(vi.begin(), tt);
                }
            }
            z++;
        }
        it = w;
    }
    std::cout << "b * 4 " << (b * 4) << " vi size " << vi.size() << std::endl;
    if ((b * 4) >= vi.size())
        return;
    b++;
    ft_recursive_un(vi, b);
    return;
}*/

void    PmergeMe::ft_merge(std::vector<unsigned int> & vi, std::vector<unsigned int> & left, std::vector<unsigned int> & right)
{
    size_t      i = 0;
    size_t      j = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] > right[j])
        {
            vi[i + j] = right[j];
            j++;
        }
        else
        {
            vi[i + j] = left[i];
            i++;
        }
    }
    while (i < left.size())
    {
        vi[i + j] = left[i];
        i++;
    }
    while (j < right.size())
    {
        vi[i + j] = right[j];
        j++;
    }
}

void     PmergeMe::ft_recursive_un(std::vector<unsigned int> & vi, unsigned int b)
{
    if (vi.size() <= 1)
        return;
    size_t          mid = vi.size() / 2;
    std::vector<unsigned int>   left(vi.begin(), vi.begin() + mid);
    std::vector<unsigned int>   right(vi.begin() + mid, vi.end());


    ft_recursive_un(left, b);
    ft_recursive_un(right, b);

    ft_merge(vi, left, right);
}

int     PmergeMe::ft_jacobstahl(int n)
{
    if (n ==0 || n == 1)
        return (0);
    std::vector<unsigned int>   temp(1, 0);
    temp.push_back(1);
    int     i = 2;
    int     nb = 1;
    while (n > nb)
    {
        nb = temp[i - 2] * 2 + temp[i - 1];
        if (n == nb)
            return (0);
        temp.push_back(nb);
        i++;
    }
    return (1);
}

void    PmergeMe::ft_binary_insertion(std::vector<unsigned int> & vi, unsigned int i)
{
    size_t      mid = vi.size() / 2;
    while (mid > 2 && vi[mid] != i)
    {
        if (i > vi[mid])
        {
            mid += mid / 2;
            std::cout << " + " << mid;
        }
        else
        {
            mid -= mid / 2;
            std::cout << " - " << mid;
        }
    }
    vi.insert(vi.begin() + mid, i);
    std::cout << " mid " << mid << " vi " << vi[mid] << " i " << i << std::endl;
    return;
}

void    PmergeMe::ft_last(std::vector<unsigned int> & vi, std::vector<unsigned int> & tab)
{
    std::vector<unsigned int>   temp;
    int i = 0;
    for (std::vector<unsigned int>::iterator it = tab.begin(); it != tab.end(); it++)
    {
        if (ft_jacobstahl(i) == 0)
        {
            ft_binary_insertion(vi, *it);
        }
        else
            temp.push_back(*it);
        i++;
    }
    for (std::vector<unsigned int>::iterator it2 = temp.begin(); it2 != temp.end(); it2++)
    {
        ft_binary_insertion(vi, *it2);
    }
}

void    PmergeMe::ft_sort_suite(std::vector<unsigned int> & vi)
{
    if (vi.size() <= 1)
        return;
    
    std::vector<unsigned int>   tab;
    int     i = 0;

    for (std::vector<unsigned int>::iterator it = vi.begin(); it != vi.end();)
    {
        if (i % 2 != 0)
        {
            tab.push_back(*it);
            it = vi.erase(it);
        }
        else
            ++it;
        i++;
    }
    unsigned int    b = 1;
    PmergeMe::ft_recursive_un(vi, b);
    PmergeMe::ft_last(vi, tab);
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
/*    for (std::vector<unsigned int>::iterator it = vi.begin(); it != vi.end(); it++)
    {
        std::cout << *it << " "; 
    }
    std::cout << std::endl;*/
    ft_sort_suite(vi);
    for (std::vector<unsigned int>::iterator it = vi.begin(); it != vi.end(); it++)
    {
        std::cout << *it << " "; 
    }
    std::cout << std::endl;
}

std::ostream &      operator<<(std::ostream & o, PmergeMe const & rhs)
{
    (void)rhs;
/*    for (std::vector<unsigned int>::iterator it = getVi.begin(); it != getVi.end(); it++)
    {

    }*/
   return o;
}