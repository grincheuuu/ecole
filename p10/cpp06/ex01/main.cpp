/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:30:18 by gschwart          #+#    #+#             */
/*   Updated: 2025/01/30 18:30:20 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer_class.hpp"

int main()
{
    Data    D;

    std::cout << &D << std::endl;
    uintptr_t   b = Serializer::serialize(&D);
    std::cout << b << std::endl;

    Data *  p = Serializer::deserialize(b);
    std::cout << p << std::endl;

    return (0);
}
