/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:05:03 by gschwart          #+#    #+#             */
/*   Updated: 2025/06/30 18:05:06 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem-in.h"

void	ft_fre(char **patch)
{
	int	i;

	i = 0;
	if (patch == NULL)
		return;
	while (patch[i] != NULL)
	{
		free(patch[i]);
		i++;
	}
	free(patch);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	l;

	l = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	dest = malloc((l + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, s1);
	ft_strcat(dest, s2);
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	dest = malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[j] != '\0')
	{
		dest[j] = s[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		if (*p1 == '\0')
			return (0);
		p1++;
		p2++;
		n--;
	}
	return (0);
}

void	ft_fre_pointer(g_list **pointer)
{
	int	i = 0;

	while (pointer[i] != NULL)
	{
		free(pointer[i]->chemin);
		free(pointer[i]->name);
		free(pointer[i]);
		i++;
	}
	free(pointer);
}


int	ft_search_room_all(g_list **all_room, char *name)
{
	if (all_room == NULL || name == NULL)
	{
		return (1);
	}
	if (name == NULL)
	{
		return (1);
	}
	for (int i = 0; all_room[i] != NULL; i++)
	{
		if (ft_strncmp(all_room[i]->name, name, ft_strlen(name) + 1) == 0)
		{
			return (1);
		}
	}
	return (0);
}

void	ft_free_a(t_chaine **a)
{
	t_chaine	*temp = *a;
	t_chaine	*zomm = *a;

	if (zomm == NULL)
	{
		free(a);
		return;
	}
	while (zomm->before != NULL)
		zomm  =  zomm->before;
	while (zomm != NULL)
	{
		temp = zomm;
		free(zomm->name);
		ft_fre(zomm->tab);
		zomm = zomm->next;
		free(temp);
	}
	free(a);
}

void	ft_free_b(t_a **b)
{
	t_a	*temp = *b;
	t_a	*sup = NULL;

	while (temp != NULL)
	{
		sup = temp;
		temp = temp->next;
		free(sup);
	}
}

void	ft_free_all(g_list **pointer)
{
	int i = 0;
	int	t = 0;
	int	j;
	g_list	**a;

    while (pointer != NULL && pointer[i] != NULL)
    {
		j = 0;
		if (pointer[i]->next != NULL)
		{
			while (pointer[i]->next[j] != NULL)
			{
				if (ft_compare_maillon(pointer, pointer[i]->next[j], i, j) == 0)
					t++;
				j++;
			}
		}
		i++;
    }
	if (t == 0)
	{
		free(pointer);
		return;
	}
	a = malloc((t + 1) * sizeof(g_list*));
	if (a == NULL)
		return;
	i = 0;
	t = 0;
	while (pointer != NULL && pointer[i] != NULL)
    {
		if (pointer[i]->next != NULL)
		{
			j = 0;
			while (pointer[i]->next[j] != NULL)
			{
				if (ft_compare_maillon(pointer, pointer[i]->next[j], i , j) == 0)
				{
					a[t] = pointer[i]->next[j];
					t++;
				}
				j++;
			}

		}
		free(pointer[i]->name);
		free(pointer[i]->chemin);
		free(pointer[i]);
		i++;
    }
	ft_free_all(a);
}

int	ft_compare_maillon(g_list **pointer, g_list *a, int i, int j)
{
	int	p = 0;
	int k;

	while (pointer[p] != NULL && pointer[p]->next != NULL && p < i)
	{
		k = 0;
		while (pointer[p]->next[k] != NULL)
		{
			if (pointer[p]->next[k] == a)
				return (1);
			k++;
		}
		p++;
	}
	k = 0;
	while ((pointer[i]->next != NULL) && (k < j) && (pointer[i]->next[k] != NULL))
	{
		if (pointer[i]->next[k] == a)
			return (1);
		k++;
	}
	return (0);
}

void	ft_free_t_room(t_room *ab)
{
	free(ab->name);
	free(ab->neighbors);
	free(ab);
}

void	ft_free_all_end(g_list **pointer)
{
	int	i = 0;

	while (pointer != NULL && pointer[i] != NULL)
	{
        t_chemin *temp = pointer[i]->all_chemins->list;
        while (temp != NULL)
        {
            t_chemin *next = temp->next;
            ft_fre(temp->chemin);
            free(temp);
            temp = next;
        }
		free(pointer[i]->next);
		free(pointer[i]->chemin);
		free(pointer[i]->all_chemins);
		free(pointer[i]);
		i++;
	}
	free(pointer);
}

void	ft_free_n(t_sortie **n)
{
	for (int i = 0; n[i] != NULL; i++)
	{
		free(n[i]->fourmie_name);
		free(n[i]->index_fourmie);
		free(n[i]->end_fourmie);
		free(n[i]);
	}
	free(n);
}

t_tab_chemin	*ft_create_tab_chemin(void)
{
	t_tab_chemin	*new;

    new = malloc(sizeof(t_tab_chemin));
    if (new == NULL)
	{
        return (NULL);
	}
	new->list = NULL;
	return (new);
}

t_tab_chemin	*ft_create_and_add_chemins(g_list **pointer, char *name)
{
	t_tab_chemin	*tab_chemin = NULL;
	t_chemin		*list_temp = NULL;

	tab_chemin = ft_create_tab_chemin();
	if (tab_chemin == NULL)
		return (NULL);
	if (pointer == NULL || (*pointer)->all_chemins == NULL)
	{
		list_temp = ft_create_new_list(NULL, name);
		tab_chemin->list = list_temp;
	}
	else
		ft_copy_and_create_list(&tab_chemin, name, (*pointer)->all_chemins);
	return (tab_chemin);
}

void	ft_copy_and_create_list(t_tab_chemin **new_chemin, char *name, t_tab_chemin *all_chemins)
{
	t_chemin	*iter = all_chemins->list;
	t_chemin	*new_list = NULL;

	while (iter != NULL)
	{
		new_list = ft_create_new_list(iter, name);
		if (new_list == NULL)
			return;
		ft_add_back_list(new_chemin, new_list); 
		iter = iter->next;
	}
}

t_chemin	*ft_create_new_list(t_chemin *iter, char *name)
{
	t_chemin	*list;

	list = malloc(sizeof(t_chemin));
	if (iter == NULL)
	{
		list->chemin = ft_copy_chemin(NULL, name);
		list->count = 1;
	}
	else
	{
		list->chemin = ft_copy_chemin(iter->chemin, name);
		list->count = iter->count + 1;
	}
	list->next = NULL;
	return(list);
}

char	**ft_copy_chemin(char **tab, char *name)
{
	char	**new_tab = NULL;
	int		i = 0;

	if (tab != NULL)
		i = ft_tab_len(tab);
	if (name == NULL)
		i += 1;
	else
		i += 2;
	new_tab = malloc((i)* sizeof(char *));
	if (new_tab == NULL)
		return (NULL);
	i = 0;
	while (tab != NULL && tab[i] != NULL)
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	if (name != NULL)
		new_tab[i++] = ft_strdup(name);
	new_tab[i] = NULL;
	return (new_tab);
}

void	ft_add_back_list(t_tab_chemin **new_chemin, t_chemin *new_maillon)
{
	t_chemin	*temp = NULL;

	if ((*new_chemin)->list == NULL)
	{
		(*new_chemin)->list = new_maillon;
		return;
	}
	temp = (*new_chemin)->list;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_maillon;
}

int	ft_tab_len(char **tab)
{
	int	i = 0;

	while(tab[i] != NULL)
		i++;
	return (i);
}

void	ft_ajout_chemin(g_list ***all_room, char *name, g_list **pointer)
{
	g_list **temp = NULL;

	temp = ft_search_room_all_deux((*all_room), name);
	if ((*temp)->all_chemins == NULL)
	{
		return;
	}
	else
		ft_copy_and_create_list(&(*temp)->all_chemins, name, (*pointer)->all_chemins);
}

g_list	**ft_search_room_all_deux(g_list **all_room, char *name)
{
	if (all_room == NULL || name == NULL)
		return NULL;
	for (int i = 0; all_room[i] != NULL; i++)
	{
		if (ft_strncmp(all_room[i]->name, name, ft_strlen(name) + 1) == 0)
		{
			return (&all_room[i]);
		}
	}
	return (0);
}

void	ft_create_c(t_a *b, t_chaine ***c)
{
	t_chemin	*temp = NULL;

	while (b != NULL)
	{
		temp = b->cas->all_chemins->list;
		while (temp != NULL)
		{
			ft_create_add_new(c, b->cas->name, temp);
			temp = temp->next;
		}
		b = b->next;
	}
}

void 	ft_free_t_all(t_all_group **list)
{
	t_all_group	*temp = *list;
	t_all_group	*suprimer = NULL;
	t_liste_chaine	*cur = temp->group;
	t_liste_chaine	*sup = NULL;
	int			i = 0;

	while (temp != NULL)
	{
		suprimer =temp;
		cur = temp->group;
		while (cur != NULL)
		{
			sup = cur;
			free(cur->name);
			ft_fre(cur->liste);
			cur = cur->next;
			free(sup);
		}
		temp = temp->next;
		free(suprimer);
		i++;
	}
	*list = NULL;
}