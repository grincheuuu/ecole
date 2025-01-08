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

class Bureaucrat
{
    public:
        Bureaucrat(void);
        Bureaucrat(const std::string & name, int grade);
        Bureaucrat(Bureaucrat const & src);
        ~Bureaucrat(void);

        Bureaucrat &    operator=(Bureaucrat const & rhs);

        std::string const   getName(void) const;

        int                 getGrade(void) const;
        void                incrementGrade(void);
        void                decrementGrade(void);

        class GradeTooHighException : public std::exception
        {
            const char  *what() const throw()
            {
                return ("Bureaucrat::GradeTooHighException");
            }
        };

        class GradeTooLowException : public std::exception
        {
            const char *what() const throw ()
            {
                return ("Bureaucrat::GradeTooLowException");
            }
        };

    private:
        std::string const   _name;
        int                 _grade;
};

std::ostream&   operator<<(std::ostream & o, Bureaucrat const & rhs);
