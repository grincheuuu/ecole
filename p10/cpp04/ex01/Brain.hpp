/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:08:30 by gschwart          #+#    #+#             */
/*   Updated: 2024/09/02 18:08:32 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP

# include <iostream>
# include <string>

class Brain
{
    public:
        Brain(void);
        Brain(Brain const & src);
        ~Brain(void);

        Brain &   operator=(Brain const & rhs);

    std::string getIdeas(unsigned int n);

    private:
        std::string _ideas[100];
};

#endif

