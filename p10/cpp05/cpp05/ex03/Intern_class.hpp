/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern_class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:46:22 by gschwart          #+#    #+#             */
/*   Updated: 2025/01/21 16:46:24 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string.h>
# include <stdexcept>
# include "AForm.hpp"

class Aform;

class Intern
{
    public:
        Intern(void);
        Intern(Intern const & src);
        ~Intern(void);

        Intern &    operator=(Intern const & rhs);

        AForm*        makeForm(std::string const a, std::string const & b);
        AForm*        createForm(int n, std::string const & b);

        class InternFormDoesntExistException : public std::exception
        {
            public:
                virtual const char * what () const throw ();
        };
};

AForm *         newRobotomyRequestForm(std::string const & b);
AForm *         newPresidentialPardonForm(std::string const & b);
AForm*          newShrubberyCreationForm(std::string const & b);
