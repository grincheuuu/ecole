/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:15:22 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/05 15:15:24 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cure_CLASS_HPP
# define Cure_CLASS_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure(void);
    Cure(Cure const & src);
    ~Cure(void);

    Cure &   operator=(Cure const & rhs);

    AMateria*   clone() const;
    void        use(ICharacter& target);
};

#endif
