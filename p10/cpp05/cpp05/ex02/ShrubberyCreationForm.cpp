/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:00:11 by gschwart          #+#    #+#             */
/*   Updated: 2025/01/14 19:00:12 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("trees", 145, 137), _target("unnknow")
{
    std::cout << "default constructor called" << std::endl;
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const b) : AForm("trees", 145, 137), _target(b)
{
    std::cout << "default assig constructor called" << std::endl;
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src), _target(src._target)
{
    std::cout << "copy constructor called" << std::endl;
    *this = src;
    return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "destructor called" << std::endl;
    return;
}

ShrubberyCreationForm &    ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
    std::cout << "operator = called" << std::endl;
    if (this != &rhs)
    {
        AForm::operator=(rhs);
    }
    return (*this);
}

std::string const       ShrubberyCreationForm::getTarget(void) const
{
    return _target;
}

void                ShrubberyCreationForm::realExecute(int g, std::string n) const
{
    if (AForm::getSigned() == 1)
    {
        if (g <= 137)
        {
            std::string     name;
            name = n + "_shrubbery";
            std::ofstream    ofs(name.c_str());
            int  i = 0;
            int  j = 10;
            int  w = 0;
            int  t = 0;
            int  z = 1;
            while (i < 10)
            {
                std::string temp;
                t = 0;
                while (t < j)
                {
                    if (t == 10 - w)
                        temp += '|';
                    else
                        temp += " ";
                    t++;
                }
                if (t == j)
                    temp += '|';
                z++;
                t++;
                ofs << temp << std::endl;
                i++;
                j++;
                w++;
            }
            t = 0;
            std::string temp;
            while (t < j)
            {
                temp += "|";
                t++;
            }
            ofs << temp << std::endl;
            i++;
            while (i < 15)
            {
                std::string temp;
                t = 0;
                while (t < (j / 2 + 3))
                {
                    if (t <= (j / 2 - 3))
                        temp += " ";
                    else
                        temp += "|";
                    t++;
                }
                ofs << temp << std::endl;
                i++;
            }
            ofs.close();
        }
        else
        {
            std::cout << "Bureaucrat target " << _target << " can't execute ShrubberyCreationForm" << std::endl;
            throw ShrubberyCreationForm::GradeTooLowException();
        }
    }
    else
    {
        std::cout << "Bureaucrat target " << _target << " haven't signed form for ShrubberyCreationForm" << std::endl;
        throw ShrubberyCreationForm::IsSignedException();
    }
}

const char *    ShrubberyCreationForm::GradeTooLowException::what () const throw ()
{
    return ("ShrubberyCreationForm grade too Low Exception");
}

const char *    ShrubberyCreationForm::GradeTooHighException::what () const throw ()
{
    return ("ShrubberyCreationForm grade too High Exception");
}

const char *    ShrubberyCreationForm::IsSignedException::what () const throw ()
{
    return ("ShrubberyCreationForm Form non sign Exception");
}

std::ostream &   operator<<(std::ostream & o, ShrubberyCreationForm const & rhs)
{
    o << rhs.getTarget();
    return o;
}

