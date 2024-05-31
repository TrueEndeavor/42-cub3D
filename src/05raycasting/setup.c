/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:49:08 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/31 17:42:56 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"



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
