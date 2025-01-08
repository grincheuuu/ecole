/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:41:52 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/06 14:41:58 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    int i;
    int j;
    char c;

    i = 1;
    c = 0;
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (argv[i] != NULL)
        {
            j = 0;
            if (i > 2)
                std::cout << " ";
            while (argv[i][j] != '\0')
            {
                if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
                    c = toupper(argv[i][j]);
                else
                    c = argv[i][j];
                std::cout << c;
                j++;
            }
            i++;
        }
        std::cout << std::endl;
    }
}