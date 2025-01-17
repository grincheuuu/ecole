



class cat
{
    public:
        class leg //class imbriquees, on defini une class dans la definition d'une autre class
        { // on va pourvoir san servir un peu comme un namespace
            //[...]
        };
};

class Dog
{
    public:
        class leg
        {
            //[...]
        };
};

// les exceptions pour gerer les erreurs
// c'est un moyen de remonter un message a travers la pile d'appel
// quand on trouve une erreur

#include <stdexcept>

//fonctions

void    test1()
{
    try // on esssaye de faire quelque chose qui pourra renvoyer une exception
    {
        if(/*si il y a une erreur*/)
        {
            throw std::exception(); // je lance une exception
            // throw remonte dans les bloc jusqua trouver un bloc catch

        }
        else
        {
            // je fais les truc prevus
        }
    }
    catch(std::exception e) // je catch une exception
    {
        //message d'erreur
        std::cerr << e.what() << '\n';
    }
}

/////////////////////////////////////////////////////

void    test2()
{
    if(/*si il y a une erreur*/)
    {
        throw std::exception(); // je lance une exception
        // throw remonte dans les bloc jusqua trouver un bloc catch

    }
    else
    {
        // je fais les truc prevus
    }
}

void    test3()
{
    try
    {
        test2();
    }
    catch(const std::exception& e) // si test 2 throw une exception ici pqr reference
    { // catch on peu le voir comme une fonction qui va prendre le parametre que l'on va catcher
        //erreur
    }
}

void    test4()
{
    class PEBKACEception : public std::exception // ce qui ma PEB... est une exception ca sa en herite ( polymorphisme)
    {
        public:
            virtual const char * what() const throw () // ici throw rien
            {// what est une virtual const char *
                return ("prrrobleme");
            }
    };

    try
    {
        test3();
    }
    catch(PEBKACEception& e) // catch specifique
    {
        // impression erreur
    }
    catch(std::exception& e) // tout autre exception, catch generique
    {
        //autre erreur
    }
}

1. Les exceptions en C++

Une exception est un mécanisme permettant de signaler une erreur ou une situation inattendue pendant l'exécution d'un programme.

    Lancer une exception :
        Utilise le mot-clé throw pour signaler une erreur.
        Exemple :

    throw Bureaucrat::GradeTooHighException();

Attraper une exception :

    Utilise un bloc try-catch pour intercepter l'exception.
    Exemple :

try
{
    Bureaucrat b("John", 0); // Erreur : grade trop bas.
}
catch (Bureaucrat::GradeTooHighException &e)
{
    std::cerr << e.what() << std::endl;
}
catch (Bureaucrat::GradeTooLowException &e)
{
    std::cerr << e.what() << std::endl;
}

. La méthode what()
Rôle :

what() est une méthode virtuelle définie dans la classe de base std::exception. Elle permet de récupérer une description textuelle de l'erreur associée à l'exception.
Propriétés :

    Renvoie un pointeur vers une chaîne de caractères (const char *).
    Par défaut, elle renvoie "std::exception" si vous n'implémentez pas une version spécifique.

Exemple dans votre code :

Dans votre classe, vous avez redéfini what() dans les exceptions personnalisées (GradeTooHighException et GradeTooLowException) :

class GradeTooHighException : public std::exception
{
    public:
        virtual const char * what() const throw ()
        {
            return "Grade is too high!";
        }
};

class GradeTooLowException : public std::exception
{
    public:
        virtual const char * what() const throw ()
        {
            return "Grade is too low!";
        }
};

Si une exception GradeTooHighException est levée, la méthode what() retournera "Grade is too high!".
Si une exception GradeTooLowException est levée, la méthode what() retournera "Grade is too low!".


Les exceptions en C++ permettent de gérer les erreurs de manière élégante en séparant le code de gestion des erreurs du code métier. Voici une explication détaillée des exceptions et du rôle de la méthode `what()` :

---

### **1. Les exceptions en C++**

Une exception est un mécanisme permettant de signaler une erreur ou une situation inattendue pendant l'exécution d'un programme.

- **Lancer une exception :**
  - Utilise le mot-clé `throw` pour signaler une erreur.
  - Exemple : 
    ```cpp
    throw Bureaucrat::GradeTooHighException();
    ```

- **Attraper une exception :**
  - Utilise un bloc `try-catch` pour intercepter l'exception.
  - Exemple :
    ```cpp
    try
    {
        Bureaucrat b("John", 0); // Erreur : grade trop bas.
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    ```

---

### **2. La méthode `what()`**

#### Rôle :
`what()` est une méthode virtuelle définie dans la classe de base `std::exception`. Elle permet de récupérer une description textuelle de l'erreur associée à l'exception.

#### Propriétés :
- Renvoie un pointeur vers une chaîne de caractères (`const char *`).
- Par défaut, elle renvoie `"std::exception"` si vous n'implémentez pas une version spécifique.

#### Exemple dans votre code :
Dans votre classe, vous avez redéfini `what()` dans les exceptions personnalisées (`GradeTooHighException` et `GradeTooLowException`) :

```cpp
class GradeTooHighException : public std::exception
{
    public:
        virtual const char * what() const throw ()
        {
            return "Grade is too high!";
        }
};

class GradeTooLowException : public std::exception
{
    public:
        virtual const char * what() const throw ()
        {
            return "Grade is too low!";
        }
};
```

- Si une exception `GradeTooHighException` est levée, la méthode `what()` retournera `"Grade is too high!"`.
- Si une exception `GradeTooLowException` est levée, la méthode `what()` retournera `"Grade is too low!"`.

---

### **3. Fonctionnement global dans votre classe `Bureaucrat`**

#### Vérification et gestion des grades :
Dans le constructeur ou les méthodes `incrementGrade` et `decrementGrade`, vous pourriez vérifier si le grade est valide et lever une exception sinon :

```cpp
Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}
```

---

### **4. Exemple d'utilisation**

```cpp
int main()
{
    try
    {
        Bureaucrat b("Alice", 0); // Le grade est trop élevé !
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b("Bob", 151); // Le grade est trop bas !
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
```

#### Sortie :
```
Exception caught: Grade is too high!
Exception caught: Grade is too low!
```

---

### **Résumé**

1. **Les exceptions :**
   - Utilisez `throw` pour signaler une erreur.
   - Utilisez `try-catch` pour capturer et gérer l'exception.

2. **La méthode `what()` :**
   - Fournit une description textuelle de l'erreur.
   - Peut être redéfinie pour fournir des messages personnalisés.

3. **Dans `Bureaucrat` :**
   - Les exceptions permettent de signaler des grades invalides.
   - La méthode `what()` donne des informations utiles sur l'erreur rencontrée.
