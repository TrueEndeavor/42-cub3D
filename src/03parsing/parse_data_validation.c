/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data_validation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:26:25 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/04 12:38:26 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	textures_are_valid(t_textures *textures)
{
	return (textures->no_count == 1 && \
			textures->ea_count == 1 && \
			textures->so_count == 1 && \
			textures->we_count == 1);
}

bool	texture_files_exist(t_textures *textures)
{
	return (check_texture_file(textures->north_texture) && \
			check_texture_file(textures->east_texture) && \
			check_texture_file(textures->south_texture) && \
			check_texture_file(textures->west_texture));
}

bool	colors_are_valid(t_colors *colors)
{
	return (colors->floor_count == 1 && \
			colors->ceiling_count == 1);
}

bool	colors_have_valid_rgb(t_colors *colors)
{
	return ((colors->floor.red >= 0 && colors->floor.red <= 255) && \
			(colors->floor.green >= 0 && colors->floor.green <= 255) && \
			(colors->floor.blue >= 0 && colors->floor.blue <= 255) && \
			(colors->ceiling.red >= 0 && colors->ceiling.red <= 255) && \
			(colors->ceiling.green >= 0 && colors->ceiling.green <= 255) && \
			(colors->ceiling.blue >= 0 && colors->ceiling.blue <= 255));
}

int	check_tex_col(t_data *data, bool tex_flag, bool col_flag)
{
	if (!textures_are_valid(&data->textures))
		return (ERR_TEXTURE_MISSING_OR_DUPLICATED);
	if (!texture_files_exist(&data->textures) && tex_flag)
		return (ERR_TEXTURE_FILE_CANNOT_OPEN);
	if (!colors_are_valid(&data->colors))
		return (ERR_COLOR_MISSING_OR_DUPLICATED);
	if (!colors_have_valid_rgb(&data->colors) && col_flag)
		return (ERR_COLOR_RGB_VALUES_MISSING);
	return (0);
}
