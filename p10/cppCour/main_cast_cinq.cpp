//static cast
// il ya 5 conversions possibles :
// les convesrions
// les reinterpretattions
// les changements de type qualifier qualifier
// les upscast et les downcast

//il correspondent au operateur de cast du c++

// le static cast, il nous permet de faire un certain nombre de conversion les plus simples
// possible  mais egalements de pouvoir naviguer dans l'arbre d'heritage


#include <iostream>

class Parent    {};
class Child1: public Parent {};
class Child2: public Parent {};

class Unrelated             {};

int main(void)
{
    int   a = 42;

    double    b = a; //  implicit promotion -> ok
    int       c = b; // implicit demotion -> non
    int       d = static_cast<int>(b); // explicit demotion -> ok

/* static_cast<int>(b) je souhaite faire un static cast de l'expression b
vers le type int      -> cast c++
*/

    child1   a;


    Parent *   b = &a;                       //implicit upcast -> ok
    Child1 *   c = b;                        //implicit downcast -> non
    Child2 *   d = static_cast<Child2 *>(b); //explicit downcast -> ok  // danger


// Unrelated n'a aucun rapport avec l'heritage de Child et Parent
    Unrelated * e = static_cast<Unrelated *>(&a); //Expplicit conversion -> non

    return 0;
}