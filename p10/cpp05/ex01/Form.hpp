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

class Bureaucrat;

class   Form
{
    public:
        Form(void);
        Form(std::string name, int minGradeSignid, int minGradeExecute);
        Form(Form const & src);
        ~Form(void);

        Form &  operator=(Form const & rhs);

        std::string const   getName(void) const;
        bool                getSignid(void) const;
        int const           getMinGradeSignid(void) const;
        int const           getMinGradeExecut(void) const;

        void                beSigned(Bureaucrat a) const;

        class GradeTooHighException : public std::exception
        {
            const char  *what() const throw()
            {
                return ("Form::Grade is too high!");
            }
        };

        class GradeTooLowException : public std::exception
        {
            const char *what() const throw ()
            {
                return ("Form::Grade is too low!");
            }
        };

    private:
        std::string const   _name;
        bool                _signid;
        int const           _minGradeSignid;
        int const           _minGradeExecut;
};

std::ostream&   operator<<(std::ostream & o, Form const & rhs);
