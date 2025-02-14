#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <algorithm>

class IOperation;

void    displayInt(int i)
{
    std::cout << i << std::endl;
}

int main(void)
{
    std::list<int>                          lst1; //list de int
    std::map<std::string, IOperation*>      map1; // map de IOperation indexer sur des strings
    std::vector<int>                        v1; // tableau de ce que l'on veut
    std::vector<int>                        v2(42, 100); // ici tableau de 42 cases qui vont contenir 100

    lst1.push_back(1);
    lst1.push_back(17);
    lst1.push_back(42);

    for_each(lst1.begin(), lst1.end(), displayInt); // algorithm pour chaque element de la list on applique la fonction

//    map1["A"] = new OperationA; // index et IOperation
//    map1["B"] = new OperationB;

    std::list<int>::const_iterator      it; // dans une list vide je cree un const iterator
    std::list<int>::const_iterator      ite = lst1.end();

    for (it = lst1.begin(); it != ite; ++it)
    {
        std::cout << *it << std::endl;
    }

    return (0);
}