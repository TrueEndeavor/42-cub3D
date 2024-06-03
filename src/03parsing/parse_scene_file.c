/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:49:07 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/03 11:14:18 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parse_line(char *line, t_data *data, bool *tex_flag, bool *col_flag)
{
	if (!line)
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

int	parse_non_map_lines(int fd, t_data *data, bool *tex_flag, bool *col_flag)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		trim_newline(line);
		if (ft_strlen(line) == 0)
		{
			free(line);
			continue ;
		}
		parse_line(line, data, tex_flag, col_flag);
		if (is_map_line(line))
		{
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	parse_map_lines(int fd, t_data *data)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		trim_newline(line);
		if (is_map_line(line))
		{
			if (!load_map(data, line))
			{
				free(line);
				return (0);
			}
			data->map_height++;
		}
		else
		{
			free(line);
			display_error("Map appears in the wrong position within the file");
			return (0);
		}
	}
	return (1);
}

int	validate_scene(t_data *data, bool tex_flag, bool col_flag)
{
	int	error_code;

	error_code = check_textures_and_colors(data, tex_flag, col_flag);
	if (error_code != 0)
	{
		display_error(get_error_message(error_code));
		on_destroy(data);
		return (0);
	}
	return (1);
}

void	parse_scene_file(t_data *data, char *scene_file)
{
	int		fd;
	bool	tex_flag;
	bool	col_flag;

	tex_flag = false;
	col_flag = false;
	fd = check_readable(data, scene_file);
	if (fd < 0 || !parse_non_map_lines(fd, data, &tex_flag, &col_flag))
	{
		display_error("The file is empty or incorrect format");
		on_destroy(data);
		return ;
	}
	if (!validate_scene(data, tex_flag, col_flag) || !parse_map_lines(fd, data))
	{
		on_destroy(data);
		return ;
	}
	close(fd);
	print_map_int_array(data->world_map, data->map_height, data->map_width);
}
