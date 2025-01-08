/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:52:22 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/05 15:52:24 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include "AMateria.hpp"

class AMateria;

class ICharacter
{
    public:
        virtual ~ICharacter() {}

        virtual std::string const & getName() const = 0;
        virtual void    equip(AMateria* m) = 0;
        virtual void    unequip(int idx) = 0;
        virtual void    use(int idx, ICharacter& target) = 0;
};

