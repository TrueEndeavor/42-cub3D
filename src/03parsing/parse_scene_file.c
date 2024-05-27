/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:49:07 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/27 11:25:18 by lannur-s         ###   ########.fr       */
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
	bool	map_started;
	int		error_code;

	error_code = 0;
	map_started = false;
	fd = check_readable(data, scene_file);
	line = get_next_line(fd);
	if (!line)
	{
		display_error("The file is empty");
		on_destroy(data);
		return ;
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
				map_started = true;
				error_code = check_textures_and_colors(data);
				if (error_code != 0)
				{
					display_error(get_error_message(error_code));
					on_destroy(data);
					return;
				}
				on_destroy(data);
				break ;
			}
			if (!load_map(data, trim_newline(line)))
				on_destroy(data);
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
