/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:32:27 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/22 13:45:52 by lannur-s         ###   ########.fr       */
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

int	is_texture_line(const char *line)
{
	return (ft_strncmp(line, "NO", 2) == 0 || \
			ft_strncmp(line, "EA", 2) == 0 || \
			ft_strncmp(line, "SO", 2) == 0 || \
			ft_strncmp(line, "WE", 2) == 0);
}

int	is_color_line(const char *line)
{
	return (ft_strncmp(line, "C", 1) == 0 || ft_strncmp(line, "F", 1) == 0);
}

int	parse_int(char **str)
{
	int	num;

	num = 0;
	while (**str >= '0' && **str <= '9')
	{
		num = num * 10 + (**str - '0');
		(*str)++;
	}
	return (num);
}