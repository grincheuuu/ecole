/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:15:09 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/05 15:15:11 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_CLASS_HPP
# define ICE_CLASS_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice(void);
    Ice(Ice const & src);
    ~Ice(void);

    Ice &   operator=(Ice const & rhs);

    AMateria*   clone() const;
    void        use(ICharacter& target);
};

#endif
