/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:49:08 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/27 15:23:08 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_image_to_position(t_data *data, void *image_ptr, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		image_ptr, x * PIXELS, y * PIXELS);
}

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
			if (((char *)current->content)[x] == 'N')
			{
				data->start_x = x;
				data->start_y = y;
				put_image_to_position(data, data->player_ptr, x, y);
			}
			x++;
		}
		y++;
		current = current->next;
	}
}

void	init_images(t_data *data)
{
	data->textures.east_texture = mlx_xpm_file_to_image(data->mlx_ptr,"./textures/wolfenstein/blue_stone.xpm", &data->win_width, &data->win_height);
	data->textures.north_texture = mlx_xpm_file_to_image(data->mlx_ptr,"./textures/wolfenstein/blue_stone.xpm", &data->win_width, &data->win_height);
	data->textures.south_texture = mlx_xpm_file_to_image(data->mlx_ptr,"./textures/wolfenstein/blue_stone.xpm", &data->win_width, &data->win_height);
	data->textures.west_texture = mlx_xpm_file_to_image(data->mlx_ptr,"./textures/wolfenstein/blue_stone.xpm", &data->win_width, &data->win_height);
	data->player_ptr = mlx_xpm_file_to_image(data->mlx_ptr,"./textures/wolfenstein/mossy.xpm", &data->win_width, &data->win_height);
	}




void	set_images(t_data *data)
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
				put_image_to_position(data, data->textures.east_texture, x, y);
			if (((char *)current->content)[x] == '0')
				put_image_to_position(data, data->textures.north_texture, x, y);
			x++;
		}
		y++;
		current = current->next;
	}

}

/*

void	set_images(t_data *data)
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
}
*/

int	set_up(t_data *data)
{


		//data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width * PIXELS, data->win_height * PIXELS, "cub3D");
		data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width, data->win_height, "cub3D");
		if (!data->win_ptr)
	{
		display_error("Cannot open window");
		on_destroy(data);
		return (0);
	}




		init_images(data);
	set_images(data);
	set_player(data);



	return (1);
}
