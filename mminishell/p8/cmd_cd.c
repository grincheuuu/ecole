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

int	ft_realize_cd(char **argv, t_pointer **pointera)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (argv[i] != NULL)
		i++;
	if (i <= 2)
		status = ft_cd(argv[1], pointera);
	else
	{
		write(2, "minishell: cd: too many arguments\n", 34);
		status = 1;
	}
	return (status);
}

int	ft_cd_tilde(t_pointer **pointera, char *str)
{
	int		status;
	char	*home;
	char	*op;

	status = 0;
	home = NULL;
	op = NULL;
	home = ft_search_home(*pointera, "HOME=");
	if (home == NULL)
		status = ft_cd(str, pointera);
	else
	{
		op = ft_strjoin(home, str + 1);
		status = ft_cd(op, pointera);
		free(op);
	}
	free(home);
	return (status);
}

char    *ft_search_home(t_pointer *pointera, char *var)
{
	t_list	*temp;
	char	*home;

	home = NULL;
	temp = pointera->first;
	while(temp != NULL)
	{
		if (ft_strncmp(var, temp->str, 4) == 0)
		{
			home = ft_strdup(temp->str + 5);
			return (home);
		}
		temp = temp->next;
	}
	return (NULL);
}

int	ft_cd(char *str, t_pointer **pointera)
{
	char	*old_pwd;

	old_pwd = NULL;
	if (str == NULL || (str[0] == '~' && str[1] == '\0'))
	{
		ft_only_cd(pointera, "HOME=");
		return (0);
	}
	if (str[0] == '~')
		return (ft_cd_tilde(pointera, str));
	if (str[0] == '-' && str[1] == '\0')
		return (ft_cd_moin(pointera));
	old_pwd = ft_old_pwd();
	if (chdir(str))
	{
		ft_chdir_error(str, old_pwd);
		return (1);
	}
	else
	{
		ft_chdir_success(old_pwd, pointera);
		return (0);
	}
}

void	ft_chdir_error(char *str, char *old_pwd)
{
	write(2, "minishell: cd: ", 15);
	if (str[0] == '~')
		ft_putstr_fd(str + 1, 2);
	else
		ft_putstr_fd(str, 2);
	write(2, ": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	write(2, "\n", 1);
	free(old_pwd);
}

void	ft_chdir_success(char *old_pwd, t_pointer **pointera)
{
	char	**var;
	char	*pwd;

	pwd = NULL;
	var = malloc(3 * sizeof(char *));
	pwd = ft_old_pwd();
	var[0] = ft_strdup("export");
	var[1] = ft_strjoin("PWD=", pwd);
	var[2] = NULL;
	ft_realize_oldpwd(old_pwd, pointera);
	ft_export(var, pointera);
	ft_fre(var);
	free(pwd);
	free(old_pwd);
}

int	ft_cd_moin(t_pointer **pointera)
{
	int	i;
	int	j;
	t_list	*temp;
	char	*old_pwd;

	j = 0;
	old_pwd = NULL;
	temp = (*pointera)->first;
	i = ft_search_var(*pointera, "OLDPWD=");
	if (i == 0)
		i = ft_search_var(*pointera, "PWD=");
	while (temp != NULL && j < i)
	{
		temp = temp->next;
		j++;
	}
	old_pwd = ft_strdup(temp->str + 7);
	ft_cd(old_pwd, pointera);
	free(old_pwd);
	ft_pwd();
	return (0);
}

void	ft_realize_oldpwd(char *old_pwd, t_pointer **pointera)
{
	char	**op;

	op = malloc(3 * sizeof(char *));
	if (op == NULL)
		return ;
	if (old_pwd == NULL)
		return ;
	op[0] = ft_strdup("export");
	op[1] = ft_strjoin("OLDPWD=", old_pwd);
	op[2] = NULL;
	ft_export(op, pointera);
	ft_fre(op);
}

char	*ft_old_pwd(void)
{
	char	*buffer;
	size_t	size;

	size = 1024;
	if (size <= 0)
		return (NULL);
	buffer = malloc((size + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	if (getcwd(buffer, size) == NULL)
	{
		write(2, "Cannot get current working directory path\n", 43);
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

void	ft_only_cd(t_pointer **pointera, char *var)
{
	t_list	*temp;
	char	*zoz;
	int		i;

	i = 0;
	zoz = NULL;
	temp = (*pointera)->first;
	while (temp != NULL)
	{
		if (ft_strncmp(var, temp->str, 4) == 0)
		{
			zoz = ft_strdup(temp->str + 5);
			ft_cd(zoz, pointera);
			free(zoz);
			return ;
		}
		temp = temp->next;
		i++;
	}
	return ;
}
