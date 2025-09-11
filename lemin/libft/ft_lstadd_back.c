/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminet <mminet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:34:43 by mminet            #+#    #+#             */
/*   Updated: 2024/03/11 15:33:44 by mminet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (alst == NULL || new == NULL)
		return ;
	last = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}
