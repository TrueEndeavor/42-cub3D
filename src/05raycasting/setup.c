/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:49:08 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/29 16:06:12 by lannur-s         ###   ########.fr       */
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

void	load_texture(t_data *data, char *tex_path, void **img, int **img_data)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	*img = mlx_xpm_file_to_image(data->mlx_ptr, tex_path, &width, &height);
	*img_data = (int *)mlx_get_data_addr(*img, &(int){0}, &(int){0}, &(int){0});

	if (!*img_data)
	{
		display_error("Image not loaded properly");
		on_destroy(data);
	}
}

void	init_images(t_data *data)
{
	load_texture(data, data->textures.east_texture, \
		(void **)&data->textures.east_img, &data->textures.east_data);
	load_texture(data, data->textures.north_texture, \
		(void **)&data->textures.north_img, &data->textures.north_data);
	load_texture(data, data->textures.south_texture, \
		(void **)&data->textures.south_img, &data->textures.south_data);
	load_texture(data, data->textures.west_texture, \
		(void **)&data->textures.west_img, &data->textures.west_data);
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
