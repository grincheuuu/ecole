// type cast d'operateur = il permet de definir au sein des class, des operateurs specifique
// a fein de pouvoir faire des conversion implicit de la class
// vers un type choisi

#include <iostream>

class Foo
{
    public:
        Foo(float const v) : _v(v)
        {
            return;
        }

        float   getV(void) { return this->_v;}


// operateur de cast : mot cle operator puis le type vers le type que je souhaite
//faire le class implicite sur ma class Foo
        operator float ()
        {
            return this->_v;
        }
        operator int()
        {
            return static_cast<int>(this->_v);
        }
    private:
        float   _v;
};

int main(void)
{
    Foo a(420.42f);
    float   b =a; // cast implicit d'un type Foo vers float
    // le compilateur va chercher si il ya un operateur de class vers float
    int   c = a; // cast implicit de foo vers int

    std::cout << a.getV() << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    return (0);
}