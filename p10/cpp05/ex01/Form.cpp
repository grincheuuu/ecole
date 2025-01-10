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

#include "Form.hpp"

Form::Form(void)
{
    return;
}

Form::Form(std::string name, int minGradeSigned, int minGradeExecute)
{
    return;
}

Form::Form(Form const & src)
{

}

Form::~Form(void)
{

}

Form &  Form::operator=(Form const & rhs)
{

}

std::string const   Form::getName(void) const
{

}

bool                Form::getSigned(void) const
{

}

int const           Form::getMinGradeSigned(void) const
{

}

int const           Form::getMinGradeExecut(void) const
{

}

void                Form::beSigned(Bureaucrat const & a)
{

}

class GradeTooHighException : public std::exception
{
    public:
        virtual const char * what() const throw ();
}

class GradeTooLowException : public std::exception
{
    public:
        virtual const char * what() const throw ();
}