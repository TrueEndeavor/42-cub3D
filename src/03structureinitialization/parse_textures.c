/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:47:25 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/21 10:44:52 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* char	*trim_newline(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
	}
	return (str);
} */

char *trim_whitespace(char *line)
{
	while (*line && ft_iswhitespace(*line))
		line++;
	return line;
}

void get_texture(char *line, char **texture, int *count)
{
	trim_whitespace(&line);
	*texture = ft_strdup(line);
	(*count)++;
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
