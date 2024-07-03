/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:44:42 by tlegendr          #+#    #+#             */
/*   Updated: 2024/07/02 18:08:57 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_addlist_token	*bstructtok(int token, int next_token,
	int *token_var)
{
	t_addlist_token	*new_node;

	new_node = (t_addlist_token *)malloc(sizeof(t_addlist_token));
	if (new_node == NULL)
		exit(EXIT_FAILURE);
	new_node->token = token;
	new_node->next_token = next_token;
	new_node->token_var = token_var;
	return (new_node);
}

t_addlist	*bstruct(int index, int full_len,
	int special_token)
{
	t_addlist	*new_node;

	new_node = (t_addlist *)malloc(sizeof(t_addlist));
	if (new_node == NULL)
		exit(EXIT_FAILURE);
	new_node->index = index;
	new_node->full_len = full_len;
	new_node->special_token = special_token;
	return (new_node);
}

int	handle_special_case(t_parsing *parsing)
{
	int		status;
	char	tocheck;

	tocheck = parsing->line[parsing->i];
	if (tocheck)
	{
		if (tocheck == ' ')
			status = 0;
		else if (tocheck == '\t')
			status = 0;
		else if (tocheck == '\'' || tocheck == '\"')
			status = 0;
		else if (tocheck == '|')
			status = 0;
		else if (tocheck == '>' || tocheck == '<')
			status = 0;
		else if (tocheck == '$')
			status = 0;
		else
			status = 1;
	}
	else
		status = 0;
	return (status);
}

t_lexing	*add_to_list(t_lexing *tmp, char *cmd,
	t_addlist_token *addlist_token, t_addlist *addlist)
{
	t_lexing	*new_node;

	tmp->cmd = ft_strdup(cmd);
	tmp->token = addlist_token->token;
	tmp->special_token = addlist->special_token;
	tmp->full_len = addlist->full_len;
	tmp->index = addlist->index;
	if (addlist_token->token_var != NULL)
		*(addlist_token->token_var) = addlist_token->next_token;
	free(addlist_token);
	free(addlist);
	new_node = (t_lexing *)malloc(sizeof(t_lexing));
	if (new_node == NULL)
		exit(EXIT_FAILURE);
	new_node->cmd = NULL;
	new_node->token = 0;
	new_node->special_token = 0;
	new_node->full_len = 0;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = tmp;
	tmp->next = new_node;
	return (new_node);
}
