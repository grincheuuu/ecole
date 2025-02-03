/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:32:32 by gschwart          #+#    #+#             */
/*   Updated: 2025/01/30 18:32:34 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base_class.hpp"
#include "A_class.hpp"
#include "B_class.hpp"
#include "C_class.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>

Base *      generate(void);
void        identify(Base * p);
void        identify(Base & p);


Base *  ft_A(void)
{
    Base *  oui = new A();
    return (oui);
}

Base *  ft_B(void)
{
    Base *  oui = new B();
    return (oui);
}

Base *  ft_C(void)
{
    Base *  oui = new C();
    return (oui);
}

Base *      generate(void)
{
    Base *    O = NULL;
    Base *   (*tab[3])(void) = {ft_A, ft_B, ft_C};

    int i = 0;
    while (1)
    {
        if (i == 3)
            i = 0;
        if (rand() % 3 == 0)
        {
            O = tab[i]();
            break;
        }
        i++;
    }
    return O;
}
void        identify(Base * p)
{
//    char     tab[3] = {'A', 'B', 'C'};
    A *     aa = dynamic_cast<A *>(p);
    B *     bb = dynamic_cast<B *>(p);
    C *     cc = dynamic_cast<C *>(p);
    if (aa != NULL)
        std::cout << "actual type of the object pointed to by p: A" << std::endl;
    if (bb != NULL)
        std::cout << "actual type of the object pointed to by p: B" << std::endl; 
    if (cc != NULL)
        std::cout << "actual type of the object pointed to by p: C" << std::endl; 
}

void        identify(Base & p)
{
    try
    {
        A &     aa = dynamic_cast<A &>(p);
        std::cout << "actual type of the object pointed to by p: A" << std::endl;
        (void)aa;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        B &     bb = dynamic_cast<B &>(p);
        std::cout << "actual type of the object pointed to by p: B" << std::endl;
        (void)bb;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        C &     cc = dynamic_cast<C &>(p);
        std::cout << "actual type of the object pointed to by p: C" << std::endl;
        (void)cc;
    }
    catch(const std::exception& e)
    {
    }
}

int main(void)
{
    Base    E;
    Base *  n = NULL;
    

    srand(time(NULL));
    n = generate();
    identify(n);
    identify(*n);
    delete n;
    std::cout << std::endl;
    n = generate();
    identify(n);
    identify(*n);
    delete n;
    std::cout << std::endl;
    n = generate();
    identify(n);
    identify(*n);
    delete n;
    std::cout << std::endl;
    n = generate();
    identify(n);
    identify(*n);
    delete n;
    std::cout << std::endl;
    n = generate();
    identify(n);
    identify(*n);
    delete n;

    
    return (0);
}
