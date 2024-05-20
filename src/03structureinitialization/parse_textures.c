/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:47:25 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/20 19:05:44 by lannur-s         ###   ########.fr       */
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

void	parse_textures(int direction, t_textures *textures, char *line)
{
	char	*tex_file;

	while (ft_iswhitespace(*line) && (*line) != '\n')
	{
		line++;
	}
	tex_file = line;
	printf("tex_file = %s\n", tex_file);
	if (direction == NORTH)
		textures->north_texture = ft_strdup(tex_file);
	if (direction == EAST)
		textures->north_texture = ft_strdup(tex_file);
	if (direction == SOUTH)
		textures->north_texture = ft_strdup(tex_file);
	if (direction == WEST)
		textures->north_texture = ft_strdup(tex_file);
	
	//free(line);
}
