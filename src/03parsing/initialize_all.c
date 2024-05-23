/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:49:07 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/23 10:34:27 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_all_texures(t_textures *textures)
{
	textures->north_texture = NULL;
	textures->east_texture = NULL;
	textures->south_texture = NULL;
	textures->west_texture = NULL;
	textures->no_count = 0;
	textures->ea_count = 0;
	textures->so_count = 0;
	textures->we_count = 0;
}

void	init_all_colors(t_colors *colors)
{
	colors->floor.red = 0;
	colors->floor.green = 0;
	colors->floor.blue = 0;
	colors->ceiling.red = 0;
	colors->ceiling.green = 0;
	colors->ceiling.blue = 0;
	colors->floor_count = 0;
	colors->ceiling_count = 0;
}

void	init_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	init_all_texures(&data->textures);
	init_all_colors(&data->colors);
}
