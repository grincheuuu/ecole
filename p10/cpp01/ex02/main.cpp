/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:02:21 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/15 15:02:29 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *PTR = &str;
    std::string &REF = str;

    std::cout << "str adresse : " << &str << std::endl;
    std::cout << "PTR adresse : " << PTR << std::endl;
    std::cout << "REF adresse : " << &REF << std::endl;

    std::cout << "str value : " << str << std::endl;
    std::cout << "PTR value : " << *PTR << std::endl;
    std::cout << "REF value : " << REF << std::endl; 
    return (0);
}

