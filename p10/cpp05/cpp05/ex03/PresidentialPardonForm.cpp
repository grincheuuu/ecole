/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:59:20 by gschwart          #+#    #+#             */
/*   Updated: 2025/01/14 18:59:22 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "fstream"
#include <string>

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("pardon", 25, 5), _target("unnknow")
{
    std::cout << "default constructor called" << std::endl;
    return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const b) : AForm("PresidentialPardon", 25, 5), _target(b)
{
    std::cout << "default assig constructor called" << std::endl;
    return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src), _target(src._target)
{
    std::cout << "copy constructor called" << std::endl;
    *this = src;
    return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "destructor called" << std::endl;
    return;
}

PresidentialPardonForm &    PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
    std::cout << "operator = called" << std::endl;
    if (this != &rhs)
    {
        AForm::operator=(rhs);
    }
    return (*this);
}

std::string const       PresidentialPardonForm::getTarget(void) const
{
    return _target;
}

void                PresidentialPardonForm::realExecute(int g, std::string n) const
{
    (void)n;
    if (AForm::getSigned() == 1)
    {
        if (g <= 5)
        {
            std::cout << "Bureaucrat target " << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;            
        }
        else
        {
            std::cout << "Bureaucrat target " << _target << " can't execute PresidentialPardonForm" << std::endl;
            throw PresidentialPardonForm::GradeTooLowException();
        }
    }
    else
    {
        std::cout << "Bureaucrat target " << _target << " haven't signed form for PresidentialPardonForm" << std::endl;
        throw PresidentialPardonForm::IsSignedException();
    }
}

const char *    PresidentialPardonForm::GradeTooLowException::what () const throw ()
{
    return ("PresidentialPardonForm grade too Low Exception");
}

const char *    PresidentialPardonForm::GradeTooHighException::what () const throw ()
{
    return ("PresidentialPardonForm grade too High Exception");
}

const char *    PresidentialPardonForm::IsSignedException::what () const throw ()
{
    return ("PresidentialPardonForm Form non sign Exception");
}
std::ostream &   operator<<(std::ostream & o, PresidentialPardonForm const & rhs)
{
    o << rhs.getTarget();
    return o;
}

