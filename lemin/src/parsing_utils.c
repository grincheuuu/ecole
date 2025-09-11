#include "../include/lem-in.h"

void	del_nothing(void *to_del)
{
	(void)to_del;
}

void	del_room(void *to_del)
{
	t_room *room;

	if (to_del)
	{
		room = (t_room *)to_del;
		if (room->name)
			free(room->name);
		if (room->neightbors_lst)
			ft_lstclear(&room->neightbors_lst, del_nothing);
		free(room);
	}
}

void	del_str(void *to_del)
{
	char *str;

	str = (char *)to_del;
	if (str)
		free(str);
}

void 	free_parsing(t_parse *parse)
{
	parse->line = get_next_line(0);
	while (parse->line)
	{
		free(parse->line);
		parse->line = get_next_line(0);
	}
	if (parse->rooms)
		ft_lstclear(&parse->rooms, del_room);
	if (parse->file)
		ft_lstclear(&parse->file, del_str);
}

void	parsing_error(t_parse *parse, char *str)
{
	free_parsing(parse);
	if (str)
		my_exit(1, str);
	if (parse->status == 0)
		my_exit(1, "Error: invalid number of ants\n");
	if (parse->status == 1)
		my_exit(1, "Error: invalid room\n");
	else
		my_exit(1, "Error: invalid link\n");
}

int check_nbr_ants(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (!ft_isdigit(line[i]))
            return (1);
        i++;
    }
    if (ft_atoi(line) > 500 || ft_atoi(line) <= 0)
        return (1);
    return (0);
}

int check_room(char *line)
{
    int i = 0;

    if (line[0] == 'L' || line[0] == '#')
        return (1);
    while (line[i] && ft_isprint(line[i]) && line[i] != ' ')
        i++;
    if (line[i] == ' ')
        i++;
    if (!line[i] || !ft_isdigit(line[i]))
        return (1);
    if (ft_atoi(line + i) < 0)
        return (1);
    while (line[i] && ft_isdigit(line[i]))
        i++;
    if (line[i] == ' ')
        i++;
    if (!line[i] || !ft_isdigit(line[i]))
        return (1);
    if (ft_atoi(line + i) < 0)
        return (1);
    while (line[i] && ft_isdigit(line[i]))
        i++;
    if (line[i])
        return (1);
    return (0);
}

int check_link(char *line)
{
    int j;

    j = 0;
    if (line[0] == '-')
        return (1);
    while (line[j] && line[j] != '-')
        j++;
    if (line[j] != '-')
        return (1);
    j++;
    if (!line[j])
        return (1);
    while (line[j] && line[j] != '-')
        j++;
    if (line[j])
        return (1);
    return (0);
}
t_room	*get_room_lst(char *str, t_list *rooms)
{
	t_list *tmp;
	t_room *room;

	tmp = rooms;
	while (tmp)
	{
		room = (t_room *)tmp->content;
		if (!ft_strncmp(room->name, str, ft_strlen(str) + 1))
			return (room);
		tmp = tmp->next;
	}
	return (NULL);
}
