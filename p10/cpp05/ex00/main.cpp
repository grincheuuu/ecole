/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:04:07 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/30 17:04:08 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat  John("John", 2);
        std::cout << John.getName() << " " << John.getGrade() << std::endl;
        John.incrementGrade();
        std::cout << John.getName() << " " << John.getGrade() << std::endl;
        John.incrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() <<std::endl;
    }
    return (0);
}
