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
#include "Brain.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "i " << i->getType() << " ";
    i->makeSound();
    std::cout << std::endl;
    std::cout << "j " << j->getType() << " ";
    j->makeSound();
    std::cout << std::endl;

    const Animal*   tab[100];
    unsigned int    n = 0;

    while (n < 100)
    {
        if (n < 50)
            tab[n] = new Dog();
        else
            tab[n] = new Cat();
        std::cout << n << " " << tab[n]->getType() << " ";
        tab[n]->makeSound();
        std::cout << std::endl;
        n++;
    }
    while (n)
    {
        n--;
        if (n < 50)
            delete tab[n];
        else
            delete tab[n];
    }

    delete j;
    delete i;

    return (0);
}
