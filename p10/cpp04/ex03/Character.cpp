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
    std::cout << "Default constructor Character call" << std::endl;
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
    std::cout << "assignement constructor Character call" << std::endl;
    return;
}

Character::Character(Character const & src)
{
    std::cout << "copy constructor Character call" << std::endl;
    *this = src;
    return;
}

Character::~Character(void)
{
    int i = 0;

    while (i < 4)
    {
        if (_item[i] != NULL)
            delete _item[i];
        i++;
    }
    std::cout << "Destructor Character call" << std::endl;
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
        ICharacter::operator=(rhs);
        while (i < 4)
        {
            if (this->_item[i] != NULL)
            {
                delete this->_item[i];
                _item[i] == NULL;
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
        std::cout << "AMateria m == NULL" << std::endl;
        return;
    }
    while (i < 4)
    {
        if (_item[i] == NULL)
        {
            _item[i] = m;
            std::cout << "Character " << getName() << " take a weapon " << m->get_type() << " at the emplacement " << i << std::endl;
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
        std::cout << "idx is not between 0-3, we can't unequip" << std::endl;
        return;
    }
    temp = _item[idx];
    if (_item[idx] == NULL)
    {
        std::cout << "they have no weapons at the emplacement n'" << idx << std::endl;
        return;
    }
    _item[idx] = NULL;
    std::cout << "Character " << getName() << " unequip a weapon at the emplacement " << idx << std::endl;
    delete temp;
    return;
}

void    Character::use(int idx, ICharacter& target)
{
    if (idx > 0 && idx < 4 && _item[idx] != NULL)
    {
        _item[idx]->use(target);
    }
    else if (_item[idx] == NULL)
    {
        std::cout << "they have no weapon to use a the emplacement " << idx << std::endl;
    }
    return;
}
