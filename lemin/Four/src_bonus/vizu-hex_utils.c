 #include "../include/vizu_hex.h"

int	my_mlx_get_color(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->data + (y * data->size_l + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->data + (y * data->size_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int free_all(t_vizu_hex *all)
{
    for (int i = 0; all->ants[i]; i++)
        free(all->ants[i]);
    free(all->ants);
    while(all->line)
    {
        free(all->line);
        all->line = get_next_line(0);
    }
    for (int i = 0; all->rooms[i]; i++)
    {
        free(all->rooms[i]->name);
        free(all->rooms[i]->neighbors);
        free(all->rooms[i]);
    }
    free(all->rooms);
	if (all->mlx_ptr)
	{  
		if (all->back_tex.img.img_ptr)
			mlx_destroy_image(all->mlx_ptr, all->back_tex.img.img_ptr);
		if (all->room.img.img_ptr)
			mlx_destroy_image(all->mlx_ptr, all->room.img.img_ptr);
		if (all->ant.img.img_ptr)
			mlx_destroy_image(all->mlx_ptr, all->ant.img.img_ptr);
		if (all->back_tex.img.img_ptr && all->room.img.img_ptr && all->ant.img.img_ptr)
		{		
			mlx_destroy_image(all->mlx_ptr , all->back.img_ptr);
			mlx_destroy_image(all->mlx_ptr, all->room_img.img_ptr);
			mlx_destroy_image(all->mlx_ptr, all->ant_img.img_ptr);
			mlx_destroy_image(all->mlx_ptr, all->tmp.img_ptr);
			mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		}
		mlx_destroy_display(all->mlx_ptr);
	}
    free(all->mlx_ptr);
    exit(0);
    return (0);
}
