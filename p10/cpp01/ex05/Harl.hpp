/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:34:18 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/17 19:34:19 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CLASS_HPP
# define    HARL_CLASS_HPP

# include <iostream>
# include <string>

class Harl
{
    public:

    Harl(void);
    ~Harl(void);
    void    complain(std::string level);

    private:
        void    _debug(void);
        void    _info(void);
        void    _warning(void);
        void    _error(void);
};

#endif
