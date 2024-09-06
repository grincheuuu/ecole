/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:25:49 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/25 12:32:53 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int argc, char **argv)
{
	int	i;

	i = 0;
	while(argv[0][i])
	{
		write(1, &argv[0][i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	ft_putchar(argc, argv);
	return (0);
}
