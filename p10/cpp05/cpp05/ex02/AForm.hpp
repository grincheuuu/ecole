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

class   AForm
{
    public:
        AForm(void);
        AForm(std::string name, int const minGradeSigned, int const minGradeExecute);
        AForm(AForm const & src);
        virtual ~AForm(void);

        AForm &  operator=(AForm const & rhs);

        std::string const   getName(void) const;
        bool                getSigned(void) const;
        int                 getMinGradeSigned(void) const;
        int                 getMinGradeExecut(void) const;

        void                beSigned(Bureaucrat const & a);

        void                execute(Bureaucrat const & executor) const;

        virtual void                realExecute(int g, std::string n) const = 0;

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

std::ostream &   operator<<(std::ostream & o, AForm const & rhs);
