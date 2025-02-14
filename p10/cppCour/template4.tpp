//specialization
// on pourra specialiser completement que un template de fonction
// on fonction du type des valeur envoye on pourra utiliser tell ou tell type de specialisation

#include <iostream>
#include <iomanip>
#include <string.h>

template< typename T, typename U > 
class Pair
{
    public:
        Pair<T, U>(T const & lhs, U const & rhs) : _lhs(lhs), _rhs(rhs) 
        {
            std::cout << "generic template" << std::endl;
            return;
        }
        ~Pair< T, U >(void) {}

        T const &   fst(void) const { return this->_lhs; }
        U const &   snd(void) const { return this->_rhs; }

    private:
        T const &    _lhs;
        U const &    _rhs;

        Pair<T, U>(void);
};

///////////////////////////////////////////////////////////////////

//specialisation partiel

template< typename U > 
class Pair< int, U > // 1er type tjs int et le 2eme parametre (variable) template
{
    public:
        Pair< int, U >( int lhs, U const & rhs ) : _lhs( lhs ), _rhs( rhs ) 
        {
            std::cout << "int partial specialisation" << std::endl;
            return;
        }
        ~Pair< int, U >(void) {}

        int         fst(void) const { return this->_lhs; }
        U const &   snd(void) const { return this->_rhs; }

    private:
        int          _lhs;
        U const &    _rhs;

        Pair< int, U >( void );
};

//////////////////////////////////////////////////

//specialisation complete ; dans tous les autres cas utilise le template generique
// mais si les prametres que tu me donne sont les suivant alor utilise template

template<> // plus de variable de type
class Pair< bool, bool > // type specialiser
{
    public:
        Pair< bool, bool >(bool lhs, bool rhs)
        {
            std::cout << "bool/bool specialisation" << std::endl;
            this->_n = 0;
            this->_n != static_cast<int>(lhs) << 0; //1erbit 
            this->_n != static_cast<int>(rhs) << 1; //decalage de 1bit pour stocker le deuxieme bit
            // le 1er this va soit mettre mon 1er bit a 0 ou a 1 si c'est true ou false en fonction de lhs
            return;
        }
        ~Pair< bool, bool >(void) {}

        bool       fst(void) const { return (this->_n & 0x01); }
        bool       snd(void) const { return (this->_n & 0x02); }

    private:
        int          _n;

        Pair< bool, bool >(void); // constructeur par default
};


//////////////////////////////////////////////////////////

template< typename T, typename U >
std::ostream &      operator<<(std::ostream & o, Pair<T, U> const & p) //template d'une surcharge de fonction
{
    o << "Pair( " << p.fst() << ", " << p.snd() << ")";
    return o;
}

std::ostream &      operator<<(std::ostream & o, Pair<bool, bool> const & p) //template d'une surcharge de fonction
{
    o << std::boolalpha << "Pair( " << p.fst() << ", " << p.snd() << ")";
    return o;
}


/////////////////
/*
on a un template generique qui sera utiliser dans tous les cas

sauf si le 1er parametre est un int

ou que les 2 parametres sont de bool
*/