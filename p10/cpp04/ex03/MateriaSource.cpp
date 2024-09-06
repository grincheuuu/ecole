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
    std::cout << "Default MateriaSource call" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & src) : IMateriaSource(src)
{
    std::cout << "copy constructor MateriaSource call" << std::endl;
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
    std::cout << "Destructor MateriaSource call" << std::endl;
    return;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
    int i = 0;
    if (this != &rhs)
    {
        MateriaSource::operator=(rhs);
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
        std::cout << "they have no materia to learn" << std::endl;
        return;
    }
    while (i < 4)
    {
        if (_tab[i] == NULL)
        {
            _tab[i] == m;
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
        if (_tab[i] && _tab[i]->get_type() == type)
            return (_tab[i]->clone());
        i++;
    }
    std::cout << "they have no materia to create" << std::endl;
    return (NULL);
}
