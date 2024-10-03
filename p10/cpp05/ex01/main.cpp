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
        Bureaucrat  Paul("Paul", 149);

        std::cout << John.getName() << " grade " << John.getGrade() << std::endl;
        John.incrementGrade();
        std::cout << John.getName() << " grade " << John.getGrade() << std::endl;
        John.incrementGrade();
        std::cout << Paul.getName() << " grade " << Paul.getGrade() << std::endl;
        Paul.decrementGrade();
        std::cout << Paul.getName() << " grade " << Paul.getGrade() << std::endl;
        Paul.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() <<std::endl;
    }

    try
    {
        Bureaucrat  Paul("Paul", 149);

        std::cout << Paul.getName() << " grade " << Paul.getGrade() << std::endl;
        Paul.decrementGrade();
        std::cout << Paul.getName() << " grade " << Paul.getGrade() << std::endl;
        Paul.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() <<std::endl;
    }
    std::cout << "Ste " << std::endl;
    try
    {
        Bureaucrat  Ste("ste", 151);

        std::cout << Ste.getName() << " grade " << Ste.getGrade() << std::endl;
        Ste.incrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() <<std::endl;
    }
    return (0);
}
