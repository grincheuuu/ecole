/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main(2).cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:15:02 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/05 15:15:05 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


int main()
{
    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");

    AMateria* tmp;

    std::cout << std::endl << "ice" << std::endl;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->use(0, *bob);

    std::cout << std::endl << "cure" << std::endl;
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->use(1, *bob);

    std::cout << std::endl << "blaster" << std::endl;
    tmp = src->createMateria("blaster");
    me->equip(tmp);
    me->use(2, *bob);

    tmp = src->createMateria("blaster");
    bob->equip(tmp);    
    bob->use(0, *me);

    std::cout << std::endl << "cure" << std::endl;
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->use(3, *bob);
    me->use(2, *bob);

    tmp = src->createMateria("cure");   
    bob->equip(tmp);
    bob->use(0, *me);

    std::cout << std::endl << "sword" << std::endl;
    tmp = src->createMateria("sword");
    me->equip(tmp);
    me->use(4, *bob);

    me->use(5, *bob);
    
    delete bob;
    delete me;
    delete src;
    return 0;
}
