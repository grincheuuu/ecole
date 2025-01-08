/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:42:02 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/02 17:42:04 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongAnimal_CLASS_HPP
# define WrongAnimal_CLASS_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
public:
   WrongAnimal(void);
   WrongAnimal(std::string const & type);
   WrongAnimal(WrongAnimal const & src);
    virtual ~WrongAnimal(void);

   WrongAnimal &    operator=(WrongAnimal const & rhs);

    std::string const &     getType(void) const;
    virtual void            makeSound(void) const;
protected:
    std::string _type;
};

#endif
