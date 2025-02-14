#include "Sample.class.hpp"


//initialisation list on construit l'attribut a1 a partir de p1, gaff a l'ordre et tous les mettres (je croit)
// ici on initialise ma constante a3 a la valeur p3
Sample::Sample(char p1, int p2, float const p3) : a1(p1), a2(p2), a3(p3) // dans la classe Sample je souhaite acceder a la classe Sample
{
    std::cout << "constructor call" << std::endl;

    // this est un pointer qui pointe sur l'instance courante
    this->foo = 42; // on initialise la variable dans le constructeur
    this->bar(); // on apelle la fonction membre bar de mon instance courante
    //initialisation soit
    // this->a1 = p1;
    this->_privateFoo = 1;
    this->_privateBar();
    std::cout << this->foo << std::endl;
    std::cout << this->a1 << std::endl;
    std::cout << this->a2 << std::endl;
    std::cout << this->a3 << std::endl;
    return;
}

Sample::~Sample(void)
{
    std::cout << "destructor call" << std::endl;
    return;
}

void    Sample::bar(void) const // toujour c++ donne un parametre qui sera un pointer sur l'instance courrante
{
    std::cout << "function" << std::endl;
    return;
}

void    Sample::_privateBar(void) const
{
    std::cout << "function privayte" << std::endl;
    return;
}