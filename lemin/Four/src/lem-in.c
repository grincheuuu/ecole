#include "../include/lem-in.h"

void    print_help()
{
    ft_putstr_fd("Usage:\n./lem-in < map.txt\n\nmap.txt:\n", 1);
    ft_putstr_fd("4\n3 2 2\n##start\nstart 4 0\n##end\nend 4 6\n", 1);
    ft_putstr_fd("4 0 4\n1 4 2\n2 4 4\n5 8 2\n6 8 4\nstart-1\n", 1);
    ft_putstr_fd("3-4\n2-4\n1-5\n6-5\nend-6\n1-2\n2-end\n3-start\n", 1);
    exit(0);
}

void    free_paths(t_list *paths)
{
    t_list *tmp;
    t_list *tmp2;

    tmp = paths;
    while (tmp)
    {
        tmp2 = (t_list *)tmp->content;
        ft_lstclear(&tmp2, del_nothing);
        tmp = tmp->next;
    }
    ft_lstclear(&paths, del_nothing);
}

void	free_all(t_lem_in *all)
{
	if (all->paths)
		free_paths(all->paths);
	for (int a = 0; all->ants[a]; a++)
		free(all->ants[a]);
	free(all->ants);
	free_rooms(all->rooms);
}

int main(int ac, char **av)
{
    t_lem_in all;
	g_list  **pointer;
    g_list    **all_room;

    all_room = NULL;

    if (ac > 2)
        my_exit(1, "Error: too many arguments\n");
    if (ac == 2)
    {
        if (!ft_strncmp(av[1], "--help", 7))
            print_help();
        my_exit(1, "Error: with arguments\n");
    }
	all.paths = NULL;
    parsing(&all);
	pointer = ft_pointer_begin(&all, &all_room);
    ft_maillon_list(pointer, &all, &all_room);
    ft_free_all_end(all_room);
	free_all(&all);
}
