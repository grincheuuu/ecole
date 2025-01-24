#include <string>
#include <iostream>

//passage de parametre par reference


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

        std::string &       getLoginRef()
        {
            return this->_login;
        }
        std::string const &       getConstLoginRef() const
        {
            return this->_login;
        }

        std::string *       getLoginPtr()
        {
            return &(this->_login);
        }
        std::string const *       getConstLoginPtr() const
        {
            return &(this->_login);
        }
};


void    byPtr(std::string* str)
{
    *str += " and ponies";
}

void    byConstPtr(std::string const * str)
{
    std::cout << *str << std::endl;
}

void    byRef(std::string& str)
{
    str += " and licorne";
}

void    byConstRef(std::string const & str)
{
    std::cout << str << std::endl;
}

int main()
{
    std::string     str = "i like butterflies";

    std::cout << str << std::endl;
    byPtr(&str);
    byConstPtr(&str);

    str = "i like chats";
    std::cout << str << std::endl; 
    byRef(str);
    byConstRef(str);

    Student     bob = Student("bfubar");
    Student const    jim = Student("jfubar");

    std::cout << bob.getConstLoginRef() << " " << jim.getConstLoginRef() << std::endl;
    std::cout << *(bob.getConstLoginPtr()) << " " << *(jim.getConstLoginPtr()) << std::endl;
    bob.getLoginRef() = "Windows";

    std::cout << bob.getConstLoginRef() << std::endl;

    *(bob.getLoginPtr()) = "bobyfubar";
    std::cout << *(bob.getConstLoginPtr()) << std::endl; 

    return (0);
}

// si sa peut exister on utilise un pointeur
// si sa doit toujours exister et jamais changer j'utilise une reference