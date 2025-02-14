// mot cle explicit
// c++ autorise systematiquement un cast implicit d'une expression ou que se soit dans le code

#include <iostream>

class A {};
class B {};

class C
{
    public:
        c(A const & _ ) { return ;} // 1er constructeur qui prend une instance d'une class A
        explicit    c(B const & _){ return ;} // 2eme constructeur  B

    // le mot cle explicit interdit la conversion implicit de l'instance
};

// C est construit soit avec une instance de la classe A soit de la classe B

void    f( C const & _) // une fonction qui prend une refenrece sur une fonction C constante
{
    return;
}

int main(void)
{
    f(A()); // implicit conversion = Ok
    f(B()); // imlicit conversion = non OK , constructeur explicit

    return (0);
}