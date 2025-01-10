/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:31:50 by gschwart          #+#    #+#             */
/*   Updated: 2024/10/03 19:31:51 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class   Form
{
    public:
        Form(void);
        Form(std::string name, int minGradeSigned, int minGradeExecute);
        Form(Form const & src);
        ~Form(void);

        Form &  operator=(Form const & rhs);

        std::string const   getName(void) const;
        bool                getSigned(void) const;
        int const           getMinGradeSigned(void) const;
        int const           getMinGradeExecut(void) const;

        void                beSigned(Bureaucrat const & a);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char * what() const throw ();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char * what() const throw ();
        };

    private:
        std::string const   _name;
        bool                _signed;
        int const           _minGradeSigned;
        int const           _minGradeExecut;
};

std::ostream &   operator<<(std::ostream & o, Bureaucrat const & rhs);
