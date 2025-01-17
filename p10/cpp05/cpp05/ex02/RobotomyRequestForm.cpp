/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:59:52 by gschwart          #+#    #+#             */
/*   Updated: 2025/01/14 18:59:54 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "fstream"
#include <string>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("robot", 72, 45), _target("unnknow")
{
    std::cout << "default constructor called" << std::endl;
    return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const b) : AForm("robot", 72, 45), _target(b)
{
    std::cout << "default assig constructor called" << std::endl;
    return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src), _target(src._target)
{
    std::cout << "copy constructor called" << std::endl;
    *this = src;
    return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "destructor called" << std::endl;
    return;
}

RobotomyRequestForm &    RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
    std::cout << "operator = called" << std::endl;
    if (this != &rhs)
    {
        AForm::operator=(rhs);
    }
    return (*this);
}

void                RobotomyRequestForm::realExecute(int g, std::string n) const
{
    (void)n;
    if (AForm::getSigned() == 1)
    {
        if (g <= 45)
        {
            if (rand() % 2 == 0)
                std::cout << "VRRRRRRRRRRRRRRRRRRRRRRRR target " << _target << " has been robotomized successfull" << std::endl;
            else
                std::cout << "VRRRRRRRRRRRRRRRRRRRRRRRR target " << _target << " the robotomy failed" << std::endl;
        }
        else
        {
            std::cout << "Bureaucrat target " << _target << " can't execute RobotomyRequestForm" << std::endl;
            throw RobotomyRequestForm::GradeTooLowException();
        }
    }
    else
    {
        std::cout << "Bureaucrat target " << _target << " haven't signed form for RobotomyRequestForm" << std::endl;
        throw RobotomyRequestForm::IsSignedException();
    }
}

std::string const       RobotomyRequestForm::getTarget(void) const
{
    return _target;
}

const char *    RobotomyRequestForm::GradeTooLowException::what () const throw ()
{
    return ("RobotomyRequestForm grade too Low Exception");
}

const char *    RobotomyRequestForm::GradeTooHighException::what () const throw ()
{
    return ("RobotomyRequestForm grade too High Exception");
}

const char *    RobotomyRequestForm::IsSignedException::what () const throw ()
{
    return ("RobotomyRequestForm Form non sign Exception");
}
std::ostream &   operator<<(std::ostream & o, RobotomyRequestForm const & rhs)
{
    o << rhs.getTarget();
    return o;
}