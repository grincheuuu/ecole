#include "../include/vizu_hex.h"
#include "../include/lem-in.h"

void	add_rooms(char *line, t_vizu_hex *all)
{
	t_room *new_room;
	char **tab;
	int i;

	new_room = malloc(sizeof(t_room) * 1);
	tab = ft_split(line, ' ');
	new_room->name = ft_strdup(tab[0]);
	new_room->x = ft_atoi(tab[1]);
	new_room->y = ft_atoi(tab[2]);
	if (tab[3] && !ft_strncmp(tab[3], "start", 6))
		all->start = new_room;
	else if (tab[3])
		all->end = new_room;
	i = 0;
	while (all->rooms[i])
		i++;
	all->rooms[i] = new_room;
	all->rooms[i + 1] = NULL;
	ft_free_tab(tab);
}

t_ant_visu **create_ants(int nbr_ants, t_vizu_hex *all)
{
	t_ant_visu **ants;
	t_ant_visu *ant;
	int i;

	i = 0;
	ants = malloc(sizeof(t_ant_visu *) * (nbr_ants + 1));
	ants[nbr_ants] = NULL;
	while (i < nbr_ants)
	{
		ant = malloc(sizeof(t_ant_visu) * 1);
		ant->index = i + 1;
		ant->room = all->start;
		ant->x = all->rooms[0]->x;
		ant->y = all->rooms[1]->y;
		ant->prev_room = NULL;
		ants[i] = ant;
		i++;
	}
	return (ants);
}

void	fill_rooms(t_vizu_hex *all, t_lem_in *lem_in)
{
	all->rooms = lem_in->rooms;
	all->start = lem_in->start;
	all->end = lem_in->end;
	all->ants = create_ants(lem_in->nb_ants, all);
    all->nbr_ants = lem_in->nb_ants;
	all->mlx_ptr = NULL;
	all->back_tex.img.img_ptr = NULL;
	all->ant.img.img_ptr = NULL;
	all->room.img.img_ptr = NULL;
}

int	key_press(int key, t_vizu_hex *all)
{
	if (key == 65307)
		free_all((void *)all);
	return (0);
}

void	put_ant_img(t_vizu_hex *all, float x, float y)
{
	int img_size = (int)(all->scale / 2);

	x = (int)((x + 1.0) * all->scale);
	y = (int)((y + 1.0) * all->scale);

	x -= img_size / 2;
	y -= img_size / 2;
	for (int i = 0; i < img_size; i++)
		for (int j = 0; j < img_size; j++)
			if (my_mlx_get_color(&all->ant_img, i, j) >= 1 && x + i >= 0 && x + i < all->win_height && y + j >= 0 && y + j < all->win_height)
				my_mlx_pixel_put(&all->tmp, x + i, y + j, my_mlx_get_color(&all->ant_img, i, j));

}

unsigned long	to_milisecond(unsigned long second, unsigned long micro, unsigned long mili)
{
	unsigned long res;
	res = second * 1000;
	res += mili;
	res += micro / 1000;
	return (res);
}

void	update_anim(t_ant_visu *ant, t_room *start, t_room *end, int percent)
{
	float dx = (float)(end->x - start->x);
	float dy = (float)(end->y - start->y);

	ant->x = (float)start->x + dx * ((float)percent / 100.0f);
	ant->y = (float)start->y + dy * ((float)percent / 100.0f);
}

int game_loop(t_vizu_hex *all)
{
	char **tab;
	int a;
	struct timeval time_val;
	unsigned long now;
	
	gettimeofday(&time_val, NULL);
	now = to_milisecond(time_val.tv_sec, time_val.tv_usec, 0);
	if (all->is_anim_running)
	{
		for (int k = 0; all->ants[k]; k++)
		{
			if (all->ants[k]->prev_room)
				update_anim(all->ants[k], all->ants[k]->prev_room, all->ants[k]->room, all->anim_percent);
		}
		reset_tmp(all);
		for (int k = 0; all->ants[k]; k++)
			put_ant_img(all, all->ants[k]->x, all->ants[k]->y);
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->tmp.img_ptr, 0, 0);
		if (all->anim_percent >= 100)
			all->is_anim_running = 0;
		all->anim_percent += 5;
	}
	else if ((now - all->time_start) > all->time_to_sleep && all->line)
	{
		ft_putstr_fd(all->line, 1);
		ft_putchar_fd('\n', 1);
		for (int k = 0; all->ants[k]; k++)
		{
			all->ants[k]->prev_room = NULL;
			all->ants[k]->x = all->ants[k]->room->x;
			all->ants[k]->y = all->ants[k]->room->y;
		}
		tab = ft_split(all->line, ' ');
		for (int i = 0; tab[i]; i++)
		{
			a = 0;
			while (tab[i][a] && tab[i][a] != '-')
				a++;
			all->ants[ft_atoi(tab[i] + 1) - 1]->prev_room = all->ants[ft_atoi(tab[i] + 1) - 1]->room;
			all->ants[ft_atoi(tab[i] + 1) - 1]->room = get_room(tab[i] + a + 1, all->rooms);
		}
		ft_free_tab(tab);
		free(all->line);
		all->line = get_next_line(0);
		if (all->line && !check_move_line(all->line, all))
			free_all(all);
		all->is_anim_running = 1;
		all->anim_percent = 0;
		all->time_start = to_milisecond(time_val.tv_sec, time_val.tv_usec, 0);
	}
	return (0);
}

void put_names(t_vizu_hex *all)
{
	for (int i = 0; all->rooms[i]; i++)
		mlx_string_put(all->mlx_ptr, all->win_ptr, (all->rooms[i]->x * all->scale) + 50, (all->rooms[i]->y * all->scale) + 50,0xFFFF0000, all->rooms[i]->name);
}


int main()
{
    t_vizu_hex all;
	t_lem_in lem_in;
	struct timeval time_val;

	gettimeofday(&time_val, NULL);
	all.time_start = to_milisecond(time_val.tv_sec, time_val.tv_usec, 0);
	parsing_vizu(&lem_in);
	fill_rooms(&all, &lem_in);
	all.time_to_sleep = 750;
	all.is_anim_running = 0;
	all.anim_percent = 0;
	all.line = get_next_line(0);
	if (all.line && all.line[0] == 'E')
		my_exit(1, all.line);
	make_back_img(&all);
	add_link(&all);
	put_rooms(&all);
	reset_tmp(&all);

	for (int k = 0; all.ants[k]; k++)
		put_ant_img(&all, all.ants[k]->x, all.ants[k]->y);
	if (all.line && !check_move_line(all.line, &all))
		free_all(&all);
	mlx_put_image_to_window(all.mlx_ptr, all.win_ptr, all.tmp.img_ptr, 0, 0);
	//put_names(&all);
	mlx_hook(all.win_ptr, 17, 0, free_all, &all);
	mlx_hook(all.win_ptr, 2, (1L << 0), key_press, &all);
	mlx_loop_hook(all.mlx_ptr, game_loop, &all);
	mlx_loop(all.mlx_ptr);
}
