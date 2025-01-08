#ifndef INTEGER_CLASS_H
# define INTEGER_CLASS_H

# include <iostream>

// surcharge d'operateur
/* 1+1 notation infixe ( entre 1 et 1)
+ 1 1  notation prefixe ou notation fonctionnel +(1, 1)
1 1 + notations postfixe*/

class integer
{
    public:
        integer(int const n);
        ~integer(void);

        int     getValue(void) const;

        integer &   operator=(integer const & rhs); // rhs right on side
        integer     operator+(integer const & rhs) const;
    
    /* le mot cle operator operator permet de faire une surcharge d'operateur
    = et + sont binaire
    c++  passe systematiquement par default une reference sur une instance courante
    pour = il va passer la valeur de l'entier n de l'instance courante a la valeur de l'entier
    passer en parametre, l'instance courante va etre modifier. n = 2 ici renvoie
    l'instance courante modifier
    une addition ne modifie pas les operande (1 + 1) mais un resultat est creer
    ici vu que l'instance courante n'est pas modifier, renvoie une copie du resulat
    par une nouvel instance creer dans l'operateur plus et renvoie une copie
    pour faire 1 + 1 + 2 */

    private:
        int     _n;

};

std::ostream &      operator<<(std:: ostream & o, integer const & rhs);
//on fait une surcharge de fonction non membre
// on prend en 1er parametre une reference sur une instance de ostream
//et en second parametre ma classe
//je renvoie une reference sur une instance de ostream

#endif