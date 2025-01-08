/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:50:30 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/05 17:50:32 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : IMateriaSource()
{
    int i = 0;

    while (i < 4)
    {
        this->_tab[i] = NULL; 
        i++;
    }
//   std::cout << BLUE "Default MateriaSource call" RESET << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & src) : IMateriaSource(src)
{
//    std::cout << BLUE "copy constructor MateriaSource call" RESET << std::endl;
    *this = src;
    return;
}

MateriaSource::~MateriaSource(void)
{
    int i = 0;

    while (i < 4)
    {
        if (_tab[i] != NULL)
            delete _tab[i];
        i++;
    }
//    std::cout << YELLO "Destructor MateriaSource call" RESET << std::endl;
    return;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
    int i = 0;
    if (this != &rhs)
    {
         while (i < 4)
        {
            if (_tab[i] != NULL)
            {
                delete _tab[i];
                _tab[i] = NULL;
            }
            i++;
        }
        i = 0;
        while (i < 4)
        {
            this->_tab[i] = rhs._tab[i]; 
            i++;
        }
    }
    return (*this);
}

void        MateriaSource::learnMateria(AMateria* m)
{
    int i = 0;

    if (m == NULL)
    {
        std::cout << RED "they have no materia to learn" RESET << std::endl;
        return;
    }
    while (i < 4)
    {
        if (_tab[i] == NULL)
        {
            _tab[i] = m;
            return;
        }
        i++;
    }
    return;
}

AMateria*   MateriaSource::createMateria(std::string const & type)
{
    int i = 0;

    while (i < 4)
    {
        if (_tab[i] && _tab[i]->getType() == type)
        {
            return (_tab[i]->clone());
        }
        i++;
    }
    std::cout << RED "they have no materia to create" RESET << std::endl;
    return (NULL);
}
