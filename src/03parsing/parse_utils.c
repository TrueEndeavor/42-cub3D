/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:32:27 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/31 16:01:27 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	trim_whitespace(char **line)
{
	char	*end;

	while (ft_iswhitespace((unsigned char)**line))
	{
		(*line)++;
	}
	if (*line[0] == '\0')
		return ;
	end = *line + ft_strlen(*line) - 1;
	while (end > *line && ft_iswhitespace((unsigned char)*end))
		end--;
	end[1] = '\0';
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
	while (*line && ft_iswhitespace((unsigned char)*line))
		line++;
	return (ft_strncmp(line, "NO", 2) == 0 || \
			ft_strncmp(line, "EA", 2) == 0 || \
			ft_strncmp(line, "SO", 2) == 0 || \
			ft_strncmp(line, "WE", 2) == 0);
}

int	is_color_line(char *line)
{
	while (*line && ft_iswhitespace((unsigned char)*line))
		line++;
	return (ft_strncmp(line, "C", 1) == 0 || ft_strncmp(line, "F", 1) == 0);
}

int	is_map_line(char *line)
{
	if (*line == '\0')
	{
		return (0);
	}
	while (*line)
	{
		if (*line != ' ' && *line != '1' && *line != '0' && \
			*line != 'N' && *line != 'S' && *line != 'E' && *line != 'W')
		{
			return (0);
		}
		line++;
	}
	return (1);
}
