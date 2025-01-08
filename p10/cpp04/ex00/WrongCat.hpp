/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:31:15 by gschwart          #+#    #+#             */
/*   Updated: 2024/10/11 18:31:18 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_CLASS_HPP
# define WrongCat_CLASS_HPP

# include "WrongAnimal.hpp"
# include <iostream>
# include <string>


class WrongCat : public WrongAnimal
{
public:
    WrongCat(void);
    WrongCat(std::string const & type);
    WrongCat(WrongCat const & src);
    ~WrongCat(void);

    WrongCat &    operator=(WrongCat const & rhs);

    void    makeSound(void) const;
};

#endif