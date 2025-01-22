/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:00:36 by gschwart          #+#    #+#             */
/*   Updated: 2025/01/14 19:00:38 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string.h>
# include <stdexcept>
# include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string const b);
        PresidentialPardonForm(PresidentialPardonForm const & src);
        ~PresidentialPardonForm(void);

        PresidentialPardonForm &    operator=(PresidentialPardonForm const & rhs);

        void                realExecute(int g, std::string n) const;

        std::string const       getTarget(void) const;

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
        class IsSignedException : public std::exception
        {
            public:
                virtual const char * what() const throw ();
        };
    
    private:
        std::string const      _target;
};

std::ostream &   operator<<(std::ostream & o, PresidentialPardonForm const & rhs);