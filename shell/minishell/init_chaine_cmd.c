/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_chaine_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:02:41 by gschwart          #+#    #+#             */
/*   Updated: 2024/05/06 16:03:12 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_init_maillon_cmd(char **argv)
{
    t_pointer_cmd   *pointerb;
    t_cmd      *cmd_list;
    t_cmd   	*temp;

    pointerb = NULL;
    cmd_list = NULL;
	pointerb = malloc(sizeof(t_pointer_cmd));
	if (pointerb == NULL)
        return (1);
    pointerb->first = NULL;
	pointerb->end = NULL;
    cmd_list = ft_maillonlist_cmd(argv);
	if (cmd_list == NULL)
		return (1);
	temp = cmd_list;
	pointerb->first = cmd_list;
	while (temp->next != NULL)
		temp = temp->next;
	pointerb->end = temp;
    write(1, "\n", 1);
	ft_printlist_cmd(pointerb);
    write(1, "\n", 1);
	ft_lstclear_node(&cmd_list);
	free(pointerb);
	return (0);
}

t_cmd	*ft_maillonlist_cmd(char **argv)
{
	t_cmd	*new;
	t_cmd	*chaine;
    char    **temp;
	int		i;

	i = 0;
	new = NULL;
	chaine = NULL;
    temp = NULL;
	while (argv[i] != NULL)
	{
        temp = ft_split(argv[i], ' ');
		new = ft_lstnew_cmd(&temp);
		if (new == NULL)
		{
			ft_lstclear_node(&chaine);
            ft_fre(temp);
			return (NULL);
		}
		ft_lstadd_back_cmd(&chaine, new);
        ft_fre(temp);
		i++;
	}
	return (chaine);
}

t_cmd	*ft_lstnew_cmd(char ***str)
{
	t_cmd	*new_node;
    int i;

    i = 0;
	new_node = (t_cmd *)malloc(sizeof(t_cmd));
	if (new_node == NULL)
		return (NULL);
    while ((*str)[i] != NULL)
        i++;
    if (i < 2)
    {
        free(new_node);
        return (NULL);
    }
	new_node->cmd = ft_strdup((*str)[0]);
    new_node->type = ft_strdup((*str)[1]);
    if (new_node->type == NULL)
	{
		ft_free_node_cmd(new_node);
		return (NULL);
	}
	new_node->before = NULL;
	new_node->next = NULL;
	return (new_node);
}
void    ft_free_node_cmd(t_cmd *node)
{
    if (node->cmd != NULL)
        free(node->cmd);
    if (node->type != NULL)
        free(node->type);
    free(node);
}
void	ft_lstclear_node(t_cmd **chaine)
{
	t_cmd	*current;
	t_cmd	*second;

	if (*chaine == NULL)
		return ;
	current = *chaine;
	while (current != NULL)
	{
		second = current->next;
		ft_free_node_cmd(current);
		current = second;
	}
	*chaine = NULL;
}

void	ft_printlist_cmd(t_pointer_cmd *pointerB)
{
	t_cmd	*temp;
	int		i;

	temp = NULL;
	i = 0;

	if (pointerB == NULL)
	{
		write (1, "NULL", 4);
		return ;
	}
	temp = pointerB->first;
	while (temp != NULL)
	{
		printf("%s\n", temp->cmd);
        printf("%s\n", temp->type);
		temp = temp->next;
		i++;
    	printf("\n");
	}
}

void	ft_lstadd_back_cmd(t_cmd **chaine, t_cmd *new)
{
	t_cmd	*temp;

	temp = *chaine;
	if (*chaine == NULL)
		*chaine = new;
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
		new->before = temp;
		new->next = NULL;
	}
}
