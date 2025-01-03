/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:03:47 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/30 17:03:49 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _grade(150)
{
    return;
}

Bureaucrat::Bureaucrat(const std::string & name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->_grade = grade;
    return;
}

Bureaucrat::~Bureaucrat(void)
{
    return;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
    *this = src;
    return;
}

Bureaucrat &    Bureaucrat::operator=(Bureaucrat const & rhs)
{
    if (this != &rhs)
    {
        this->_grade = rhs.getGrade();
    }
    return (*this);
}

std::ostream &  operator<<(std::ostream & o, Bureaucrat const & rhs)
{
    o << rhs.getName() << ", Bureaucrat grade " << rhs.getGrade();
    return (o);
}

std::string const   Bureaucrat::getName(void) const
{
    return (this->_name);
}

int                 Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void    Bureaucrat::incrementGrade(void)
{
    if (this->_grade > 1)
        this->_grade -= 1;
    else
    {
        throw GradeTooHighException();
        this->_grade -= 1;
    }
    return;
}

void    Bureaucrat::decrementGrade(void)
{
    if (this->_grade < 149)
        this->_grade += 1;
    else
    {
        throw GradeTooLowException();
        this->_grade += 1;
    }
    return;
}