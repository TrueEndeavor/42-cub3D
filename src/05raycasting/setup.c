/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:49:08 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/30 10:27:02 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_player(t_data *data)
{
	t_list	*current;
	int		x;
	int		y;

	current = data->map;
	y = 0;
	while (current)
	{
		x = 0;
		while (((char *)current->content)[x])
		{
			if (((char *)current->content)[x] == 'P')
			{
				data->cat_x = x;
				data->cat_y = y;
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->player_ptr, data->cat_x * PIXELS,
					data->cat_y * PIXELS);
			}
			x++;
		}
		y++;
		current = current->next;
	}
}

/* void	load_texture(t_data *data, char *tex_path, void **img, int **img_data)
{
	
	*img = mlx_xpm_file_to_image(data->mlx_ptr, tex_path, &data->textures.east_width, &data->textures.east_height);
	*img_data = (int *)mlx_get_data_addr(*img, &(int){0}, &(int){0}, &(int){0});

	if (!*img_data)
	{
		display_error("Image not loaded properly");
		on_destroy(data);
	}
} */

void	init_images(t_data *data)
{
	 data->textures.east_img = mlx_xpm_file_to_image(data->mlx_ptr, data->textures.east_texture, &data->textures.east_width, &data->textures.east_height);
    data->textures.east_data = (int *)mlx_get_data_addr(data->textures.east_img, &data->textures.ea_count, &data->textures.ea_count, &data->textures.ea_count);

    data->textures.north_img = mlx_xpm_file_to_image(data->mlx_ptr, data->textures.north_texture, &data->textures.north_width, &data->textures.north_height);
    data->textures.north_data = (int *)mlx_get_data_addr(data->textures.north_img, &data->textures.no_count, &data->textures.no_count, &data->textures.no_count);

    data->textures.south_img = mlx_xpm_file_to_image(data->mlx_ptr, data->textures.south_texture, &data->textures.south_width, &data->textures.south_height);
    data->textures.south_data = (int *)mlx_get_data_addr(data->textures.south_img, &data->textures.so_count, &data->textures.so_count, &data->textures.so_count);

    data->textures.west_img = mlx_xpm_file_to_image(data->mlx_ptr, data->textures.west_texture, &data->textures.west_width, &data->textures.west_height);
    data->textures.west_data = (int *)mlx_get_data_addr(data->textures.west_img, &data->textures.we_count, &data->textures.we_count, &data->textures.we_count);
	if (!data->textures.north_data || !data->textures.east_data || \
		!data->textures.south_data || !data->textures.west_data)
	{
		display_error("Images not loaded properly");
		on_destroy(data);
	}
}

void	put_image_to_position(t_data *data, void *image_ptr, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		image_ptr, x * PIXELS, y * PIXELS);
}

/* void	set_images(t_data *data)
{
	t_list	*current;
	int		x;
	int		y;

	current = data->map;
	y = 0;
	while (current)
	{
		x = 0;
		while (((char *)current->content)[x])
		{
			if (((char *)current->content)[x] == '1')
				put_image_to_position(data, data->wall_ptr, x, y);
			if (((char *)current->content)[x] == '0')
				put_image_to_position(data, data->floor_ptr, x, y);
			if (((char *)current->content)[x] == 'C')
				put_image_to_position(data, data->flower_ptr, x, y);
			if (((char *)current->content)[x] == 'E')
				put_image_to_position(data, data->lover_ptr, x, y);
			x++;
		}
		y++;
		current = current->next;
	}
} */

int	set_up(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
		data->win_width, data->win_height, \
		"Raycaster new");
	if (!data->win_ptr)
	{
		display_error("Cannot open window");
		on_destroy(data);
		return (0);
	}
	init_images(data);
	//set_images(data);
	//set_player(data);
	//data->moves = 0;
	//data->collected = 0;
	return (1);
}
