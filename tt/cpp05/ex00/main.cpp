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
        Bureaucrat  John("john", 2);
        Bureaucrat  Paul("paul", 149);

        std::cout << John.getName() << ", bureaucrat grade " << John << std::endl;
        John.incrementGrade();
        std::cout << John.getName() << ", bureaucrat grade " << John << std::endl;
//        John.incrementGrade();
        std::cout << John.getName() << ", bureaucrat grade " << John << std::endl;
        std::cout << Paul.getName() << ", bureaucrat grade " << Paul << std::endl;
        Paul.decrementGrade();
        std::cout << Paul.getName() << ", bureaucrat grade " << Paul << std::endl;
        Paul.decrementGrade();
        std::cout << Paul.getName() << ", bureaucrat grade " << Paul << std::endl;
    }
    catch(Bureaucrat::GradeTooHighException & e)
    {
        std::cerr << e.what() <<std::endl;
    }
    catch(Bureaucrat::GradeTooLowException & e)
    {
        std::cerr << e.what() <<std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() <<std::endl;
    }

    try
    {
        Bureaucrat  Paul("Paul", 180);

        std::cout << Paul.getName() << ", bureaucrat grade " << Paul << std::endl;
        Paul.decrementGrade();
        std::cout << Paul.getName() << ", bureaucrat grade " << Paul << std::endl;
        Paul.decrementGrade();
        std::cout << Paul.getName() << ", bureaucrat grade " << Paul << std::endl;
    }
    catch(Bureaucrat::GradeTooHighException & e)
    {
        std::cerr << e.what() <<std::endl;
    }
    catch(Bureaucrat::GradeTooLowException & e)
    {
        std::cerr << e.what() <<std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() <<std::endl;
    }

    return (0);
}
