/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:40:20 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/26 15:40:22 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMGERGE_ME_HPP
# define PMGERGE_ME_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <cstdlib>
# include <algorithm>
# include <vector>
# include <deque>
# include <ctime>
# include <stdexcept>

class PmergeMe
{
    public:
        PmergeMe(void);
        PmergeMe(PmergeMe const & rhs);
        ~PmergeMe(void);

        PmergeMe &      operator=(PmergeMe const & src);

        void    ft_sort(char **argv, int argc);
        
        template<typename T>
        void    ft_print(T const & array, std::string const & str)
        {
            std::cout << str;
            for (typename T::const_iterator it = array.begin(); it != array.end(); it++)
            {
                std::cout << *it << " "; 
            }
            std::cout << std::endl;            
        }

        template<typename H>
        void    ft_verifie_sort(H const & array, std::string const & str)
        {
            int i = 0;
            unsigned int   temp = 0;
            for (typename H::const_iterator it = array.begin(); it != array.end(); it++)
            {
                if (i > 0)
                {
                    if (*it < temp)
                    std::cout << "NO " << str << std::endl;  
                }
                temp = *it;
                i++;
            }
            std::cout << "OK " << str << std::endl;             
        }

        class echecException : public std::exception
        {
            public:
                virtual const char * what() const throw ();
        };
    
    private:
        void    ft_get_time(clock_t t);
        int     ft_unsigned_int(std::string str);
        void    ft_sort_un(std::vector<unsigned int> & vi);
        void    ft_sort_suite(std::vector<unsigned int> & vi);
        void    ft_recursive_un(std::vector<unsigned int> & vi);
        void    ft_merge(std::vector<unsigned int> & vi, std::vector<unsigned int> & left, std::vector<unsigned int> & right);
        void    ft_last(std::vector<unsigned int> & vi, std::vector<unsigned int> & tab);
        void    ft_binary_insertion(std::vector<unsigned int> & vi, unsigned int i);
        void    ft_jacobstahl(unsigned int);
        int     ft_jacobstahl_compare(unsigned int n);

        void    ft_sort_deux(std::deque<unsigned int> & de);
        void    ft_sortyop(std::deque<unsigned int> & de);
        void    ft_recursive(std::deque<unsigned int> & de, unsigned int b);
        void    ft_mergeDeux(std::deque<unsigned int> & de, std::deque<unsigned int> & left, std::deque<unsigned int> & right);
        void    ft_lastDeux(std::deque<unsigned int> & de, std::deque<unsigned int> & tab);
        void    ft_jacobstahlDeux(unsigned int n);
        int     ft_jacobstahl_compareDeux(unsigned int n);
        void    ft_binary_insertionDeux(std::deque<unsigned int> & vi, unsigned int i);

        std::vector<unsigned int>       _jacob;
        std::deque<unsigned int>        _jacobDeux;
};

#endif