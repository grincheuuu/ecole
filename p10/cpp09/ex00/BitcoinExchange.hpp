/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:58:00 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/14 18:58:01 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string.h>
# include <ctype.h>
# include <fstream>
# include <map>
# include <string>
# include <cstdlib>
# include <sstream>
# include <iomanip>

class BitCoinExchange
{
    public:
        static int                              isInt(std::string ligne);
        static int                              isFloat(std::string ligne);
        static int                              ft_date(std::string ligne);
        static int                              ft_date_deux(std::string ligne);
        static int                              ft_pars_ligne(std::string ligne);
        static std::map<std::string, double>    ft_csv(std::string str);
        static std::string                      ft_to_string(int str);
        static void                             ft_compare(std::multimap<std::string, double> tab, std::map<std::string, double> csv);

    private:
        BitCoinExchange(void);
        BitCoinExchange(BitCoinExchange const & src);
        ~BitCoinExchange(void);

        BitCoinExchange &       operator=(BitCoinExchange const & rhs);
};

#endif
