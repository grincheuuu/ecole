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
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	std::cout << std::endl <<  "-------------------------------" << std::endl
		<< "\tMATERIA SOURCE TEST" << std::endl
		<<  "-------------------------------" << std::endl;
	std::cout << std::endl << "-- MATERIA SOURCE CREATION" << std::endl;
	MateriaSource * source = new MateriaSource();


	std::cout << std::endl << "-- MATERIA SOURCE LEARNING RECIPES" << std::endl;
	source->learnMateria(NULL);
	source->learnMateria(new Cure());
	source->learnMateria(new Ice());
	std::cout << std::endl << "-- MATERIA SOURCE DEEP COPY" << std::endl;
	MateriaSource * copySource = new MateriaSource(*source);
	std::cout << "Original ";

	std::cout << "Copy ";

	std::cout << "Original Materia Source learns another recipe:" << std::endl;
	source->learnMateria(new Cure());
	std::cout << "Original ";

	std::cout << "Copy ";

	std::cout << "Deleting Copy Materia Source:" << std::endl;
	delete copySource;

	std::cout << std::endl << "-- MATERIA SOURCE LEARNING TOO MANY RECIPES" << std::endl;

	source->learnMateria(new Ice());
	source->learnMateria(new Cure());


	std::cout << std::endl << "-- MATERIA SOURCE CREATING MATERIA FROM RECIPES" << std::endl;
	AMateria *	m1 = NULL;
	AMateria *	m2 = NULL;
	AMateria *	m3 = NULL;
	
	m1 = source->createMateria("ice");
	if (m1 == NULL)
		std::cout << "Materia was not created." << std::endl;
	else
		std::cout << "Created materia is " << m1->getType() << std::endl;
	m2 = source->createMateria("cure");
	if (m2 == NULL)
		std::cout << "Materia was not created." << std::endl;
	else
		std::cout << "Created materia is " << m2->getType() << std::endl;
	m3 = source->createMateria("rock");
	if (m3 == NULL)
		std::cout << "Materia was not created." << std::endl;
	else
		std::cout << "Created materia is " << m2->getType() << std::endl;
	if (m1 != NULL)
		delete m1;
	if (m2 != NULL)
		delete m2;
	if (m2 != NULL)
		delete m3;

	std::cout << std::endl << "-- MATERIA SOURCE DELETION" << std::endl;
	delete source;
/*    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");

    me->equip(tmp);

    tmp = src->createMateria("cure");

    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
    return 0;*/
}
