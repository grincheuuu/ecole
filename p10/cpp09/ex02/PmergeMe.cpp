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
    if (this != &src)
    {
        _jacob = src._jacob;
        _jacobDeux = src._jacobDeux;
    }
    return *this;
}

void            PmergeMe::ft_get_time(clock_t t)
{
    t = clock() - t;
    double  useconds;
    useconds = (double)t / CLOCKS_PER_SEC * 1000000;
    std::cout << "time " << useconds << " microseconds" << std::endl;
    return;
}

void    PmergeMe::ft_sort(char **argv, int argc)
{
    std::vector<unsigned int>   ti;
    std::deque<unsigned int>    de;
    for (int i = 1; i < argc; i++)
    {
        if (ft_unsigned_int(argv[i]) == 1)
        {
            ti.clear();
            de.clear();
            throw PmergeMe::echecException();
        }
        ti.push_back(strtoul(argv[i], NULL, 0));
        de.push_back(strtoul(argv[i], NULL, 0));
    }
    ft_sort_un(ti);
    ft_sort_deux(de);
    ti.clear();
    de.clear();
    return;
}

int     PmergeMe::ft_unsigned_int(std::string str)
{
    std::stringstream   string(str);
    std::string         reste;
    unsigned int            nb;

    if(*str.begin() == '-')
        return (1);
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

void     PmergeMe::ft_recursive_un(std::vector<unsigned int> & vi)
{
    if (vi.size() <= 1)
        return;
    size_t          mid = vi.size() / 2;
    std::vector<unsigned int>   left(vi.begin(), vi.begin() + mid);
    std::vector<unsigned int>   right(vi.begin() + mid, vi.end());


    ft_recursive_un(left);
    ft_recursive_un(right);

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
    this->_jacob = temp;
    return;
}

int     PmergeMe::ft_jacobstahl_compare(unsigned int n)
{
    for (std::vector<unsigned int>::iterator it = _jacob.begin(); it != _jacob.end(); it++)
    {
        if (*it == n)
            return 0;
        if (*it > n)
            return 1;
    }
    return (1);
}

void    PmergeMe::ft_binary_insertion(std::vector<unsigned int> & vi, unsigned int i)
{
    if (vi.empty())
    {
        vi.push_back(i);
        return;
    }
    size_t      end = vi.size() - 1;
    size_t      begin = 0;
    while(begin <= end)
    {
        size_t  mid = (end + begin) / 2;
        if(i == vi[mid])
        {
            vi.insert(vi.begin() + mid, i);
            return;
        }
        else if (i < vi[mid])
        {
            if (i <= vi[begin])
            {
                vi.insert(vi.begin() + begin, i);
                return;
            }
            else
                begin++;
            end = mid;
        }
        else
        {
            if (i >= vi[end])
            {
                vi.insert(vi.begin() + end + 1, i);
                return;
            }
            else
                end--;
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
    ft_jacobstahl(maax);
    int i = 0;
    for (std::vector<unsigned int>::iterator it = tab.begin(); it != tab.end(); it++)
    {
        if (ft_jacobstahl_compare(*it) == 0)
            ft_binary_insertion(vi, *it);
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
    PmergeMe::ft_recursive_un(vi); // min
    PmergeMe::ft_last(vi, tab);
}

void    PmergeMe::ft_sort_un(std::vector<unsigned int> & vi)
{
    clock_t t;
    t = clock();
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
    ft_print(vi, "Before: ");
    ft_sort_suite(vi);
    ft_print(vi, "After:  ");
    int     nb = vi.size();
    std::cout << "Time to process a range of " << nb << " elements with std::vector : ";
    ft_get_time(t);
//    ft_verifie_sort(vi, "vector");
}

void    PmergeMe::ft_sort_deux(std::deque<unsigned int> & de)
{
    clock_t t;
    t = clock();
    std::deque<unsigned int>::iterator     it = de.begin();
    int     i = 0;
    unsigned int     n;
    while (it != de.end())
    {
        if (i % 2 == 0)
        {
            n = *it;
            if (++it == de.end())
                break;
            i++;
            if (std::max(*it, n) == n)
                std::swap(de[i - 1], de[i]);
        }
        i++;
        it++;
    }
//    ft_print(de, "Before: ");
    ft_sortyop(de);
//    ft_print(de, "After:  ");
    int     nb = de.size();
    std::cout << "Time to process a range of " << nb << " elements with std::deque :  ";
    ft_get_time(t);
//    ft_verifie_sort(de, "deque");
}


void    PmergeMe::ft_sortyop(std::deque<unsigned int> & de)
{
    if (de.size() <= 1)
        return;
    
    std::deque<unsigned int>   tab;
    int     i = 0;

    for (std::deque<unsigned int>::iterator it = de.begin(); it != de.end();)
    {
        if (i % 2 != 0)
        {
            tab.push_back(*it);
            it = de.erase(it);
        }
        else
            ++it;
        i++;
    }
    unsigned int    b = 1;
    PmergeMe::ft_recursive(de, b); // min
    PmergeMe::ft_lastDeux(de, tab);
}

void     PmergeMe::ft_recursive(std::deque<unsigned int> & de, unsigned int b)
{
    if (de.size() <= 1)
        return;
    size_t          mid = de.size() / 2;
    std::deque<unsigned int>   left(de.begin(), de.begin() + mid);
    std::deque<unsigned int>   right(de.begin() + mid, de.end());


    ft_recursive(left, b);
    ft_recursive(right, b);

    ft_mergeDeux(de, left, right);
}

void    PmergeMe::ft_mergeDeux(std::deque<unsigned int> & de, std::deque<unsigned int> & left, std::deque<unsigned int> & right)
{
    size_t      i = 0;
    size_t      j = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] > right[j])
        {
            de[i + j] = right[j];
            j++;
        }
        else
        {
            de[i + j] = left[i];
            i++;
        }
    }
    while (i < left.size())
    {
        de[i + j] = left[i];
        i++;
    }
    while (j < right.size())
    {
        de[i + j] = right[j];
        j++;
    }
}

void    PmergeMe::ft_lastDeux(std::deque<unsigned int> & de, std::deque<unsigned int> & tab)
{
    std::deque<unsigned int>   temp;
    unsigned int                maax = 0;
    std::deque<unsigned int>::iterator oo;
    oo = max_element(tab.begin(), tab.end());
    maax = *oo;
    ft_jacobstahlDeux(maax);
    int i = 0;
    for (std::deque<unsigned int>::iterator it = tab.begin(); it != tab.end(); it++)
    {
        if (ft_jacobstahl_compareDeux(*it) == 0)
            ft_binary_insertionDeux(de, *it);
        else
            temp.push_back(*it);
        i++;
    }
    for (std::deque<unsigned int>::iterator it2 = temp.begin(); it2 != temp.end(); it2++)
    {
        ft_binary_insertionDeux(de, *it2);
    }
}

void    PmergeMe::ft_jacobstahlDeux(unsigned int n)
{
    std::deque<unsigned int>   temp(1, 0);
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
    this->_jacobDeux = temp;
    return;
}

int     PmergeMe::ft_jacobstahl_compareDeux(unsigned int n)
{
    for (std::deque<unsigned int>::iterator it = _jacobDeux.begin(); it != _jacobDeux.end(); it++)
    {
        if (*it == n)
            return 0;
        if (*it > n)
            return 1;
    }
    return (1);
}

void    PmergeMe::ft_binary_insertionDeux(std::deque<unsigned int> & de, unsigned int i)
{
    if (de.empty())
    {
        de.push_back(i);
        return;
    }
    size_t      end = de.size() - 1;
    size_t      begin = 0;
    while(begin <= end)
    {
        size_t  mid = (end + begin) / 2;
        if(i == de[mid])
        {
            de.insert(de.begin() + mid, i);
            return;
        }
        else if (i < de[mid])
        {
            if (i <= de[begin])
            {
                de.insert(de.begin() + begin, i);
                return;
            }
            else
                begin++;
            end = mid;
        }
        else
        {
            if (i >= de[end])
            {
                de.insert(de.begin() + end + 1, i);
                return;
            }
            else
                end--;
            begin = mid;
        }
    }
    de.insert(de.begin() + begin, i);
    return;
}

const char *    PmergeMe::echecException::what () const throw ()
{
    return ("Bad input number!!");
}