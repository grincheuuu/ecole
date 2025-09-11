#include "../include/vizu_hex.h"
#include "../include/lem-in.h"

void	put_background(t_vizu_hex *all)
{
	float scale;

	scale = (float)all->back_tex.height / (float)all->win_height;
	for (int x = 0; x < all->win_height - 1; x++)
	{
		for (int y = 0; y < all->win_height - 1; y++)
		{
			my_mlx_pixel_put(&all->back, x, y, my_mlx_get_color(&all->back_tex.img, (int)((float)x * scale), (int)((float)y * scale)));
		}
	}
}

void		get_diff_max(t_vizu_hex *all)
{
	int max;

	all->x_min = all->rooms[0]->x;
	max = 0;
	for(int i = 0; all->rooms[i]; i++)
	{
		if (all->rooms[i]->x < all->x_min)
			all->x_min = all->rooms[i]->x;
		if (all->rooms[i]->x > max)
			max = all->rooms[i]->x;
	}
	all->diff_max = max - all->x_min;
	all->y_min = all->rooms[0]->y;
	max = 0;
	for(int i = 0; all->rooms[i]; i++)
	{
		if (all->rooms[i]->y < all->y_min)
			all->y_min = all->rooms[i]->y;
		if (all->rooms[i]->y > max)
			max = all->rooms[i]->y;
	}
	if ((max - all->y_min) > all->diff_max)
		all->diff_max = max - all->y_min;
	for (int i = 0; all->rooms[i]; i++)
	{
		all->rooms[i]->x -= all->x_min;
		all->rooms[i]->y -= all->y_min;
	}
    for (int j = 0; all->ants[j]; j++)
    {
        all->ants[j]->x = all->start->x;
        all->ants[j]->y = all->start->y;
    }
}

void	reset_tmp(t_vizu_hex *all)
{
	for (int x = 0; x < all->win_height; x++)
		for (int y = 0; y < all->win_height; y++)
			my_mlx_pixel_put(&all->tmp, x, y, my_mlx_get_color(&all->back, x, y));
}

void	resize_ant(t_vizu_hex *all)
{
	int img_size;
	float scale;

	img_size = (int)(all->scale / 2);
	if (img_size <= 0)
		img_size = 1;
	all->ant_img.img_ptr = mlx_new_image(all->mlx_ptr, img_size, img_size);	
	all->ant_img.data = mlx_get_data_addr(all->ant_img.img_ptr, &all->ant_img.bpp, &all->ant_img.size_l, &all->ant_img.endian);
	scale = (float)all->ant.height / (float)img_size;
	for (int x = 0; x < img_size; x++)
		for (int y = 0; y < img_size; y++)
				my_mlx_pixel_put(&all->ant_img, x, y, my_mlx_get_color(&all->ant.img, (int)((float)x * scale), (int)((float)y * scale)));
}

void	resize_room(t_vizu_hex *all)
{
	int img_size;
	float scale;

	img_size = (int)(all->scale / 1.1);
	if (img_size == 0)
		img_size++;
	all->room_img.img_ptr = mlx_new_image(all->mlx_ptr, img_size, img_size);
	all->room_img.data = mlx_get_data_addr(all->room_img.img_ptr, &all->room_img.bpp, &all->room_img.size_l, &all->room_img.endian);
	scale = (float)all->room.height / (float)img_size;
	(void)scale;
	for (int x = 0; x < img_size; x++)
		for (int y = 0; y < img_size; y++)
			my_mlx_pixel_put(&all->room_img, x, y, my_mlx_get_color(&all->room.img, (int)((float)x * scale), (int)((float)y * scale)));
}

int		darckness(int color)
{
	int r = (color >> 16) & 0xFF;
	int g = (color >> 8) & 0xFF;
	int b = color & 0xFF;

	r -= 50;
	g -= 50;
	b -= 50;
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	return ((r << 16) | (g << 8) | b);
}

void	put_room_img(t_vizu_hex *all, t_room *room)
{
	int img_size = (int)(all->scale / 1.1);

	int x = (int)((float)(room->x + 1) * all->scale);
	int y = (int)((float)(room->y + 1) * all->scale);

	x -= img_size / 2;
	y -= img_size / 2;
	if (room == all->start || room == all->end)
	{
		for (int i = 0; i < img_size; i++)
			for (int j = 0; j < img_size; j++)
				if (x + i >= 0 && x + i < all->win_height && y + j >= 0 && y + j < all->win_height)
					my_mlx_pixel_put(&all->back, x + i, y + j, darckness(my_mlx_get_color(&all->room_img, i, j)));
	}
	else
		for (int i = 0; i < img_size; i++)
			for (int j = 0; j < img_size; j++)
				if (x + i >= 0 && x + i < all->win_height && y + j >= 0 && y + j < all->win_height)
					my_mlx_pixel_put(&all->back, x + i, y + j, my_mlx_get_color(&all->room_img, i, j));
	
}

void 	load_textures(t_vizu_hex *all)
{
	all->ant.img.img_ptr = mlx_xpm_file_to_image(all->mlx_ptr, "./textures/fourmis.xpm", &all->ant.width, &all->ant.height);
	all->room.img.img_ptr = mlx_xpm_file_to_image(all->mlx_ptr, "./textures/salles.xpm", &all->room.width, &all->room.height);
	all->back_tex.img.img_ptr = mlx_xpm_file_to_image(all->mlx_ptr, "./textures/herbe.xpm", &all->back_tex.width, &all->back_tex.height);
	if (!all->back_tex.img.img_ptr || !all->ant.img.img_ptr || !all->room.img.img_ptr)
	{
		ft_putstr_fd("Error: error with textures\n", 1);
		free_all(all);
	}
	all->room.img.data = mlx_get_data_addr(all->room.img.img_ptr, &all->room.img.bpp, &all->room.img.size_l, &all->room.img.endian);
	all->ant.img.data = mlx_get_data_addr(all->ant.img.img_ptr, &all->ant.img.bpp, &all->ant.img.size_l, &all->ant.img.endian);
	all->back_tex.img.data = mlx_get_data_addr(all->back_tex.img.img_ptr, &all->back_tex.img.bpp, &all->back_tex.img.size_l, &all->back_tex.img.endian);
}

void	put_rooms(t_vizu_hex *all)
{
	if (!all->room.img.img_ptr)
		return;
	resize_room(all);
	for (int i = 0; all->rooms[i]; i++)
		put_room_img(all, all->rooms[i]);
	all->tmp.img_ptr = mlx_new_image(all->mlx_ptr, all->win_height, all->win_height);
	all->tmp.data = mlx_get_data_addr(all->tmp.img_ptr, &all->tmp.bpp, &all->tmp.size_l, &all->tmp.endian);
	resize_ant(all);
}

void draw_line(t_vizu_hex *all, int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
    int e2;

    while (1)
    {
		for (int x = x0 - 1; x <= x0 + 1; x++)
			for (int y = y0 - 1; y <= y0 + 1; y++)
				if (x < all->win_height && y < all->win_height)
					if (x >= 0 && x <= all->win_height - 1 && y >= 0 && y <= all->win_height - 1)
					my_mlx_pixel_put(&all->back, x, y, 0xFFFF0000);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void	add_link(t_vizu_hex *all)
{
	t_room *room1;
	t_room *room2;
	
	for (int i = 0; all->rooms[i]; i++)
	{
		room1 = all->rooms[i];
		for (int j = 0; all->rooms[i]->neighbors[j]; j++)
		{
			room2 = all->rooms[i]->neighbors[j];
			draw_line(all, (room1->x + 1) * all->scale, (room1->y + 1) * all->scale, (room2->x + 1) * all->scale, (room2->y + 1) * all->scale);
		}
	}
}

void	make_back_img(t_vizu_hex *all)
{
	int width;
	int height;

	all->mlx_ptr = mlx_init();
	load_textures(all);
	get_diff_max(all);
	mlx_get_screen_size(all->mlx_ptr, &width, &height);
	all->win_height = height - 80;
	all->win_ptr = mlx_new_window(all->mlx_ptr, all->win_height, all->win_height, "Lem-in");
	all->back.img_ptr = mlx_new_image(all->mlx_ptr, all->win_height, all->win_height);
	all->back.data = mlx_get_data_addr(all->back.img_ptr, &all->back.bpp, &all->back.size_l, &all->back.endian);
	put_background(all);
	all->scale = (float)all->win_height / ((float)all->diff_max + 2);
}
