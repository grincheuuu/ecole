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
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat  John("john", 1);
        Bureaucrat  Paul("paul", 75);
        ShrubberyCreationForm        d1("home");
        RobotomyRequestForm        d2("optiflex");
        PresidentialPardonForm        d3("moi");

        std::cout << John.getName() << ", bureaucrat grade " << John << std::endl;
        John.signForm(d1);
        John.executeForm(d1);
        John.signForm(d2);
        John.executeForm(d2);
        John.signForm(d3);
        John.executeForm(d3);
        std::cout << std::endl;
        std::cout << Paul.getName() << ", bureaucrat grade " << Paul << std::endl;
        Paul.signForm(d2);
        Paul.executeForm(d2);
    }
    catch(Bureaucrat::GradeTooHighException & e)
    {
        std::cerr << e.what() <<std::endl;
    }
    catch(Bureaucrat::GradeTooLowException & e)
    {
        std::cerr << e.what() <<std::endl;
    }
    catch(AForm::GradeTooHighException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(AForm::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() <<std::endl;
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat  John("Paul", 6);
        ShrubberyCreationForm        d1("home");
        RobotomyRequestForm        d2("optiflex");
        PresidentialPardonForm        d3("moi");

        std::cout << John.getName() << ", bureaucrat grade " << John << std::endl;
        John.signForm(d1);
        John.executeForm(d1);
        John.signForm(d2);
        John.executeForm(d2);
        John.signForm(d3);
        John.executeForm(d3);
    }
    catch(Bureaucrat::GradeTooHighException & e)
    {
        std::cerr << e.what() <<std::endl;
    }
    catch(Bureaucrat::GradeTooLowException & e)
    {
        std::cerr << e.what() <<std::endl;
    }
    catch(AForm::GradeTooHighException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(AForm::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() <<std::endl;
    }

    return (0);
}
