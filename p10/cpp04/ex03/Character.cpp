/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:53:08 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/05 15:53:10 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
//    std::cout << BLUE "Default constructor Character call" RESET << std::endl;
    return;
}

Character::Character(std::string name) : _name(name)
{
    int i = 0;
    while (i < 4)
    {
        this->_item[i] = NULL; 
        i++;
    }
//    std::cout << BLUE "assignement constructor Character call" RESET << std::endl;
    return;
}

Character::Character(Character const & src)
{
//    std::cout << BLUE "copy constructor Character call" RESET << std::endl;
    *this = src;
    return;
}

Character::~Character(void)
{
    int i = 0;

    while (i < 4)
    {
        if (_item[i] != NULL)
        {
//            std::cout << YELLO "Character call " RESET << _item[i]->getType() << std::endl;
            delete _item[i];
        }
        i++;
    }
//    std::cout << YELLO "Destructor Character call " RESET << std::endl;
    return;
}

std::string const &     Character::getName() const
{
    return (this->_name);
}

Character &   Character::operator=(Character const & rhs)
{
    int i = 0;

    if (this != &rhs)
    {
        while (i < 4)
        {
            if (this->_item[i] != NULL)
            {
                delete this->_item[i];
                _item[i] = NULL;
            }
            i++;
        }
        i = 0;
        this->_name = rhs._name;
        while (i < 4)
        {
            this->_item[i] = rhs._item[i]->clone();
            i++;
        }
    }
    return (*this);
}

void    Character::equip(AMateria* m)
{
    int i = 0;

    if (m == NULL)
    {
        std::cout << RED "AMateria m == NULL" RESET << std::endl;
        return;
    }
    while (i < 4)
    {
        if (_item[i] == NULL)
        {
            _item[i] = m;
            std::cout << "Character " << BL << getName() << RESET << " take a weapon " << m->getType() << " at the emplacement " << i << std::endl;
            return;
        }
        i++;
    }
    return;
}

void    Character::unequip(int idx)
{
    AMateria*   temp;

    if (idx < 0 || idx > 3)
    {
        std::cout << RED "idx is not between 0-3, we can't unequip" RESET << std::endl;
        return;
    }
    temp = _item[idx];
    if (_item[idx] == NULL)
    {
        std::cout << RED "they have no weapons at the emplacement n'" RESET << idx << std::endl;
        return;
    }
    _item[idx] = NULL;
    std::cout << "Character " << BL << getName() << RESET << " unequip a weapon at the emplacement " << idx << std::endl;
    delete temp;
    return;
}

void    Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && _item[idx] != NULL)
    {
        _item[idx]->use(target);
    }
    else if (_item[idx] == NULL)
    {
        std::cout << RED "they have no weapon to use a the emplacement " RESET << idx << std::endl;
    }
    else
        std::cout << RED "idx is not between 0-3, we can't use" RESET << std::endl;
    return;
}
