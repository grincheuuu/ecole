#include <string>
#include <iostream>


// classe abstract and interface
class ACharacter
{
    public:
        virtual void    attack(std::string const & target) = 0; //methode pure
        //la methode la on ne peut pas l'implementer et on ne peut pas l'instancier
        void            sayHello(std::string const & target);
};

//la classe mere n'a pas de comportement attack

class Warrior : public ACharacter
{
    public:
        virtual void    attack(std::string const & target);
};

class   ICoffeeMaker // interface, pas d'attribut
{// tous les enfants en herites
    public:
        virtual void    water(IWaterSource * src) = 0;
        virtual ICoffee* coffee(std::string const & type) = 0;
};



void    ACharacter::sayHello(std::string const & target)
{
    std::cout << "Hello " << target << std::endl;
}

void    Warrior::attack(std::string const & target)
{
    std::cout << "attack " << target << std::endl;
}

int main()
{
    ACharacter*     a = new Warrior ();

    a->sayHello("student");
}

