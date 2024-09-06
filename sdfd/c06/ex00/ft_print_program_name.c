/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 10:35:18 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/20 11:06:10 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char **str)
{
	int	i;

	i = 0;
	while (str[0][i])
	{
		write (1, &str[0][i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	ft_putstr(argv);
	return (0);
}
