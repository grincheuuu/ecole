/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:40:41 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/02 17:40:43 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
public:
    Animal(void);
    Animal(std::string const & type);
    Animal(Animal const & src);
    virtual ~Animal(void);

    Animal &    operator=(Animal const & rhs);

    std::string const &     getType(void) const;
    virtual void            makeSound(void) const;
protected:
    std::string _type;
};

#endif
