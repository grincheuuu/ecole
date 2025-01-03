/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:50:44 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/05 17:50:45 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_CLASS_HPP
# define MATERIASOURCE_CLASS_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource(void);
        MateriaSource(MateriaSource const & src);
        ~MateriaSource(void);

        MateriaSource & operator=(MateriaSource const & rhs);

        void        learnMateria(AMateria* m);
        AMateria*   createMateria(std::string const & type);

    private:
        AMateria*   _tab[4];
};

#endif
