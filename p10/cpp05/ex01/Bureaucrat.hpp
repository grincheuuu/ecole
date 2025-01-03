/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:03:57 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/30 17:03:59 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string.h>
# include <stdexcept>
# include "Form.hpp"

class Form;

class Bureaucrat
{
    public:
        Bureaucrat(const std::string & name, int grade);
        Bureaucrat(Bureaucrat const & src);
        ~Bureaucrat(void);

        Bureaucrat &    operator=(Bureaucrat const & rhs);

        std::string const   getName(void) const;

        int                 getGrade(void) const;
        void                incrementGrade(void);
        void                decrementGrade(void);

        void                SigneForm(Form & f);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw ();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

/*        class GradeTooHighException : public std::exception
        {
            const char  *what() const throw()
            {
                return ("Bureaucrat:Grade is too high!");
            }
        };

        class GradeTooLowException : public std::exception
        {
            const char *what() const throw ()
            {
                return ("Bureaucrat:Grade is too low!");
            }
        };*/

    private:
        std::string const   _name;
        int                 _grade;
};

std::ostream&   operator<<(std::ostream & o, Bureaucrat const & rhs);
