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

class PmergeMe
{
    private:
        PmergeMe(void);
        PmergeMe(PmergeMe const & rhs);
        ~PmergeMe(void);

        PmergeMe &      operator=(PmergeMe const & src);

    public:
        static int     ft_unsigned_int(std::string str);
        static void    ft_sort_un(std::vector<unsigned int> & vi);
        static void    ft_sort_suite(std::vector<unsigned int> & vi);
        static void    ft_recursive_un(std::vector<unsigned int> & vi, unsigned int b);
        static void    ft_merge(std::vector<unsigned int> & vi, std::vector<unsigned int> & left, std::vector<unsigned int> & right);
        static void    ft_last(std::vector<unsigned int> & vi, std::vector<unsigned int> & tab);
        static void    ft_binary_insertion(std::vector<unsigned int> & vi, unsigned int);
        static int     ft_jacobstahl(int);

};

std::ostream &      operator<<(std::ostream & o, PmergeMe const & rhs);
#endif
