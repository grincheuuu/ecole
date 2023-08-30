/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlecaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:50:04 by qlecaude          #+#    #+#             */
/*   Updated: 2023/08/12 15:04:01 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ligne1(int x, int y, int l, int c);
void	ligne2(int x, int y, int l, int c);
void	ligne3(int x, int y, int l, int c);

void	rush02(int x, int y)
{
	int	l; /*compteur de ligne */
	int	c; /*compteur de colonne */

	l = 1;
	while (l <= y)
	{
		c = 1;
		while (c <= x)
		{
			ligne1(x, y, l, c);
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
	if (l == 1 && (c == 1 || c == x))  //si la ligne egal a 1 et la colone ( est egal a 1 et est egal a x ) alor imprime A
	{
		ft_putchar('A');
	}
	else if(l == 1 && c != 1 && c != x) // si la ligne est egal a 1 et la colone est differente de 1 et de x imprime B
	{
		ft_putchar('B');
	}
}
void	ligne2(int x, int y, int l, int c)
{
	if((l != y && l != 1) && (c == 1 || c == x)) //si la ligne est differente de y et de 1 et la colone est egal a 1 ou x imprime B
	{
		ft_putchar('B');
	}
	else if (l != 1 && l != y && c != 1 && c != x) //la ligne est differente de 1 et de y et la colone differente de et de x
	{
		ft_putchar(' ');
	}
}
void	ligne3(int x, int l, int c)
{
	if (l == y && (c == 1 || c == x))
	{
		ft_putchar('C');
	}
	else if(l == y && c != 1 && c != x)
	{
		ft_putchar('B');
	}
}
