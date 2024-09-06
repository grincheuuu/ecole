/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:41:48 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/02 17:41:50 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    const WrongAnimal* Wrongmeta = new WrongAnimal();
    const WrongAnimal* Wrongi = new WrongCat();

    std::cout << "i " << i->getType() << " ";
    i->makeSound();
    std::cout << std::endl;
    std::cout << "j " << j->getType() << " ";
    j->makeSound();
    std::cout << std::endl;
    std::cout << "meta " << meta->getType() << " ";
    meta->makeSound();
    std::cout << std::endl;
    std::cout << Wrongi->getType() << " ";
    Wrongi->makeSound();
    std::cout << std::endl;
    std::cout << Wrongmeta->getType() << " ";
    Wrongmeta->makeSound();
    std::cout << std::endl;

    delete j;
    delete i;
    delete Wrongi;
    delete Wrongmeta;
    delete meta;

    return (0);
}
