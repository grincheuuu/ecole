/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:06:08 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/14 17:06:10 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
    MutantStack<int>    mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << " ";

    mstack.pop();
    std::cout << mstack.size() << " ";

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    //[...]

    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "\n";

    std::list<int>    lstack;

    lstack.push_back(5);
    lstack.push_back(17);

    std::cout << lstack.back() << " ";

    lstack.pop_back();
    std::cout << lstack.size() <<  " ";

    lstack.push_back(3);
    lstack.push_back(5);
    lstack.push_back(737);


    lstack.push_back(0);
    std::list<int>::iterator lit = lstack.begin();
    std::list<int>::iterator lite = lstack.end();

    ++lit;
    --lit;
    
    while (lit != lite)
    {
        std::cout << *lit << " ";
        ++lit;
    }
    std::list<int>     ls(lstack);
    std::cout << std::endl;
    return 0;
}
