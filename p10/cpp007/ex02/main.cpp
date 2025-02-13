/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:24:47 by gschwart          #+#    #+#             */
/*   Updated: 2025/02/03 17:24:48 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 2
int main(int, char**)
{
    Array<int>  numbers(MAX_VAL);
    int*        mirror = new int[MAX_VAL];

    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int   value = rand();

        numbers[i] = value;
        mirror[i] = value;
        std::cout << value << " " << numbers[i] << ":" << mirror[i] << std::endl;
    }
    std::cout << numbers.size() <<std::endl;
    //SCOPE
    {
        Array<int>  tmp = numbers;
        Array<int>  test(tmp);
        std::cout << numbers.size() << " " << tmp.size() << " " << test.size() <<std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
