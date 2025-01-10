/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:31:43 by gschwart          #+#    #+#             */
/*   Updated: 2024/10/03 19:31:44 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

Form::Form(std::string name, int minGradeSignid, int minGradeExecute) : _signid(0), _name(name), _minGradeSignid(minGradeSignid), _minGradeExecut(minGradeExecute)
{
    if (minGradeSignid > 150)
        throw GradeTooLowException();
    else if (minGradeSignid < 1)
        throw GradeTooHighException();
    if (minGradeExecute > 150)
        throw GradeTooLowException();
    else if (minGradeExecute < 1)
        throw GradeTooHighException();
    return;
}

Form::Form(Form const & src) :  _name(src._name), _minGradeSignid(src._minGradeSignid), _minGradeExecut(src._minGradeExecut)
{
    *this = src;
    return;
}

Form::~Form(void)
{
    return;
}

Form &  Form::operator=(Form const & rhs)
{
    if (this != &rhs)
    {
        std::cout << "constructeur copy error" << std::endl;
    }
    return (*this);
}

std::string const   Form::getName(void) const
{
    return (this->_name);
}

bool                Form::getSignid(void) const
{
    return (this->_signid);
}

int const           Form::getMinGradeSignid(void) const
{
    return (this->_minGradeSignid);
}

int const           Form::getMinGradeExecut(void) const
{
    return (this->_minGradeExecut);
}

void                Form::beSigned(Bureaucrat const & a)
{
    if (a.getGrade() <= _minGradeSignid)
        this->_signid = 1;
    else
        throw GradeTooLowException();
    return;
}

const char* Form::GradeTooHighException::what(void) const throw ()
{
    return ("Form::Grade is too high!");
}

const char* Form::GradeTooLowException::what(void) const throw ()
{
    return ("Form::GradeTooLowException");
}

std::ostream&   operator<<(std::ostream & o, Form const & rhs)
{
    o << "Form Name: " << rhs.getName() << " it is signed: " << rhs.getSignid() << " minGrade sign: ";
    o << rhs.getMinGradeSignid() << " minGradeExecute: " << rhs.getMinGradeExecut() << std::endl;
    return (o);
}
