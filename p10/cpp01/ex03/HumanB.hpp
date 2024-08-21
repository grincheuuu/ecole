/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:33:06 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/15 16:33:08 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
    public:
    
        HumanB(std::string const name);
        ~HumanB(void);

        void    attack(void) const;
        void    setWeapon(Weapon &weapon);

    private:
        Weapon               *_weaponT;
        std::string const    _name;
};

#endif
