/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer_class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:30:58 by gschwart          #+#    #+#             */
/*   Updated: 2025/01/30 18:31:00 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>

struct Data
{
    int nb;
};

class Serializer
{
    public:
        static uintptr_t   serialize(Data* ptr);
/*uintptr_t est un type d'entier non signé, de sorte que toute valeur valide (void *) peut être convertie
 dans ce type, puis reconvertie.  Il est capable de stocker des valeurs dans l'intervalle [0,
 INTPTR_MAX].
*/
        static Data *      deserialize(uintptr_t raw);

    private:
        Serializer(void);
        Serializer(Serializer const & src);
        ~Serializer(void);

        Serializer  operator=(Serializer const & rhs);
};
