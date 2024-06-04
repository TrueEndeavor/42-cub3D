/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:49:08 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/04 13:01:45 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_images_loading(t_data *data)
{
	if (!data->textures.north_data || !data->textures.east_data || \
		!data->textures.south_data || !data->textures.west_data)
	{
		display_error("Images not loaded properly");
		on_destroy(data);
	}
}

void	init_images(t_data *data)
{
	load_east_texture(data);
	load_north_texture(data);
	load_south_texture(data);
	load_west_texture(data);
	check_images_loading(data);
}

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
	return (1);
}
