/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:25:08 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/30 11:25:32 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_abs.h"

int main() 
{
    int num = -5;
    int absNum = ABS(num);

    printf("La valeur absolue de %d est %d\n", num, absNum);

    return 0;
}

