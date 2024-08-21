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

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
    public:

        Zombie(void);
        Zombie(std::string  name);
        ~Zombie(void);

        void    set_name(std::string name);

        void    annonce(void);

    private:

        std::string _name;
};

#endif