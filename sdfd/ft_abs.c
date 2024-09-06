/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:48:23 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/27 14:57:52 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define ABS(Value) (((Value) < 0) ? -(Value) : (Value))

int main()
{
	int	num;
	int	abs_num;

	num = -5;
	abs_num = ABS(num);
	printf("la valeur absolue de %d est %d\n", num, abs_num);
	return (0);
}
