//dynamic cast =  il a lieu a l execution pas a la compilation, apres la compilation et il peu echouer
// il ne fonctionne que dans le cas d'une instance polymorphique, il faudra au moin une fonction menbre virtuel pour l'utiliser dessus
// que downcast et que sur des cast de pointeurs ou de reference


#include <iostream>
#include <typeinfo>
#include <exception>

class Parent { public : virtual ~Parent(void) {} };
class Child1: public Parent{};
class Child2: public Parent {};

int main()
{
    Child1      a;
    Parent *    b = &a;  //implicit cast -> ok

    // explicit downcast ->
    // le dynamic cast renvoie sur un pointer soit l'adresse converti soit NULL ( cast pas possible )
    Child1*     c = dynamic_cast<Child1 *>(b);
    if (c == NULL)
    {
        std::cout << "NULL" << std::endl;
    }
    else
        std::cout << "ok" << std::endl;

    // explicit downcast ->
    // ici dans le cas des reference, une reference est toujours non null
    // donc c++ nous permet de lever une exception
    try {
        Child2 &    d = dynamic_cast<Child2 &>(*b);
        std::cout << "ok" << std::endl;
    }
    catch (std::bad_cast & bc)
    {
        std::cout << "echec" << bc.what() << std::endl;
        return 0;
    }
    return 0;
}