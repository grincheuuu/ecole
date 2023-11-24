/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:33:44 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/25 17:43:34 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_limit(int n, int fd)
{
	write (fd, "-", 1);
	write (fd, "2", 1);
	n = 147483648;
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		div;
	int		mod;

	c = 0;
	if (n == -2147483648)
		n = ft_limit(n, fd);
	if (n < 0)
	{
		n *= -1;
		write (fd, "-", 1);
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 0 && n <= 9)
	{
		c = '0' + n;
		write (fd, &c, 1);
	}
	else
	{
		div = n / 10;
		mod = n % 10;
		ft_putnbr_fd(div, fd);
		ft_putnbr_fd(mod, fd);
	}
}
/*
int	main(void)
{
	int	n;
	int	fd;

	n = 124;
	fd = 1;
	ft_putnbr_fd(n, fd);
	return (0);
}*/

    Encapsulation dans un module ou un fichier source :
        En utilisant le mot-clé static pour déclarer une fonction dans un fichier source C, vous la rendez "privée" à ce fichier. Cela signifie que la fonction n'est pas accessible depuis d'autres fichiers source du projet, et elle ne peut pas être appelée depuis l'extérieur du fichier. Cela permet d'encapsuler la fonction dans le module où elle est définie, aidant ainsi à éviter les conflits de noms et à maintenir la cohérence du code.

    Éviter les conflits de noms :
        Lorsque plusieurs fichiers source d'un projet contiennent des fonctions avec le même nom, cela peut entraîner des conflits de noms. En déclarant une fonction en tant que static, vous limitez sa portée au fichier source où elle est définie, ce qui réduit le risque de conflits de noms avec des fonctions portant le même nom dans d'autres fichiers.

    Réduire la complexité du code :
        En définissant des fonctions comme static, vous pouvez "cacher" des détails d'implémentation complexes ou des fonctions auxiliaires qui ne sont pas destinées à être utilisées en dehors du fichier source. Cela permet de simplifier l'interface publique du module et d'améliorer la lisibilité du code en masquant les détails d'implémentation.

    Optimisation du compilateur :
        Les fonctions static peuvent potentiellement être optimisées par le compilateur. Le compilateur peut mieux comprendre la portée limitée de ces fonctions et peut appliquer des optimisations spécifiques, ce qui peut améliorer les performances du programme.
