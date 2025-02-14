#include <iostream>
#include "template3.hpp"


int     main(void)
{
    Vertex<int>     v1(11, 12, 18);
    Vertex<>        v2(11, 12, 18); //type par default -> ici convertion implicit

    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;

    return (0);
}