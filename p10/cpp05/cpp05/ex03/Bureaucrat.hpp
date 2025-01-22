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
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
    public:
        Bureaucrat(void);
        Bureaucrat(std::string const & name, int grade);
        Bureaucrat(Bureaucrat const & src);
        ~Bureaucrat(void);

        Bureaucrat &    operator=(Bureaucrat const & rhs);

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

        std::string const          getName(void) const;
        int                        getGrade(void) const;

        int                        incrementGrade(void);
        int                        decrementGrade(void);

        void                       signForm(AForm & f) const;
        
        void                       executeForm(AForm const & form) const;

    private:
        std::string const   _name;
        int                 _grade;
};

std::ostream &   operator<<(std::ostream & o, Bureaucrat const & rhs);
