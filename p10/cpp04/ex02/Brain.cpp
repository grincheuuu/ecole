/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:08:40 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/02 18:08:42 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    int i = 0;

    while (i < 100)
    {
        if (i % 2 == 0)
            _ideas[i] = "aaaMiAMaa";
        else
            _ideas[i] = "MiAmaaaaa";
        i++;
    }
    std::cout << "Default constructor Brain call" << std::endl;
    return;
}

Brain::Brain(Brain const & src)
{
    std::cout << "Copy constructor Brain call" << std::endl;
    *this = src;
    return;
}

Brain &   Brain::operator=(Brain const & rhs)
{
    unsigned int    n = 0;
    if (this != &rhs)
    {
        while (n < 100)
        {
            this->_ideas[n] = rhs._ideas[n];
            n++;
        }
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Destructor Brain call" << std::endl;
}

std::string Brain::getIdeas(unsigned int n)
{
    if (n > 99)
    {
        std::cout << "there are only 100 ideas, n is between 0-99" << std::endl;
        return (NULL);
    }
    return (this->_ideas[n]);
}


