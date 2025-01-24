#include <iostream>
#include "ph22.class.hpp"

int main()
{
    integer x(30);
    integer y(10);
    integer z(0);

    std::cout << "value x " << x << std::endl; //  c grace a la surcharge de ostream que
    std::cout << "value y " << y << std::endl;// je sort la valeur de x y z
    std::cout << "value z " << z << std::endl;// de la classe integer
    y = integer(12);
    std::cout << "value2 y " << y << std::endl;
    z = x + y; // x et y sont de type integer
    std::cout << "value z " << z << std::endl;
    return 0;
}