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

Cette syntaxe en C++ définit un tableau de pointeurs vers des fonctions. Analysons cela étape par étape :

---

### Déclaration Décomposée
```cpp
AForm* (*Atab[3])(std::string const &);
```

#### 1. **Le tableau de taille 3**
```cpp
Atab[3]
```
Cela indique que `Atab` est un tableau de taille 3. Chaque élément du tableau contiendra un pointeur vers une fonction.

---

#### 2. **Type des éléments du tableau**
```cpp
(*Atab[3])
```
Le symbole `*` avant `Atab` signifie que chaque élément du tableau est un pointeur. Ce tableau contient donc des **pointeurs vers des fonctions**.

---

#### 3. **Signature des fonctions pointées**
```cpp
(std::string const &)
```
Cela décrit les paramètres que chaque fonction doit accepter. Dans ce cas, chaque fonction pointée doit accepter un argument de type `std::string const&` (une référence constante à une chaîne de caractères).

```cpp
AForm*
```
Cela indique que chaque fonction doit **retourner un pointeur vers un objet de type `AForm`**.

---

### Initialisation
```cpp
= {newPresidentialPardonForm, newRobotomyRequestForm, newShrubberyCreationForm};
```

1. **`newPresidentialPardonForm`, `newRobotomyRequestForm`, et `newShrubberyCreationForm`** :
   Ces fonctions ont été définies comme suit :
   ```cpp
   AForm* newPresidentialPardonForm(std::string const& b);
   AForm* newRobotomyRequestForm(std::string const& b);
   AForm* newShrubberyCreationForm(std::string const& b);
   ```
   Elles correspondent exactement à la signature définie dans `Atab`. Elles prennent une référence constante à une chaîne (`std::string const&`) et renvoient un pointeur vers un objet `AForm`.

2. **Initialisation du tableau** :
   Chaque élément du tableau pointe vers l'une de ces fonctions. Cela permet d'utiliser ces fonctions dynamiquement via leur index dans le tableau.

---

### Exemple d'Utilisation
Une fois le tableau initialisé, vous pouvez appeler ces fonctions de manière dynamique en utilisant un index :
```cpp
int n = 1; // Choix de la deuxième fonction
std::string target = "TargetName";
AForm* form = Atab[n](target);
```
Ici :
- `Atab[n]` accède à la fonction correspondante dans le tableau (par exemple, `newRobotomyRequestForm`).
- `(target)` appelle cette fonction avec `target` comme paramètre.
- `form` reçoit le pointeur retourné par la fonction appelée.

---

### Avantages
- **Flexibilité** : Vous pouvez sélectionner et appeler une fonction parmi plusieurs avec un simple index.
- **Réduction du Code** : Moins de duplication de code pour gérer plusieurs types similaires de fonctions.
- **Utilisation Dynamique** : Vous pouvez écrire des algorithmes génériques où les fonctions spécifiques à appeler sont décidées à l'exécution.

---

### Illustration Complète
```cpp
AForm* newPresidentialPardonForm(std::string const& target) {
    return new PresidentialPardonForm(target);
}

AForm* newRobotomyRequestForm(std::string const& target) {
    return new RobotomyRequestForm(target);
}

AForm* newShrubberyCreationForm(std::string const& target) {
    return new ShrubberyCreationForm(target);
}

void example() {
    AForm* (*Atab[3])(std::string const&) = {
        newPresidentialPardonForm,
        newRobotomyRequestForm,
        newShrubberyCreationForm
    };

    std::string target = "ExampleTarget";
    int n = 2; // Appelera la troisième fonction
    AForm* form = Atab[n](target); // Appel dynamique
    std::cout << "Form created: " << form->getName() << std::endl;
}
```
