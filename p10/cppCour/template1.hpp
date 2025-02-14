#include <iostream>

int     max(int x, int y)
{
    return (x >= y ? x : y);//x >= y si oui on renvoie x sinon on renvoi y
}


template< typename T> // pour indiquer a mon compilateur que c un template de fonction il faut le mot cle template et entre < > typename puis la variable de type ou la liste de type
T const &     max(T const & x, T const & y) // type T quelquonque mais le meme // on prend les parametre par reference pour ne pas copier l'instance et const car ne modifie ni x ni y
{
    return (x >= y ? x : y);//x >= y si oui on renvoie x sinon on renvoi y
}

/////////////////////////////////////////////////////////


template< typename T> //definition template
T     max(T const & x, T const & y)
{
    return ((x >= y) ? x : y);
}

int  foo(int x)
{
    std::cout << "fgfgqfgf" << std::endl;
    return x
}

int     main(void)
{
    int     a = 21;
    int     b = 42;


//ici a et b on le meme type
    std::cout << "Max of " << a << " and " << b << " is ";
    std::cout << max<int>(a, b) << std::endl; // explicit instanciation
    std::cout << "Max of " << a << " and " << b << " is ";
    std::cout << max(a, b) << std::endl; // implicit instanciation

    float     c = 21.02f;
    float     d = 4.2f;

    std::cout << "Max of " << c << " and " << d << " is ";
    std::cout << max<float>(c, d) << std::endl; // explicit instanciation
    std::cout << "Max of " << c << " and " << d << " is ";
    std::cout << max(c, d) << std::endl; // implicit instanciation

    int ret = max<int>( foo(a), foo(b)); // explicit instaciation // fonction non ecrite, le compilateur la ferra
    std::cout << "Max of " << a << " and " << b << " is ";
    std::cout << ret << std::endl;

    return (0);
}