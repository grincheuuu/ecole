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

#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    const Cat   k;

    k.makeSound();
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    const WrongAnimal* Wrongmeta = new WrongAnimal();
    const WrongAnimal* Wrongi = new WrongCat();

    std::cout << "i " << i->getType() << " ";
    i->makeSound();
    std::cout << std::endl;
    std::cout << "j " << j->getType() << " ";
    j->makeSound();
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

    return (0);
}
