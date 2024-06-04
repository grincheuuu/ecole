/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:44:55 by gschwart          #+#    #+#             */
/*   Updated: 2024/04/24 17:00:30 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char *str, t_pointer **pointera)
{
	char	*var;
	char	*old_pwd;

	var = NULL;
	old_pwd = NULL;
	if (str == NULL || (str[0] == '~' && str[1] == '\0'))
	{
		ft_only_cd(pointera, "HOME=");
		return ;
	}
	old_pwd = ft_old_pwd(pointera);
	if (chdir(str))
	{
		strerror(errno);
		write (2, "cd: no such file or directory: ", 32);
		if (str[0] == '~')
			ft_putstr_fd(str + 1, 2);
		else
			ft_putstr_fd(str, 2);
		write (2, "\n", 1);
		free(old_pwd);
	   	return ;
	}
	else
	{
		var = ft_strjoin("PWD=", str);
		ft_realize_oldpwd(old_pwd, pointera);
		ft_export(var, pointera);
		free(var);
		free(old_pwd);
		return ;
	}
}

void	ft_realize_oldpwd(char *old_pwd, t_pointer **pointera)
{
	char	*op;

	op = NULL;
	if (old_pwd == NULL)
		return ;
	op = ft_strjoin("OLDPWD=", old_pwd);
	ft_export(op, pointera);
//	printf("\n\nL%sL\n\n", op);
	free(op);
}

char    *ft_old_pwd(t_pointer **pointera)
{
    char    *buffer;
    size_t  size;

    size = 1024;
    if (size <= 0)
        ft_failure(pointera);
    buffer = malloc((size + 1) * sizeof(char));
    if (buffer == NULL)
        ft_failure(pointera);
    if (getcwd(buffer, size) == NULL)
    {
        write (2, "Cannot get current working directory path\n", 43);
        free(buffer);
        ft_failure(pointera);
    }
    return (buffer);
}

void	ft_only_cd(t_pointer **pointera, char *var)
{
	t_list	*temp;
	char	*zoz;
	int	i;

	i = 0;
	zoz = NULL;
	temp = (*pointera)->first;
	while(temp != NULL)
	{
		if (ft_strncmp(var, temp->str, ft_strlen(var)) == 0)
		{
			zoz = ft_strdup(temp->str + 5);
			ft_cd(zoz, pointera);
			free (zoz);
			return ;
		}
		temp = temp->next;
		i++;
	}
	return ;
}
