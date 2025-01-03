/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:47:59 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/06 15:48:01 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include <iostream>

Contact::Contact(void) : _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret("")
{
    return;
}

void Contact::setfirst_name(std::string& _first_name)
{
    this->_first_name = _first_name;
}

void Contact::setlast_name(std::string& _last_name)
{
    this->_last_name = _last_name;
}

void Contact::setnickname(std::string& _nickname)
{
    this->_nickname = _nickname;
}

void Contact::setphone_number(std::string& _phone_number)
{
    this->_phone_number = _phone_number;
}

void Contact::setdarkest_secret(std::string& _darkest_secret)
{
    this->_darkest_secret = _darkest_secret;
}

std::string const   Contact::getfirst_name(void) const
{
    return (this->_first_name);
}

std::string const   Contact::getlast_name(void) const
{
    return (this->_last_name);
}

std::string const   Contact::getnickname(void) const
{
    return (this->_nickname);
}

std::string const   Contact::getphone_number(void) const
{
    return (this->_phone_number);
}

std::string const   Contact::getdarkest_secret(void) const
{
    return (this->_darkest_secret);
}


Contact::~Contact(void)
{
    return;
}
