// cast de type qualifier
// qualifier est un mot cle en c comme const ou volatile
// dans qualifier il y a une hierarchie dans les types

#include <stdio.h>

int main(void)
{
    int   a = 42;

// on passe d'une variable normal a une const
    int const *  b = &a; // implicit type qualifier cast
    int const *  c = (int const *) &a; // explicit type qualifier cast

    int const *  d = &a; // implicit promotion -> ok

// on passe de const a non const
    int *   e = d; //        implicit demotion -> non
    int *   f = (int *) d; //explicit demotion -> ok

    return 0;
}