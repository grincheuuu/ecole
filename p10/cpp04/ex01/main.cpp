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
    
    delete j;
    delete i;

    const Animal*   tab[10];
    unsigned int    n = 0;

    while (n < 10)
    {
        if (n < 5)
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
        if (n < 5)
            delete tab[n];
        else
            delete tab[n];
    }

    return (0);
}
