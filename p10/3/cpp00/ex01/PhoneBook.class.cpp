/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:08:18 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/06 15:08:24 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

#include <iostream>
#include <string>
#include <iomanip>

PhoneBook::PhoneBook(void) : _nb(0), _max(0)
{
    return ;
}

PhoneBook::~PhoneBook(void)
{
    return;
}

void    PhoneBook::addContact(void)
{
    std::string first_name, last_name, nickname, phone_number, darkest_secret;
    int n = 0;

    if (_nb >= 8)
        _nb = 0;
    std::cout << "please enter the first name : " << std::endl;
    std::getline(std::cin, first_name);
    std::cout << "please enter the last name : " << std::endl;
    std::getline(std::cin, last_name);
    std::cout << "please enter the nickname : " << std::endl;
    std::getline(std::cin, nickname);
    std::cout << "please enter the phone number : " << std::endl;
    std::getline(std::cin, phone_number);
    std::cout << "please enter the darkest secret : " << std::endl;
    std::getline(std::cin, darkest_secret);

    if (first_name.empty() == 1 || last_name.empty() == 1 || nickname.empty() == 1
        || phone_number.empty() == 1 || darkest_secret.empty() == 1)
    {
        std::cout << "the contact is not register ..............." << std::endl;
        std::cout << "you must complete all case !!!" << std::endl;
        return;
    }
/*    n = first_name.size();
    if (n > 10)
    {
        first_name.erase (first_name.begin()+8, first_name.end() - 1);
        first_name = first_name.substr(0, 9) + ".";
    }*/
    _contactList[_nb].setfirst_name(first_name);
/*    n = last_name.size();
    if (n > 10)
    {
        last_name.erase (last_name.begin()+8, last_name.end() - 1);
        last_name = last_name.substr(0, 9) + ".";
    }*/
    _contactList[_nb].setlast_name(last_name);
/*    n = nickname.size();
    if (n > 10)
    {
        nickname.erase (nickname.begin()+8, nickname.end() - 1);
        nickname = nickname + ".";
    }*/
    _contactList[_nb].setnickname(nickname);
    _contactList[_nb].setphone_number(phone_number);
    _contactList[_nb].setdarkest_secret(darkest_secret);

    _nb++;
    _max++;
}

int    isint(std::string& chr)
{
    if (chr.empty() == 1)
        return (2);
    std::string::iterator it = chr.begin();
    while (it!=chr.end())
    {
        if (!(*it >= '0' && *it <= '9'))
        {
            if (chr == "EXIT")
                return (1);
            else
                return (2);
        }
        it++;
    }
    return (0);
}

std::string  limitedstr(std::string str)
{
    int n = 0;

    n = str.size();
    if (n > 10)
    {
        str.erase (str.begin()+8, str.end() - 1);
        str = str.substr(0, 9) + ".";
    }
    return (str);
}

int    PhoneBook::searchContactList(void) const
{
    int nb;
    int i = 0;

    std::cout << "*********************************************" << std::endl;
    std::cout << "************CONTACTS LIST********************" << std::endl;
    std::cout << "*********************************************" << std::endl;
    std::cout << "|";
    std::cout << "     index";
    std::cout << "|";
    std::cout << "first name";
    std::cout << "|";
    std::cout << " last name";
    std::cout << "|";
    std::cout << "  nickname";
    std::cout << "|" << std::endl;

    while (i < 8 && i < _max)
    {
        std::string fname,lname, nname;

        std::cout << "|";
        std::cout << "         " << i + 1;
        std::cout << "|";
        fname = limitedstr(_contactList[i].getfirst_name());
        std::cout << std::setw(10) << fname;
        std::cout << "|";
        lname = limitedstr(_contactList[i].getlast_name());
        std::cout << std::setw(10) << lname;
        std::cout << "|";
        nname = limitedstr(_contactList[i].getnickname());
        std::cout << std::setw(10) << nname;
        std::cout << "|" << std::endl;
        i++;
    }
    std::cout << "*********************************************" << std::endl;

    std::cout << "please enter the index of a contact : ";
    std::string chr;
    std::getline (std::cin, chr);
    if (isint(chr) == 1)
        return (1);
    else if (isint(chr) == 2)
        return (0);
    nb = std::stoi(chr, 0);
    if (nb == 0 || nb > 8)
    {
        std::cout << "the index number is between 1 and 8" << std::endl;
        return (0);
    }
    std::cout << "*********************************************" << std::endl;
    std::cout << "First Name : " << _contactList[nb - 1].getfirst_name() << std::endl;;
    std::cout << "Last Name : " << _contactList[nb - 1].getlast_name() << std::endl;;
    std::cout << "Nickname : " << _contactList[nb - 1].getnickname() << std::endl;;
    std::cout << "Phone number : " << _contactList[nb - 1].getphone_number() << std::endl;;
    std::cout << "darkest secret : " << _contactList[nb - 1].getdarkest_secret() << std::endl;;
    std::cout << "*********************************************" << std::endl;
    return (0);
}