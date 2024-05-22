/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:47:25 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/22 12:51:49 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void get_texture(char *line, char **texture, int *count)
{
	trim_whitespace(&line);
	*texture = ft_strdup(line);
	(*count)++;
}

int	get_direction(const char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return NORTH;
	if (ft_strncmp(line, "EA", 2) == 0)
		return EAST;
	if (ft_strncmp(line, "SO", 2) == 0)
		return SOUTH;
	if (ft_strncmp(line, "WE", 2) == 0)
		return WEST;
	return (-1);
}

void parse_texture_line(char *line, t_textures *textures)
{
	int direction = get_direction(line);
	if (direction != -1)
	{
		parse_textures(direction, textures, line + 2);
	}
}

void	parse_textures(int direction, t_textures *textures, char *line)
{
	if (direction == NORTH)
		get_texture(line, &textures->north_texture, &textures->no_count);
	else if (direction == EAST)
		get_texture(line, &textures->east_texture, &textures->ea_count);
	else if (direction == SOUTH)
		get_texture(line, &textures->south_texture, &textures->so_count);
	if (direction == WEST)
		get_texture(line, &textures->west_texture, &textures->we_count);
	//free(line);
	/*free(textures.north_texture);
	free(textures.east_texture);
	free(textures.south_texture);
	free(textures.west_texture);*/
}
