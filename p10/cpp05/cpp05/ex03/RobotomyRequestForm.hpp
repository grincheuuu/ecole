/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:59:40 by gschwart          #+#    #+#             */
/*   Updated: 2025/01/14 18:59:42 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string.h>
# include <stdexcept>
# include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string const b);
        RobotomyRequestForm(RobotomyRequestForm const & src);
        ~RobotomyRequestForm(void);

        RobotomyRequestForm &    operator=(RobotomyRequestForm const & rhs);

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

std::ostream &   operator<<(std::ostream & o, RobotomyRequestForm const & rhs);

