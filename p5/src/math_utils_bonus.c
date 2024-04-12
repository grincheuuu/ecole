/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:04:20 by gschwart          #+#    #+#             */
/*   Updated: 2023/12/18 15:52:13 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

// [0..799] -> [-2..+2]

double	map(double unscaled_num, double new_min,
		double new_max, double old_min)
{
	return ((new_max - new_min) *(unscaled_num - old_min));
}

t_complex	sum_complex(t_complex z, t_complex c)
{
	t_complex	result;

	result.x = z.x + c.x;
	result.y = z.y + c.y;
	return (result);
}

t_complex	square_complex(t_complex z, t_fractal *fractal)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	if (!ft_strncmp(fractal->name, "burnigship", 10))
	{
		if (result.y < 0)
			result.y = result.y * -1;
	}
	return (result);
}
