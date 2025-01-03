/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:45:07 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/06 15:45:15 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"

class   PhoneBook
{
    public:

        PhoneBook(void);
        ~PhoneBook(void);
        void    addContact();
        int    searchContactList() const;
    
    private:

        Contact _contactList[8];
        int _nb;
        int _max;
};

#endif