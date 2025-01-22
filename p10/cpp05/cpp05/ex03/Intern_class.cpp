/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern_class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:46:34 by gschwart          #+#    #+#             */
/*   Updated: 2025/01/21 16:46:36 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern_class.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
    std::cout << "default constructor I called" << std::endl;
    return;
}

Intern::Intern(Intern const & src)
{
    std::cout << "copy constructor I called" << std::endl;
    *this = src;
    return;
}

Intern::~Intern(void)
{
    std::cout << "destructeur I called" << std::endl;
    return;
}

Intern &    Intern::operator=(Intern const & rhs)
{
    std::cout << "operator = I called" << std::endl;
    (void)rhs;
    return *this;
}

AForm *         newPresidentialPardonForm(std::string const & b)
{
    return (new PresidentialPardonForm(b));
}

AForm *         newRobotomyRequestForm(std::string const & b)
{
    return (new RobotomyRequestForm(b));
}

AForm*          newShrubberyCreationForm(std::string const & b)
{
    return (new ShrubberyCreationForm(b));
}

AForm*        Intern::createForm(int n, std::string const & b)
{
    AForm*      (*Atab[3])(std::string const &) = {newPresidentialPardonForm, newRobotomyRequestForm, newShrubberyCreationForm};

    if (n < 0 || n > 2)
        return NULL;
    return (Atab[n](b));
}

const char *    Intern::InternFormDoesntExistException::what () const throw ()
{
   return ("Intern can't creates form, name doesn't exist");
};

AForm*        Intern::makeForm(std::string const a, std::string const & b)
{
    std::string        tab[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    int                i = 0;
    while (i < 3)
    {
        if (tab[i] == a)
        {
            AForm *      Formm = createForm(i, b);
            std::cout << "Intern creates " << *Formm << std::endl;
            return (Formm);
        }
        i++;
    }
    throw Intern::InternFormDoesntExistException();
    return NULL;
}