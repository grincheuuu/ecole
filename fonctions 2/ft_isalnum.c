/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:31:31 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/19 17:46:15 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(char c)
{
	if (c == '\0')
		return (0);
	if ((c < 65 || c > 90) && (c < 97 || c > 122))
	{
		if (c < 48 || c > 57)
			return (0);
	}
	return (1);
}
/*
int	main(void)
{
	char	c = '~';

	printf("%d", ft_isalnum(c));
	return (0);
}*/

La fonction isalnum est une fonction de la bibliothèque standard en langage C (et dans d'autres langages de programmation) qui permet de déterminer si un caractère est un caractère alphanumérique. Un caractère alphanumérique est un caractère qui est soit une lettre (a-z, A-Z) soit un chiffre (0-9).
