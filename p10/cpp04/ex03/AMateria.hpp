/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:15:41 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/05 15:15:43 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria
{
protected:
    std::string _type;
public:
    AMateria(void);
    AMateria(std::string const & type);
    AMateria(AMateria const & src);
    virtual ~AMateria(void);

    AMateria &  operator=(AMateria const & rhs);

    std::string const & getType() const; //Returns the materia type

    virtual std::string     get_type();
    virtual AMateria*       clone() const = 0;
    virtual void            use(ICharacter& target);
};

#endif // AMATERIA_HPP
