/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:49:07 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/23 10:31:52 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parse_line(char *line, t_data *data)
{
	if (line == NULL)
		return ;
	trim_whitespace(&line);
	if (is_texture_line(line))
		parse_texture_line(line, &data->textures);
	else if (is_color_line(line))
		parse_color_line(line, &data->colors);
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
		if (!load_map(data, trim_newline(line)))
			on_destroy(data);
		free(line);
		line = get_next_line(fd);
	}
	// Is any of the textures missing?
	//printf("%d %d %d %d\n", data->textures->no_count, data->textures->ea_count, data->textures->so_count, data->textures->we_count);
	if (data->textures.no_count != 1 || \
		data->textures.ea_count != 1 || \
		data->textures.so_count != 1 || \
		data->textures.we_count != 1)
	{
		printf("one of the textures missing or double\n");
	}
	if (!check_texture_file(data->textures.north_texture) || \
		!check_texture_file(data->textures.east_texture) || 
		!check_texture_file(data->textures.south_texture) || 
		!check_texture_file(data->textures.west_texture))
	{
		printf("one of the texture files cannot be opened\n");	
	}
	// Is any of the colors missing?
	//printf("%d %d %d %d\n", data->colors->floor_count, data->colors->ceiling_count);
	if (data->colors.floor_count != 1 || \
		data->colors.ceiling_count != 1)
	{
		printf("one of the colors missing or double\n");
	}
	// Is textures || colors || map missing?
		
	{
		// Check if Textures are filled
		// Check if Colors are filled
		// only then parse_map();
		// Is map missing?
	}		
	free(line);
	close(fd);
}
