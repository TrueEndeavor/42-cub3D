/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:49:07 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/03 16:54:38 by lannur-s         ###   ########.fr       */
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
	colors->floor.red = -1;
	colors->floor.green = -1;
	colors->floor.blue = -1;
	colors->ceiling.red = -1;
	colors->ceiling.green = -1;
	colors->ceiling.blue = -1;
	colors->floor_count = 0;
	colors->ceiling_count = 0;
}

void	init_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	data->map_height = 0;
	data->map_width = 0;
	init_all_texures(&data->textures);
	init_all_colors(&data->colors);
	initialize_game(&data->game);
	data->map = NULL;
	data->dup_map = NULL;
	data->world_map = NULL;
}

void	initialize_game(t_game *game)
{
	game->pos_x = 3;
	game->pos_y = 2;
	game->move_speed = 0.6;
	game->rot_speed = 0.3;
	game->mouserot_speedfactor = 0.005;
	game->dir_x = -1;
	game->dir_y = 0;
	game->plane_x = 0;
	game->plane_y = 0.66;
}
