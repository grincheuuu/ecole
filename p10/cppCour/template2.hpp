// on peut ecrire des class et des structures template

#include <iostream>

template< typename T > // a l instanciation T va devenir le type effectif
class List //list chainer
{
    public:
        List<T>( T const & content){} //constructeur, cree la list
        List<T>( List<T> const & list) {}
        ~List<T>(void) {}

    private:
// ou   T           _content;
        T *         _content;
        List<T> *   _next;
};

int main(void)
{
    List< int >             a( 42 ); // on instancie le template ici avec le type int
    List< float >           b(3.14f);
    List< List< int > >     c( a ); // list sur une list d'int

    return (0);
}