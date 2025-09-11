#include "../include/lem-in.h"

void    print_help()
{
    ft_putstr_fd("Usage:\n./lem-in < map.txt\n\nmap.txt:\n", 1);
    ft_putstr_fd("4\n3 2 2\n##start\nstart 4 0\n##end\nend 4 6\n", 1);
    ft_putstr_fd("4 0 4\n1 4 2\n2 4 4\n5 8 2\n6 8 4\nstart-1\n", 1);
    ft_putstr_fd("3-4\n2-4\n1-5\n6-5\nend-6\n1-2\n2-end\n3-start\n", 1);
    exit(0);
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
//    ft_print_all(all_room, "next");
//	ft_print_list_maillon(all_room);
    ft_free_all_end(all_room);
//	find_all_paths(&all);


	// t_list *tmp;
	// t_list *tmp2;
	// t_room *room;
	// tmp = all.paths;
	// while (tmp)
	// {
	// 	tmp2 = tmp->content;
	// 	while (tmp2)
	// 	{
	// 		room = tmp2->content;
	// 		printf("%s ", room->name);
	// 		tmp2 = tmp2->next;
	// 	}
	// 	printf("\n");
	// 	tmp = tmp->next;
	// }


//	for (int i = 0; all.ants[i]; i++)
//		all.ants[i]->path = all.paths->content;
//	reset_is_visited(&all);
//	print_moves(&all);
	//printf("chemins trouvé: %d\n", ft_lstsize(all.paths));
	for (int a = 0; all.ants[a]; a++)
		free(all.ants[a]);
	free(all.ants);
	free_rooms(all.rooms);
}
