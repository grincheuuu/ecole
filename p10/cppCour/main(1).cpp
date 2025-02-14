#include <iostream>
#include "Sample.class.hpp"


int main(void)
{
/*    char    buff[512];

    std::cout << "hello" << std::endl;
    std::cin >> buff;
    std::cout << buff << std::endl;*/

    Sample  instance('a', 42, 4.2f); // je cree une variable instance de type Sample
    // je cree une instance de Sample

    instance.foo = 42; //acces depuis l'exterieur de ma classe
    instance.bar(); //public

    return 0;
}