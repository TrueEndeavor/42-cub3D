/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:49:07 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/23 16:32:38 by lannur-s         ###   ########.fr       */
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
	
	/* printf("****PARSE COLORS****\n");
	printf("data->colors.ceiling.rgb = %d, %d, %d\n", data->colors.ceiling.red, data->colors.ceiling.green, data->colors.ceiling.blue);
	printf("data->colors.ceiling_count = %d\n", data->colors.ceiling_count);
	
	printf("data->colors.floor.rgb = %d, %d, %d\n", data->colors.floor.red, data->colors.floor.green, data->colors.floor.blue);
	printf("data->colors.floor_count = %d\n", data->colors.floor_count); */
}

bool	check_textures_and_colors(t_data *data, bool map_started)
{
	bool	status;
	
	status = false;
	if (((data->textures.no_count != 1) || \
		(data->textures.ea_count != 1) || \
		(data->textures.so_count != 1) || \
		(data->textures.we_count != 1)))
	{
		if (map_started)
			return (display_error("Map is either in the top or middle of the scene"));
		return (display_error("One of the textures is missing or double"));
		//on_destroy(data);
	}
	else if ((!check_texture_file(data->textures.north_texture) || \
		!check_texture_file(data->textures.east_texture) || \
		!check_texture_file(data->textures.south_texture) || \
		!check_texture_file(data->textures.west_texture)))
	{
		if (map_started)
			return (display_error("Map is either in the top or middle of the scene"));
		return (display_error("One of the texture files cannot be opened"));
		//on_destroy(data);
	}
	else if (((data->colors.floor_count != 1) || \
		(data->colors.ceiling_count != 1)))
	{
		if (map_started)
			return (display_error("Map is either in the top or middle of the scene"));
		return (display_error("One of the colors is missing or double"));
		//on_destroy(data);
	}
	else if (!((data->colors.floor.red >= 0) && (data->colors.floor.red <= 255)) || \
		!((data->colors.floor.green >= 0) && (data->colors.floor.green <= 255)) || \
		!((data->colors.floor.blue >= 0) && (data->colors.floor.blue <= 255)))
	{
		//if (map_started)
		//	return (display_error("Map is either in the top or middle of the scene"));
		return (display_error("RGB values of one of the colors is missing"));
		//on_destroy(data);
	}	
	else
	{
		status = true;
	}
	return (status);	
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
		trim_newline(line);
		if (ft_strlen(line) == 0)
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (map_started)
		{
			if (!load_map(data, trim_newline(line)))
				on_destroy(data);
		}
		else 
		{
			if (is_texture_line(line) || is_color_line(line))
			{
				parse_line(line, data);
			}
			else if (is_map_line(line))
			{
				if (!check_textures_and_colors(data, map_started))
				{
					//display_error("grave");
					on_destroy(data);
					break ;
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
