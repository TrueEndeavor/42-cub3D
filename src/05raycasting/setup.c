/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:49:08 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/28 15:37:05 by lannur-s         ###   ########.fr       */
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

void	init_images(t_data *data)
{
	data->north_texture = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->textures.north_texture, &(data->win_width), &(data->win_height));
	data->east_texture = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->textures.east_texture, &(data->win_width), &(data->win_height));
	data->south_texture = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->textures.south_texture, &(data->win_width), &(data->win_height));
	data->west_texture = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->textures.west_texture, &(data->win_width), &(data->win_height));
	if (!data->north_texture || !data->east_texture || !data->south_texture
		|| !data->west_texture)
	{
		display_error("Image not loaded");
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
		"Raycaster");
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
