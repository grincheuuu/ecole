/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:57:00 by gschwart          #+#    #+#             */
/*   Updated: 2024/05/01 16:58:27 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	*buffer;
	size_t	size;

	size = 1024;
	if (size <= 0)
		return (1);
	buffer = malloc((size + 1) * sizeof(char));
	if (buffer == NULL)
		return (1);
	if (getcwd(buffer, size) == NULL)
	{
		write(2, "Cannot get current working directory path\n", 43);
		free(buffer);
		return (1);
	}
	ft_putstr_fd(buffer, 1);
	write(1, "\n", 1);
	free(buffer);
	return (0);
}

int	ft_int(long nb, char **argv)
{
	if (ft_atol_test(argv[1]) == 2)
		return (2);
	if (nb > 2147483647 || nb < -2147483648)
	{
		write(2, "minishell: exit: ", 17);
		ft_putstr_fd(argv[1], 2);
		write(2, " : numeric argument required", 28);
		return (2);
	}
	if (nb < 0 && nb > -257)
		return (256 + nb);
	if (nb > 255 || nb < -256)
		return (nb % 255);
	if (nb > 0 && nb <= 255)
		return (nb);
	return (0);
}
