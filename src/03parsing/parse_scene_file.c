/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:49:07 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/22 13:48:51 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parse_line(char *line, t_data *data)
{
	t_textures	textures;
	t_colors	colors;

	textures = (t_textures){NULL, 0, NULL, 0, NULL, 0, NULL, 0};
	colors = (t_colors){(t_rgb){0, 0, 0}, (t_rgb){0, 0, 0}};
	data->textures = &textures;
	data->colors = &colors;

	if (line == NULL)
		return ;
	trim_whitespace(&line);
	if (is_texture_line(line))
		parse_texture_line(line, data->textures);
	else if (is_color_line(line))
		parse_color_line(line, data->colors);
}

void	parse_scene_file(t_data *data, char *scene_file)
{
	int		fd;
	char	*line;

	fd = check_readable(data, scene_file);
	line = get_next_line(fd);
	if (!line)
	{
		display_error("Map file empty");
		on_destroy(data);
	}
	while (line)
	{
		if (!line) // maybe to skip an empty newline, empty and what not
			on_destroy(data);
		parse_line(line, data);
		// Is any of the textures missing?
		// Is any of the colors missing?
		{
			// Check if Textures are filled
			// Check if Colors are filled
			// only then parse_map();
			// Is map missing?
		}
		//data->height++;
		if (!load_map(data, trim_newline(line)))
			on_destroy(data);
		free(line);
		line = get_next_line(fd);
	}
	// Is textures || colors || map missing?
	free(line);
	close(fd);
}
