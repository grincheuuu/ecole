#include <string>
#include <iostream>


//les references c'est comme un alias vers une variable existante
//une reference est pointeur constant, tjs dereference et qui n'est jamis null

int main()
{
    int numberOfBalls = 4;

    int*    ballsPointer = &numberOfBalls; // le pointer on affecte une addresse
    int&     ballsReference = numberOfBalls; //reference, la reference pointe sur la variable
    //et ne pourra pas pointer sur autre chose et doit tjs etre affecte

    std::cout << " numberOfBalls " << numberOfBalls << " pointer " << *ballsPointer << " reference " << ballsReference << std::endl;
    *ballsPointer = 21;
    std::cout << numberOfBalls << " number Of Balls " << std::endl;
    ballsReference = 19;
    std::cout << numberOfBalls << " number Of Balls " << std::endl;
    return (0);
}