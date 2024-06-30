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
