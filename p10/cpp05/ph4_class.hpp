#include <string>
#include <iostream>


//polymorphisme par soustypage
class Character
{
    public:
        void    sayHello(std::string const & target);
};

/* le warrior herite du charater, le warrior est un character 
*/

class Warrior : public Character
{
    public:
        void    sayHello(std::string const & target);
        // on redefini dans une classe fille le comportement d'une classe mere
        //sa s'appel overrider une fonction
};

void    Character::sayHello(std::string const & target)
{
    std::cout << "Hello Character" << target << std::endl;
}

void    Warrior::sayHello(std::string const & target)
{
    std::cout << "Hello Warrior" << target << std::endl;
}

int main()
{
    Warrior*    a = new Warrior();
    Character*  b = new Warrior(); // un warrior est une character

    /*mais warrior* c = new character() ne marche pas car un character n'est pas forcement
    un warrior voir ne l'est pas*/

    a->sayHello("students");
    b->sayHello("stduent");
}