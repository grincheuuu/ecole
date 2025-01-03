/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:50:14 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/05 17:50:15 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class IMateriaSource
{
public:
    virtual ~IMateriaSource(void) {}

    virtual void        learnMateria(AMateria * m) = 0;
    virtual AMateria*   createMateria(std::string const & type) = 0;
};

#endif
