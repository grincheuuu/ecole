/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:36:14 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/30 14:41:48 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char	*o_dest;

	o_dest = dest;
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	dest = o_dest;
	return (dest);
}

int main ()
{
	char	src[] = "salut";
	char	dest[20];

	ft_strcpy(dest, src);
	return (0);
}
