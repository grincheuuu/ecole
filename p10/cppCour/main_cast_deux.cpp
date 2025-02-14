// un autre type de convertion est la convertion identitaire
// la valeur de base apres la convertion garde les meme bites dans le meme ordre
// sa s'appelle une reinterpretation

#include <stdio.h>

int main(void)
{
    float   a = 420.42f;

// void *  contient une adresse sur nimporte quel type
    void *  b = &a; // implicit reinterpretation cast
    void *  c = (void *) &a; // explicit reinterpretation cast
// reinterpretation des float vers des void * (nimporte quel type)
// on perd en precision

    void *  d = &a; // implicit promotion -> ok

// de void * a int *
// demotion on gagne en precision
//    int *   e = d; // implicit demotion -> aleatoire 
    int *   f = (int *) d; //explicit demotion -> ok

    printf("%p, %f\n", &a, a);

    printf("%p\n", b); 
    printf("%p\n", c); 

    printf("%p\n", d); 
//    printf("%p, %d\n", e, *e); 
    printf("%p, %d\n", f, *f);
    return 0;
}