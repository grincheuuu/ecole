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
        AForm(std::string name, int minGradeSignid, int minGradeExecute);
        AForm(Form const & src);
        ~AForm(void);

        AForm &  operator=(AForm const & rhs);

        std::string const   getName(void) const;
        bool                getSignid(void) const;
        int const           getMinGradeSignid(void) const;
        int const           getMinGradeExecut(void) const;

        void                beSigned(Bureaucrat const & a);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char   *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char  *what() const throw();
        };

    private:
        std::string const   _name;
        bool                _signid;
        int const           _minGradeSignid;
        int const           _minGradeExecut;
};

std::ostream&   operator<<(std::ostream & o, Form const & rhs);
