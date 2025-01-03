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

#ifndef AANIMAL_CLASS_HPP
# define AANIMAL_CLASS_HPP

# include <iostream>
# include <string>

class AAnimal
{
public:
    AAnimal(void);
    AAnimal(std::string const & type);
    virtual ~AAnimal(void);

    AAnimal &    operator=(AAnimal const & rhs);

    std::string const &     getType(void) const;
    virtual void            makeSound(void) const = 0;
protected:
    std::string _type;
};

#endif
