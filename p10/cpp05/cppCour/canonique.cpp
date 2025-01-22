#include "canonique.class.hpp"

Sample::Sample(void) : _foo(0)
{
    std::cout << "default constructeur called" << _foo << std::endl;
    return;
}

Sample::Sample(int const n) : _foo(n)
{
    std::cout << "default assignement constructeur called" << _foo << std::endl;
    return;
}

Sample::Sample(Sample const & src)
{
    std::cout << "constructeur par copie called" << std::endl;
    *this = src;
    return;
}

Sample::~Sample(void)
{
    std::cout << "destructor called" << _foo << std::endl;
    return;
}

Sample &    Sample::operator=(Sample const & rhs)
{
    std::cout << "operateur =" << std::endl;
    if (this != &rhs)
        this->_foo = rhs.getFoo();
    
    return *this;
}

int     Sample::getFoo(void) const
{
    std::cout << "getFoo" << std::endl;
    return this->_foo;
}

//on pourra rajouter une fonction membre qui permetra d'avoir une version
//sous forme de string de la classe pour pouvoir l'afficher
// c'est tres proche de la surcharge de <<

std::ostream &    operator<<(std::ostream & o, Sample const & i)
{
    o << "ostrem foo = " << i.getFoo();
    return o;
}
