/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer_class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:30:42 by gschwart          #+#    #+#             */
/*   Updated: 2025/01/30 18:30:44 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer_class.hpp"

Serializer::Serializer(void)
{
}

Serializer::Serializer(Serializer const & src)
{
    *this = src;
    return;
}

Serializer::~Serializer(void)
{
}

Serializer  Serializer::operator=(Serializer const & rhs)
{
    if (this != &rhs)
        *this = rhs;
    return *this;
}

uintptr_t   Serializer::serialize(Data* ptr)
{
    uintptr_t   p = reinterpret_cast<uintptr_t>(ptr);
    return p;
}

Data *      Serializer::deserialize(uintptr_t raw)
{
    Data *  d = reinterpret_cast<Data *>(raw);
    return d;
}
