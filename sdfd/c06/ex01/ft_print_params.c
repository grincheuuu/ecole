/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:09:00 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/20 12:41:16 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnstr(int argc, char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < argc)
	{
		while (str[j][i])
		{
			write (1, &str[j][i], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	ft_putnstr(argc, argv);
	return (0);
}
