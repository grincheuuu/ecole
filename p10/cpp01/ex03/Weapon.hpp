/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:02:50 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/15 15:02:52 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
    public:
        Weapon(void);
        Weapon(std::string type);
        ~Weapon(void);

        std::string const   getType(void) const;
        void                setType(std::string const type);

    private:

        std::string   _type;
};

#endif
