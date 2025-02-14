#include <iostream>

// reinterpretation d'adresse de classe, se sont les upcast et downcast

class Parent    {};
class Child1: public Parent {};
class Child2: public Parent {};

//il ya une hierrarchie qui va se rencontrer avec les class
// la class parent est une classe génerique, moin specifique que les classes enfants

int main(void)
{
    child1   a;

// on va d'un typre precis Child vers un type plus generique l'adresse de Parent
    Parent *  b = &a; // implicit reinterpretation cast , l enfant comporte un parent
    Parent *  c = (Parent *) &a; // explicit reinterpretation cast

    Parent *  d = &a; // implicit upcast -> ok

// downcast de parent vers enfants
    Child1 *   e = d; //        implicit downcast -> non
    Child2 *   f = (Child2 *) d; //explicit downcast -> ok mais probleme a interdire

    return 0;
}