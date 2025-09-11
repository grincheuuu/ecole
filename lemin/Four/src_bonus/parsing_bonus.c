#include "../include/lem-in.h"
#include "../include/vizu_hex.h"

int     check_move_line(char *line, t_vizu_hex *all)
{
    int i = 0;
    char **tab;

    tab = ft_split(line, ' ');
    if (!tab)
        return (0);
    for (int a = 0; tab[a]; a++)
    {
        i = 0;
        if (tab[a][i] != 'L')
        {
            ft_free_tab(tab);
            return (0);
        }
        i++;
        if (ft_atoi(tab[a] + i) <= 0 || ft_atoi(tab[a] + i) > all->nbr_ants)
        {
            ft_free_tab(tab);
            return (0);
        }
        while (ft_isdigit(tab[a][i]))
            i++;
        if (tab[a][i] != '-')
        {
            ft_free_tab(tab);
            return (0);
        }
        if (!get_room(tab[a] + i + 1, all->rooms))
        {
            ft_free_tab(tab);
            return (0);
        }
    }
	ft_free_tab(tab);
    return (1);
}

t_room *create_room(char *name, int x, int y)
{
	t_room *new_room;

	new_room = malloc(sizeof(t_room) * 1);
	new_room->name = ft_strdup(name);
	new_room->x = x;
	new_room->y = y;
	new_room->is_end = false;
	new_room->is_start = false;
	new_room->is_visited = false;
	new_room->neighbors = NULL;
	new_room->neightbors_lst = NULL;
	return (new_room);
}

int		check_double_xy(t_list *rooms, int x, int y)
{
	t_list *tmp;
	t_room *room;

	tmp = rooms;
	while (tmp)
	{
		room = (t_room *)tmp->content;
		if (room->x == x && room->y == y)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	add_new_room(t_parse *parse, t_lem_in *all)
{
	char **tab;
	t_room *new_room;

	if (parse->is_begin == 1 && parse->is_end == 1)
		parsing_error(parse, NULL);
	tab = ft_split(parse->line, ' ');
	if (!get_room_lst(tab[0], parse->rooms) && !check_double_xy(parse->rooms, ft_atoi(tab[1]), ft_atoi(tab[2])))
	{
		new_room = create_room(tab[0], ft_atoi(tab[1]), ft_atoi(tab[2]));
		if (parse->is_begin == 1)
		{
			new_room->is_start = true;
			all->start = new_room;
			parse->is_begin = 2;
		}
		else if (parse->is_end == 1)
		{
			new_room->is_end = true;
			all->end = new_room;
			parse->is_end = 2;
		}
		ft_lstadd_back(&parse->rooms, ft_lstnew((void *)new_room));
	}
	else
	{
		ft_free_tab(tab);
		parsing_error(parse, "Error: double room detected\n");
	}
	ft_free_tab(tab);
}

void	add_new_link(t_parse *parse)
{
	char **tab;
	t_room *room1;
	t_room *room2;

	tab = ft_split(parse->line, '-');
	room1 = get_room_lst(tab[0], parse->rooms);
	room2 = get_room_lst(tab[1], parse->rooms);
	parse->status = 2;
	if (!room1 || !room2 || room1 == room2 || get_room_lst(tab[0], room2->neightbors_lst))
	{
		ft_free_tab(tab);
		parsing_error(parse, NULL);
	}
	ft_free_tab(tab);
	ft_lstadd_back(&room1->neightbors_lst, ft_lstnew((void *)room2));
	ft_lstadd_back(&room2->neightbors_lst, ft_lstnew((void *)room1));
}

void	start_parsing(t_parse *parse, t_lem_in *all)
{
	while (parse->line && ft_strlen(parse->line))
	{
		ft_lstadd_back(&parse->file, ft_lstnew(parse->line));
		if (parse->line && parse->line[0] == '#')
		{
			if (parse->status == 1 && parse->is_begin == 0 && !ft_strncmp(parse->line, "##start", 8))
				parse->is_begin = 1;
			else if (parse->status == 1 && parse->is_end == 0 && !ft_strncmp(parse->line, "##end", 6))
				parse->is_end = 1;
			else if (!ft_strncmp(parse->line, "##start", 8) || !ft_strncmp(parse->line, "##end", 6))
				parsing_error(parse, "Error: double start or end detected\n");
		}
		else if (parse->status == 0 && !check_nbr_ants(parse->line))
		{
			all->nb_ants = ft_atoi(parse->line);
			parse->status = 1;
		}
		else if (parse->status == 1 && ft_strchr(parse->line, ' ') && !check_room(parse->line))
			add_new_room(parse, all);
		else if (!ft_strchr(parse->line, ' ') && ft_strchr(parse->line, '-') && !check_link(parse->line))
			add_new_link(parse);
		else
			parsing_error(parse, NULL);
		//free(parse->line);
		parse->line = get_next_line(0);
	}
	if (parse->line)
		free(parse->line);
}

void	fill_rooms_tab(t_parse *parse, t_lem_in *all)
{
	int nbr_rooms = ft_lstsize(parse->rooms);
	t_list *tmp;
	t_list *tmp2;
	t_room *room;
	
	tmp = parse->rooms;
	all->nb_rooms = nbr_rooms;
	all->rooms = malloc(sizeof(t_room *) * (nbr_rooms + 1));
	all->rooms[nbr_rooms] = NULL;
	int i = 0;
	while (tmp)
	{
		room = (t_room *)tmp->content;
		all->rooms[i] = room;
		int nbr_links = ft_lstsize(room->neightbors_lst);
		int j = 0;
		room->neighbors = malloc(sizeof(t_room *) * (nbr_links + 1));
		room->neighbors[nbr_links] = NULL;
		tmp2 = room->neightbors_lst;
		while (tmp2)
		{
			room->neighbors[j] = (t_room *)tmp2->content;
			j++;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
		i++;
	}
}

void 	parsing_vizu(t_lem_in *all)
{
	t_parse parse;
	t_list	*tmp;

	parse.status = 0;
	parse.line = get_next_line(0);
	parse.is_begin = 0;
	parse.is_end = 0;
	parse.rooms = NULL;
	parse.file = NULL;
	start_parsing(&parse, all);
	if (parse.is_begin != 2 || parse.is_end != 2)
		parsing_error(&parse, "Error: no begin or no end\n");
	if (parse.status < 2)
		parsing_error(&parse, "Error: missing an element\n");
	fill_rooms_tab(&parse, all);
	ft_lstclear(&parse.file, del_str);
	tmp = parse.rooms;
	while (tmp)
	{
		t_room *room = (t_room *)tmp->content;
		ft_lstclear(&room->neightbors_lst, del_nothing);
		tmp = tmp->next;
	}
	ft_lstclear(&parse.rooms, del_nothing);
}

