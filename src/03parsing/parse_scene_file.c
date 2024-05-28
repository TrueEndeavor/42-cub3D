/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:49:07 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/28 13:44:27 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parse_line(char *line, t_data *data, bool *tex_flag, bool *col_flag)
{
	if (line == NULL)
		return ;
	trim_whitespace(&line);
	if (is_texture_line(line))
	{
		parse_texture_line(line, &data->textures);
		*tex_flag = true;
	}
	else if (is_color_line(line))
	{
		parse_color_line(line, &data->colors);
		*col_flag = true;
	}
}

void	parse_scene_file(t_data *data, char *scene_file)
{
	int		fd;
	char	*line;
	bool	map_flag;
	bool	tex_flag;
	bool	col_flag;
	int		error_code;

	tex_flag = false;
	col_flag = false;
	error_code = 0;
	map_flag = false;
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
		if (!map_flag)
		{
			trim_newline(line);
			if (ft_strlen(line) == 0)
			{
				free(line);
				line = get_next_line(fd);
				continue ;
			}
			if (is_texture_line(line) || is_color_line(line))
			{
				parse_line(line, data, &tex_flag, &col_flag);
			}
			else if (is_map_line(line))
			{
				if (tex_flag && col_flag)
				{
					error_code = check_textures_and_colors(data, tex_flag, col_flag);
					if (error_code != 0)
					{
						display_error(get_error_message(error_code));
						on_destroy(data);
						return ;
					}
				}
				map_flag = true;
			}
		}
		if (map_flag)
		{
			if (load_map(data, line))
				data->map_height++;
			else
			{
				on_destroy(data);
				return ;
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	error_code = check_textures_and_colors(data, tex_flag, col_flag);
	if (error_code != 0)
	{
		display_error(get_error_message(error_code));
		on_destroy(data);
		return ;
	}
	close(fd);
}
