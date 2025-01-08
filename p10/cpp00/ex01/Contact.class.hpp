/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:47:59 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/06 15:48:01 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>

class Contact
{
    public:

        Contact(void);
        ~Contact(void);

        std::string const   getfirst_name(void) const;
        std::string const   getlast_name(void) const;
        std::string const   getnickname(void) const;
        std::string const   getphone_number(void) const;
        std::string const   getdarkest_secret(void) const;

        void    setfirst_name(std::string& _first_name);
        void    setlast_name(std::string& _last_name);
        void    setnickname(std::string& _nickname);
        void    setphone_number(std::string& _phone_number);
        void    setdarkest_secret(std::string& _darkest_secret);

    private:

        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;
};

#endif