/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:31:43 by gschwart          #+#    #+#             */
/*   Updated: 2024/10/03 19:31:44 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("unknow"), _signed(0), _minGradeSigned(1), _minGradeExecut(1)
{
//    std::cout << "default constructor called " << _name << std::endl;
    return;
}

AForm::AForm(std::string name, int const minGradeSigned, int const minGradeExecute) : _name(name), _signed(0), _minGradeSigned(minGradeSigned), _minGradeExecut(minGradeExecute)
{
//    std::cout << "default assignement constructor called " << _name << std::endl;
    if (minGradeSigned < 1 || minGradeExecute < 1)
        throw GradeTooHighException();
    if (minGradeSigned > 150 || minGradeExecute > 150)
        throw GradeTooLowException();
    return;
}

AForm::AForm(AForm const & src) : _name(src._name), _signed(0), _minGradeSigned(src._minGradeSigned), _minGradeExecut(src._minGradeExecut)
{
//    std::cout << "copy constructor called " << _name << std::endl;
    *this = src;
    return;
}

AForm::~AForm(void)
{
//    std::cout << "destructor called " << _name << std::endl;
    return;
}

AForm &  AForm::operator=(AForm const & rhs)
{
//    std::cout << "operator = called " << _name << std::endl;
    if (this->_signed != rhs.getSigned())
    {
        this->_signed = rhs.getSigned();
    }
    return *this;
}

std::string const   AForm::getName(void) const
{
    return this->_name;
}

bool                AForm::getSigned(void) const
{
    return this->_signed;
}

int          AForm::getMinGradeSigned(void) const
{
    return this->_minGradeSigned;
}

int        AForm::getMinGradeExecut(void) const
{
    return this->_minGradeExecut;
}

void                AForm::beSigned(Bureaucrat const & a)
{
    if (this->_signed != 1)
    {
        if (a.getGrade() <= this->_minGradeSigned)
        {
            this->_signed = 1;
        }
        else
        {
            throw AForm::GradeTooLowException();
        }
    }
    else
    {
        std::cout << a.getName() << " as already signedAForm " << _name << std::endl;
    }
    return;
}

const char *        AForm::GradeTooHighException::what () const throw()
{
    return ("AForm grade too High Exception");
}

const char *        AForm::GradeTooLowException::what () const throw ()
{
    return ("AForm grade too Low Exception");
}

std::ostream &   operator<<(std::ostream & o, AForm const & rhs)
{
    o  << " AForm " << rhs.getName() << " sign=" << rhs.getSigned()<< " MinGradeSigned " << rhs.getMinGradeSigned() << " MinGradeExecute " << rhs.getMinGradeExecut();
    return o;
}

void                AForm::execute(Bureaucrat const & executor) const
{
    realExecute(executor.getGrade(), executor.getName()); 
}