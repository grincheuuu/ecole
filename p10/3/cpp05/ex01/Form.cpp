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

Form::Form(void) : _signid(0)
{
    return;
}

Form::Form(std::string name, int minGradeSignid, int minGradeExecute) : _name(name), _minGradeSignid(minGradeSignid), _minGradeExecut(minGradeExecute)
{
    return;
}

Form::Form(Form const & src)
Form::~Form(void)

Form &  Form::operator=(Form const & rhs)

std::string const   Form::getName(void) const
bool                Form::getSignid(void) const
int const           Form::getMinGradeSignid(void) const
int const           Form::getMinGradeExecut(void) const

void                Form::beSigned(Bureaucrat a) const
