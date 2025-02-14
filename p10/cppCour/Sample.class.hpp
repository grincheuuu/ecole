#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

# include <iostream>

class Sample
{
    public:
//        Sample(void);
        Sample(char p1, int p2, float const p3);
        ~Sample(void);

        char    a1;
        int     a2;
        float const   a3;

        int     foo;
        /*attribut menbre c'est une variable dans la classe 
        que l'on peu utiliser a partir d'une instance
        et sera different pour chaque instance de la classe*/
        void    bar(void) const; //fonction menbre
        //ici const signifie que cette fonction membre ne modifiera jamais l'instance courante
        //ici jamais this-> modification

    private:
        int     _privateFoo;
        void    _privateBar(void) const;
};

#endif

/* difference en structure et class (meme syntax)
struct mot cle struct a la place de class
struct  Sample 
une classe a tous ces attribut par default en private
une structure a un scope par default public */