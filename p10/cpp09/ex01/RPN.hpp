/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:20:53 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/20 18:20:55 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <queue>

class RPN
{
    public:
        static void    ft_calcul(std::queue<int> nb, std::queue<char> chr);
        static int     ft_pars(std::string ligne);

    private:
        RPN(void);
        RPN(RPN const & src);
        ~RPN(void);

        RPN &       operator=(RPN const & rhs);
};

#endif
