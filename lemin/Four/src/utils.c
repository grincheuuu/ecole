#include "../include/lem-in.h"

t_room *get_room(char *name, t_room **rooms)
{
	for(int i = 0; rooms[i]; i++)
		if (!ft_strncmp(name, rooms[i]->name, ft_strlen(name) + 1))
			return (rooms[i]);
	return (NULL);
}

void	free_rooms(t_room **rooms)
{
    int j = 0;

    while (rooms[j])
    {
		free(rooms[j]->name);
        if (rooms[j]->neighbors)
		    free(rooms[j]->neighbors);
        free(rooms[j]);
        j++;
    }
    free(rooms);
}

void my_exit(int code, char *error)
{
    if (error)
        write(1, error, ft_strlen(error));
    write(1, "./lem-in --help for more informations\n", 39);
    exit(code);
}
