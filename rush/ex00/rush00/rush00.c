/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlecaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:50:04 by qlecaude          #+#    #+#             */
/*   Updated: 2023/08/12 10:51:46 by qlecaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ligne1(int x, int l, int c);
void	ligne2(int x, int y, int l, int c);
void	ligne3(int x, int y, int l, int c);

void	ft_putchar(char c);

void	rush00(int x, int y)
{
	int	l;
	int	c;

	l = 1;
	while (l <= y)
	{
		c = 1;
		while (c <= x)
		{
			ligne1(x, l, c);
			ligne2(x, y, l, c);
			ligne3(x, y, l, c);
			c++;
			if (c > x && l < y)
			{
				ft_putchar('\n');
			}
		}
		l++;
	}
}

void	ligne1(int x, int l, int c)
{
	if (l == 1 && (c == 1 || c == x))
	{
		ft_putchar('o');
	}
	else if (l == 1 && c != 1 && c != x)
	{
		ft_putchar('-');
	}
}

void	ligne2(int x, int y, int l, int c)
{
	if ((l != y && l != 1) && (c == 1 || c == x))
	{
		ft_putchar('|');
	}
	else if (l != 1 && l != y && c != 1 && c != x)
	{
		ft_putchar(' ');
	}
}

void	ligne3(int x, int y, int l, int c)
{
	if (l == y && (c == 1 || c == x))
	{
		ft_putchar('o');
	}
	else if (l == y && c != 1 && c != x)
	{
		ft_putchar('-');
	}
}
