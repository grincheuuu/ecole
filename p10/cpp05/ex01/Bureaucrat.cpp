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

Bureaucrat::Bureaucrat(void) : _name("unknow"), _grade(150)
{
    std::cout << "default constructor called" << std::endl;
    return;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name), _grade(grade)
{
    std::cout << "default assignement constructor called" << std::endl;
    if (this->_grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
        this->_grade = 1;
    }
    if (this->_grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
        this->_grade = 150;
    }
    return;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
    std::cout << "copy constructor called" << std::endl;
    *this = src;
    return;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "destructor \\ called" << std::endl;
    return;
}

Bureaucrat &    Bureaucrat::operator=(Bureaucrat const & rhs)
{
    std::cout << "operator = called" << std::endl;
    if (this != &rhs)
    {
        this->_grade = rhs.getGrade();
    }
    return *this;
}


std::string const          Bureaucrat::getName(void) const
{
    return this->_name;
}

int                        Bureaucrat::getGrade(void) const
{
    return this->_grade;
}

int                        Bureaucrat::incrementGrade(void)
{
    if (this->_grade < 2)
    {
        throw Bureaucrat::GradeTooHighException();
        this->_grade = 1;
    }
    else
        this->_grade -= 1;
    return this->_grade;
}

int                        Bureaucrat::decrementGrade(void)
{
    if (this->_grade > 149)
    {
        throw Bureaucrat::GradeTooLowException();
        this->_grade = 150;
    }
    else
        this->_grade += 1;
    return this->_grade;
}

std::ostream &   operator<<(std::ostream & o, Bureaucrat const & rhs)
{
    o << rhs.getGrade();
    return o;
}

const char *        Bureaucrat::GradeTooHighException::what() const throw()
{
    return "grade too high";
}

const char *        Bureaucrat::GradeTooLowException::what() const throw ()
{
    return "grade too low";
}