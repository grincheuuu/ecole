/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:15:36 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/06 16:15:40 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

int main(void)
{
    PhoneBook   list;
    std::string str;
    	
    while (true)
    {
    	if (std::cin.eof())
    		break;
        std::cout << "Veuillez tapez : ADD, SEARCH or EXIT" << std::endl;
        std::getline (std::cin, str);
        if (str == "ADD")
            list.addContact();
        else if (str == "SEARCH")
        {
            if (list.searchContactList() == 1)
                break;
        }
        else if (str == "EXIT")
            break;
    }
    return (0);
}
