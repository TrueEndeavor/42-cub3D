/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:49:07 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/23 14:10:28 by lannur-s         ###   ########.fr       */
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

bool	check_textures_and_colors(t_data *data)
{
	if ((data->textures.no_count != 1) || \
		(data->textures.ea_count != 1) || \
		(data->textures.so_count != 1) || \
		(data->textures.we_count != 1))
	{
		printf("One of the textures is missing or double\n");
		return (false);
		//on_destroy(data);
	}
	if (!check_texture_file(data->textures.north_texture) || \
		!check_texture_file(data->textures.east_texture) || \
		!check_texture_file(data->textures.south_texture) || \
		!check_texture_file(data->textures.west_texture))
	{
		printf("One of the texture files cannot be opened\n");
		return (false);
		//on_destroy(data);
	}
	if ((data->colors.floor_count != 1) || \
		(data->colors.ceiling_count != 1))
	{
		printf("One of the colors is missing or double\n");
		return (false);
		//on_destroy(data);
	}
	return (true);	
}


void	parse_scene_file(t_data *data, char *scene_file)
{
	int		fd;
	char	*line;
	bool	map_started;

	map_started = false;
	fd = check_readable(data, scene_file);
	line = get_next_line(fd);
	if (!line)
	{
		display_error("Map file empty");
		on_destroy(data);
	}
	while (line)
	{
		if (!line)
		{
			on_destroy(data);
			break ;
		}
		if (ft_strlen(line) == 0)
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		trim_newline(line);
		if (map_started)
		{
			if (!load_map(data, trim_newline(line)))
				on_destroy(data);
		}
		else 
		{
			if (is_texture_line(line) || is_color_line(line))
			{
				printf("texture/color : %s\n", line);
				parse_line(line, data);
			}
			else if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			{
				printf("be careful, it is a empty line\n");
			}
			else if (is_map_line(line))
			{
				printf("map : %s\n", line);
				if (!check_textures_and_colors(data))
				{
					on_destroy(data);
				}
				map_started = true;
				if (!load_map(data, trim_newline(line)))
					on_destroy(data);
			}
		}
		free(line);
		line = get_next_line(fd);
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
