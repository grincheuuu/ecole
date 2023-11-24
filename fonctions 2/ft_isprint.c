/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:16:16 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/24 13:35:12 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (!(c > 31 && c < 127))
		return (0);
	return (1);
}
/*
int	main(void)
{
	char	c = 'o';

	printf("%d", ft_isprint(c));
	return (0);
}*/

Les caractères de numéro 0 à 31 et le 127 ne sont pas affichables
