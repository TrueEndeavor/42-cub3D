/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:49:07 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/21 14:54:59 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*trim_newline(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
	}
	return (str);
}
int get_direction(const char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return NORTH;
	if (ft_strncmp(line, "EA", 2) == 0)
		return EAST;
	if (ft_strncmp(line, "SO", 2) == 0)
		return SOUTH;
	if (ft_strncmp(line, "WE", 2) == 0)
		return WEST;
	return -1;
}

void	parse_scene_file(t_data *data, char *scene_file)
{
	int		fd;
	char	*line;
	int     direction;
	t_textures  *textures;
	
	
	textures = {NULL, 0, NULL, 0, NULL, 0, NULL, 0};
	fd = check_readable(data, scene_file);
	line = get_next_line(fd);
	if (!line)
	{
		display_error("Map file empty");
		on_destroy(data);
	}
	//data->width = (int) ft_strlen(line) - 1;
	while (line)
	{
		if (!line) // maybe to skip an empty newline, empty and what not
			on_destroy(data);
		parse_line(line, data);
		if ((ft_strncmp(line, "NO", 2) == 0) || \
			(ft_strncmp(line, "EA", 2) == 0) || \
			(ft_strncmp(line, "SO", 2) == 0) || \
			(ft_strncmp(line, "WE", 2) == 0))
		{
			if (ft_strncmp(line, "NO", 2) == 0)
				direction = NORTH;
			if (ft_strncmp(line, "EA", 2) == 0)
				direction = EAST;
			if (ft_strncmp(line, "SO", 2) == 0)
				direction = SOUTH;
			if (ft_strncmp(line, "WE", 2) == 0)
				direction = WEST;				
			printf("....printing the line = %s\n", line);
			parse_textures(direction, textures, line+2);
		}
		if ((ft_strncmp(line, "C", 1) == 0) || \
			(ft_strncmp(line, "F", 1) == 0))
		{
			printf("....printing the line = %s\n", line);
			//parse_colors();
		}
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
