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
#include "Form.hpp"

int main(void)
{
    try
    {
        Bureaucrat  John("john", 1);
        Bureaucrat  Paul("paul", 149);
        Form        d1("dell", 100, 100);
        Form        d2("optiflex", 1, 1);
        Form        d3("optiflexxxxxxxx", 150, 150);

        std::cout << John.getName() << ", bureaucrat grade " << John << std::endl;
        John.signForm(d1);
        std::cout << Paul.getName() << ", bureaucrat grade " << Paul << std::endl;
        Paul.signForm(d2);
        John.signForm(d2);
        John.signForm(d2);
    }
    catch(Bureaucrat::GradeTooHighException & e)
    {
        std::cerr << e.what() <<std::endl;
    }
    catch(Bureaucrat::GradeTooLowException & e)
    {
        std::cerr << e.what() <<std::endl;
    }
    catch(Form::GradeTooHighException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(Form::GradeTooLowException& e)
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
        Bureaucrat  Paul("Paul", 100);
        Form        d1("dell", 100, 100);
        Form        d2("optiflex", 1, 0);

        std::cout << Paul.getName() << ", bureaucrat grade " << Paul << std::endl;
        Paul.decrementGrade();
        d1.beSigned(Paul);
    }
    catch(Bureaucrat::GradeTooHighException & e)
    {
        std::cerr << e.what() <<std::endl;
    }
    catch(Bureaucrat::GradeTooLowException & e)
    {
        std::cerr << e.what() <<std::endl;
    }
    catch(Form::GradeTooHighException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(Form::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() <<std::endl;
    }

    return (0);
}
