#include <string>

class Animal
{
    private:
        int _numberOfLeg;
    
    public:
        Animal();
        Animal(Animal const & src);
        Animal &   operator=(Animal const &);
        ~Animal();

        void    run(int distance);
};

class Cat : public Animal // le chat est un animal
{
    public:
        Cat();
        Cat(Cat const & src);
        Cat &   operator=(Cat const &);
        ~Cat();

        void    miamiam(std::string const & ggggg);
};

class Pony : public Animal
{
    public:
        Pony();
        Pony(Pony const & src);
        Pony &   operator=(Pony const &);
        ~Pony();

        void    doMagic(std::string const & ggggg);
        void    run(int distance);  // on redefini la methode
};

///////////////////////////////// protected

class Quadruped
{
    private:
        std::string name; // seul accessible pour Quadruped

    protected:
        Leg     legs[4]; // accessible pour la classe et ces clases derivees

    public:
        void    run(); // accessible par tous le monde
};

class Dog : public Quadruped
{

};