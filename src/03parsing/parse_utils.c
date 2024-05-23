/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:32:27 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/23 16:22:50 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	trim_whitespace(char **line)
{
	while (ft_iswhitespace(**line) && **line != '\n')
	{
		(*line)++;
	}
}

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

int	is_texture_line(char *line)
{
	return (ft_strncmp(line, "NO", 2) == 0 || \
			ft_strncmp(line, "EA", 2) == 0 || \
			ft_strncmp(line, "SO", 2) == 0 || \
			ft_strncmp(line, "WE", 2) == 0);
}

int	is_color_line(char *line)
{
	return (ft_strncmp(line, "C", 1) == 0 || ft_strncmp(line, "F", 1) == 0);
}

int	is_map_line(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '1' && *line != '0' &&
			*line != 'N' && *line != 'S' && *line != 'E' && *line != 'W')
		{
			return (0);
		}
		line++;
	}
	return (1);
}
