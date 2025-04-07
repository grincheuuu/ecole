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

void    PmergeMe::ft_jacobstahl(unsigned int n)
{
    std::vector<unsigned int>   temp(1, 0);
    if (n ==0 || n == 1)
        return;
    temp.push_back(1);
    int     i = 2;
    unsigned int     nb = 1;
    while (nb < n)
    {
        nb = temp[i - 2] * 2 + temp[i - 1];
        temp.push_back(nb);
        i++;
    }
/*    for (std::vector<unsigned int>::iterator it = temp.begin(); it != temp.end(); it++)
    {
        std::cout << *it << " "; 
    }
    std::cout << std::endl;*/
    this->_jacob = temp;
    return;
}

int     PmergeMe::ft_jacobstahl_compare(unsigned int n)
{
    for (std::vector<unsigned int>::iterator it = _jacob.begin(); it != _jacob.end(); it++)
    {
        if (*it == n)
        {
            std::cout << n << " gagner " << std::endl;
            return 0;
        }
        if (*it > n)
        {
            std::cout << "bla " << n << " bla" << std::endl;
            return 1;
        }
//        std::cout << *it << " comp "; 
    }
    return (1);
}

void    PmergeMe::ft_binary_insertion(std::vector<unsigned int> & vi, unsigned int i)
{
    std::cout << "i " << i << std::endl;
    if (vi.empty())
    {
        vi.push_back(i);
        return;
    }
    if (i < vi.front())
    {
        vi.insert(vi.begin(), i);
        return;
    }
    else if (i > vi.back())
    {
        vi.push_back(i);
        return;
    }
    size_t      end = vi.size();
    size_t      begin = 0;
    while(begin < end)
    {
        size_t  mid = (end + begin) / 2;
        std::cout << " vimid " << vi[mid] << " mid " << mid << " top " << end << " begin " << begin << std::endl;
        if(i == vi[mid])
        {
            vi.insert(vi.begin() + mid, i);
            std::cout << "youpi" << std::endl;
            return;
        }
        else if (i < vi[mid])
        {
            if (mid > 0 && (i < vi[mid] && i > vi[mid - 1]))
            {
                vi.insert(vi.begin() + mid - 1, i);
                std::cout << "youhou" << std::endl;
                return;
            }
            end = mid;
        }
        else
        {
            if (mid < end && (i > vi[mid] && i < vi[mid + 1]))
            {
                vi.insert(vi.begin() + mid + 1, i);
                std::cout << "boubou" << std::endl;
                return;
            }
            begin = mid;
        }
    }
    vi.insert(vi.begin() + begin, i);
    return;
}

void    PmergeMe::ft_last(std::vector<unsigned int> & vi, std::vector<unsigned int> & tab)
{
    std::vector<unsigned int>   temp;
    unsigned int                maax = 0;
    std::vector<unsigned int>::iterator oo;
    oo = max_element(tab.begin(), tab.end());
    maax = *oo;
//    std::cout << "jacobstahl " << maax << std::endl;
    ft_jacobstahl(maax);
    int i = 0;
    for (std::vector<unsigned int>::iterator it = tab.begin(); it != tab.end(); it++)
    {
        if (ft_jacobstahl_compare(*it) == 0)
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
//            std::cout << "i " << i << " ";
        }
        else
            ++it;
        i++;
    }
//    std::cout << std::endl;
    unsigned int    b = 1;
    PmergeMe::ft_recursive_un(vi, b); // min
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
    for (std::vector<unsigned int>::iterator it = vi.begin(); it != vi.end(); it++)
    {
        std::cout << *it << " "; 
    }
    std::cout << " fin " << std::endl;
    ft_sort_suite(vi);
    std::cout << std::endl;
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