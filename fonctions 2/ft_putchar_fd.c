/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:33:58 by gschwart          #+#    #+#             */
/*   Updated: 2023/10/23 14:05:01 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
/*
int	main(void)
{
	char	c;
	int	fd;

	c = 'A';
	fd = open("mon_fichier.txt", O_WRONLY);
	if (fd != -1)
	{
		ft_putchar_fd(c, fd);
		close(fd);
	}
	return (0);
}*/

Dans POSIX, un descripteur de fichier est un entier, et plus spécifiquement dans le langage C, un entier de type int.

Il y a trois descripteurs de fichier POSIX standard pour tout processus qui n'est pas un daemon :
Nombre entier 	Nom 	Constante (unistd.h) 	Flux
0 	Entrée standard 	STDIN_FILENO 	stdin
1 	Sortie standard 	STDOUT_FILENO 	stdout
2 	Erreur standard 	STDERR_FILENO 	stderr

Généralement, un descripteur de fichier est un index d'une entrée dans le noyau-résident, structure de données contenant les détails de tous les fichiers ouverts.

Dans POSIX, on appelle cette structure de données une table de descripteurs de fichier. Et chaque processus a sa propre table de descripteurs de fichier. L'application utilisateur passe la clé abstraite au noyau par un appel système et le noyau accèdera au fichier grâce à cette clé. L'application ne peut pas lire ou écrire directement dans la table des descripteurs de fichier.

Dans un système Unix, les descripteurs de fichier peuvent désigner des fichiers, des répertoires, des devices bloc ou caractère (souvent appelés fichiers spéciaux), des pipes nommés ou des pipes anonymes. 

l'entrée standard par défaut le clavier
la sortie standard, par défaut l'écran (ou la console)
et l'erreur standard, par défaut associé à l'écran (ou la console)

 Les entrées/sorties en langage C se font par l'intermédiaire d'entités logiques, appelés flux, qui représentent des objets externes au programme, appelés fichiers. Un fichier peut être ouvert en lecture, auquel cas il est censé nous fournir des données (c'est-à-dire être lu) ou ouvert en écriture, auquel cas il est destiné à recevoir des données provenant du programme. Un fichier peut être à la fois ouvert en lecture et en écriture. Une fois qu'un fichier est ouvert, un flux lui est associé. Un flux d'entrée est un flux associé à un fichier ouvert en lecture et un flux de sortie un flux associé à un fichier ouvert un écriture. Tous les fichiers ouverts doivent être fermés avant la fin du programme.

Lorsque les données échangées entre le programme et le fichier sont de type texte, la nécessité de définir ce qu'on appelle une ligne est primordiale. En langage C, une ligne est une suite de caractères terminée par le caractère de fin de ligne (inclus) : '\n'. Par exemple, lorsqu'on effectue des saisies au clavier, une ligne correspond à une suite de caractères terminée par ENTREE. Puisque la touche ENTREE termine une ligne, le caractère généré par l'appui de cette touche est donc, en C standard, le caractère de fin de ligne soit '\n'. 

https://melem.developpez.com/tutoriels/langage-c/initiation-langage-c/?page=es
