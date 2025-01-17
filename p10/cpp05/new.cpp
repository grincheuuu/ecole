#include <iostream>
#include <string>

class Student
{
    private:
        std::string _login;

    public:
        Student(std::string login) : _login(login)
        {
            std::cout << "Student " << this->_login << std::endl;
        }
        ~Student()
        {
            std::cout << "destructeur called " << this->_login << std::endl;
        }
};

class Student2
{
    private:
        std::string _login;

    public:
        Student2() : _login("default")
        {
            std::cout << "Student2 " << this->_login << std::endl;
        }
        ~Student2()
        {
            std::cout << "destructeur2 called " << this->_login << std::endl;
        }
};

int main()
{
    Student     bob = Student("bfubar"); // student allouer sur la pile
    Student     Guillaume("Hello");
    Student*    jim = new Student("jfubar"); // allouer  et avec un pointeur
    Student2*    students = new Student2[42]; // ici constructeur sans parametre
    //allocationd d'un tableau de Student2 // pas de parametre possible

    delete jim;
    delete [] students; // suppression du tableau
    return 0;
}