/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:41:23 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/02 17:41:27 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog(void);
    Dog(std::string const & type);
    Dog(Dog const & src);
    ~Dog(void);

    Dog &    operator=(Dog const & rhs);

    void    makeSound(void) const;
};

#endif
