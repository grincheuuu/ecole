/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:15:36 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/05 15:15:38 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_CLASS_HPP
# define CHARACTER_CLASS_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
    public:
        Character(void);
        Character(std::string name);
        Character(Character const & src);
        ~Character(void);

        Character &   operator=(Character const & rhs);

        virtual std::string const &     getName() const;
        virtual void    equip(AMateria * m);
        virtual void    unequip(int idx);
        virtual void    use(int idx, ICharacter& target);

    protected:
        AMateria*       _item[4];
        std::string     _name;
};

#endif
