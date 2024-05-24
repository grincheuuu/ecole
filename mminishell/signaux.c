/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:18:41 by gschwart          #+#    #+#             */
/*   Updated: 2024/05/06 20:18:53 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    sigint_handler(int signal)
{
    if (signal == SIGINT)
    {
        write (1, "\n", 1);
        write (1, " prompt ", 9);
        write (1, "^C", 2);
        write (1, "\n", 1);     
    }
}

void    set_signal(void)
{
    struct sigaction    action;

    ft_bzero(&action.sa_handler, sizeof(action));
    ft_bzero(&action.sa_mask, sizeof(action));
    ft_bzero(&action.sa_flags, sizeof(action));
    action.sa_handler = &sigint_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = SA_SIGINFO;
    sigaction(SIGINT, &action, NULL);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char		*p;
	int					i;

	i = 0;
	p = (unsigned char *)s;
	while (n > 0)
	{
		p[i] = 0;
		n--;
		i++;
	}
}
