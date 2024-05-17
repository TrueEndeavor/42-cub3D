/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_initialize_map.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:49:07 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/17 12:41:32 by lannur-s         ###   ########.fr       */
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

void	read_and_initialize_map(t_data *data, char *map)
{
	int		fd;
	char	*line;

	fd = check_readable(data, map);
	line = get_next_line(fd);
	if (!line)
	{
		display_error("Map file empty");
		on_destroy(data);
	}
	data->width = (int) ft_strlen(line) - 1;
	while (line)
	{
		if (!line)
			on_destroy(data);
		data->height++;
		if (!load_map(data, trim_newline(line)))
			on_destroy(data);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
