/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_return_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 04:20:13 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/19 04:20:45 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	number_exeptions(char **numbers, int co)
{
	if (is_str_digit(numbers[co]) == 1)
	{
		printf("Error\n");
		printf("error: there is a non int in the RGB colors\n");
		free_split2(numbers);
		return (1);
	}
	if (ft_strlen(numbers[co]) > 3)
	{
		printf("Error\n");
		printf("error: the number is too big, it must be less than 255\n");
		free_split2(numbers);
		return (1);
	}
	if (ft_atoi(numbers[co]) > 255)
	{
		printf("Error\n");
		printf("error: the number is too big, it must be less than 255\n");
		free_split2(numbers);
		return (1);
	}
	return (0);
}

int	test_rgb(char *charnum)
{
	char	**numbers;
	int		co;

	co = 0;
	numbers = ft_split(charnum, ',');
	if (numbers == NULL)
		return (1);
	while (numbers[co])
		co++;
	if (co != 3)
	{
		printf("Error\n");
		printf("error: not good colors param\n");
		free_split2(numbers);
		return (1);
	}
	co = 0;
	while (numbers[co])
	{
		if (number_exeptions(numbers, co) == 1)
			return (1);
		co++;
	}
	free_split2(numbers);
	return (0);
}

int	put_rgb_floor(t_cubfile *cubfile, char *charnum)
{
	char	**numbers;
	int		co;

	co = 0;
	if (cubfile->floor_color)
	{
		printf("Error\n");
		printf("error: there are two floor color lines!\n");
		return (1);
	}
	cubfile->floor_color = (int *)malloc(3 * sizeof(int));
	if (!cubfile->floor_color)
	{
		printf("Error\n");
		printf("error :malloc failed\n");
		return (1);
	}
	numbers = ft_split(charnum, ',');
	while (co < 3)
	{
		cubfile->floor_color[co] = ft_atoi(numbers[co]);
		co++;
	}
	free_split2(numbers);
	return (0);
}

int	put_rgb_ceiling(t_cubfile *cubfile, char *charnum)
{
	char	**numbers;
	int		co;

	co = 0;
	if (cubfile->ceiling_color)
	{
		printf("Error\n");
		printf("error: there are two ceiling color lines!\n");
		return (1);
	}
	cubfile->ceiling_color = (int *)malloc(3 * sizeof(int));
	if (!cubfile->ceiling_color)
	{
		printf("Error\n");
		printf("error :malloc failed\n");
		return (1);
	}
	numbers = ft_split(charnum, ',');
	while (co < 3)
	{
		cubfile->ceiling_color[co] = ft_atoi(numbers[co]);
		co++;
	}
	free_split2(numbers);
	return (0);
}
