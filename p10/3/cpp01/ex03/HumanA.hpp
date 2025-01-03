/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:32:23 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/15 16:32:24 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
    public:
    
        HumanA(std::string const name, Weapon &weaponT);
        ~HumanA(void);

        void    attack(void) const;

    private:
        Weapon          &_weaponT;
        std::string const     _name;
};

#endif
