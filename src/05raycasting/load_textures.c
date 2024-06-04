/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:01:55 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/04 13:02:12 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	load_east_texture(t_data *data)
{
	data->textures.east_img = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->textures.east_texture, &data->textures.east_width, \
		&data->textures.east_height);
	data->textures.east_data = (int *)mlx_get_data_addr(\
		data->textures.east_img, &data->textures.ea_count, \
		&data->textures.ea_count, &data->textures.ea_count);
}

void	load_north_texture(t_data *data)
{
	data->textures.north_img = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->textures.north_texture, &data->textures.north_width, \
		&data->textures.north_height);
	data->textures.north_data = (int *)mlx_get_data_addr(\
		data->textures.north_img, &data->textures.no_count, \
		&data->textures.no_count, &data->textures.no_count);
}

void	load_south_texture(t_data *data)
{
	data->textures.south_img = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->textures.south_texture, &data->textures.south_width, \
		&data->textures.south_height);
	data->textures.south_data = (int *)mlx_get_data_addr(\
		data->textures.south_img, &data->textures.so_count, \
		&data->textures.so_count, &data->textures.so_count);
}

void	load_west_texture(t_data *data)
{
	data->textures.west_img = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->textures.west_texture, &data->textures.west_width, \
		&data->textures.west_height);
	data->textures.west_data = (int *)mlx_get_data_addr(\
		data->textures.west_img, &data->textures.we_count, \
		&data->textures.we_count, &data->textures.we_count);
}
