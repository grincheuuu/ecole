/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:10:54 by gschwart          #+#    #+#             */
/*   Updated: 2024/08/20 20:10:56 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

#define RESET "\e[0m"
#define RED "\e[31m"
#define BLUE "\e[34;1;1m"

bool    bsp(Point const a, Point const b, Point const c, Point const m);

int main(void)
{
    Point const  a (0, 0);
    Point const  b (4.5f, 4.5f);
    Point const  c (0, 5);
    Point const  m (8.1f, 2.1f);

    int i = 0;


    i = bsp(a, b, c, m);
    if (i == 1)
        std::cout << BLUE "the point is in the triangle...." RESET << std::endl;
    else
        std::cout << RED "the point is not in the triangle" RESET << std::endl;

    return 0;
}
