#include <iostream>
#include "ph22.class.hpp"

integer::integer(int const n) : _n(n)
{
    std::cout << "constructor called " << _n << std::endl;
    return;
}

integer::~integer(void)
{
    std::cout << "destructor called " << _n << std::endl;
    return;
}

int     integer::getValue(void) const
{
    return this->_n;
}

integer &   integer::operator=(integer const & rhs)
{
    std::cout << "operateur=" << " n " << _n << std::endl;
    std::cout << " rhs " << rhs.getValue() << std::endl;
    this->_n = rhs.getValue();
    return *this; // on dereference le pointer this pour avoir la reference
}

integer     integer::operator+(integer const & rhs) const
{
    std::cout << "operateur+" << " n " << _n << std::endl;
    std::cout << " rhs " << rhs.getValue() << std::endl;
    return integer(this->_n + rhs.getValue()); // creer une nouvel instance de la class integer
    // renvoie une copie de cette instance creer
}

std::ostream &      operator<<(std::ostream & o, integer const & rhs) // reference const 
{//sur ma classe entier car je ne la modifie pas
    o << rhs.getValue(); // je redirige mon flux de sortie o (permet de recuperer un entier)
    return o;
}