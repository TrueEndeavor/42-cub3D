/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:47:25 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/22 13:46:18 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_color(char *line, t_rgb *rgb)
{
	trim_whitespace(&line);
	rgb->red = parse_int(&line);
	if (*line == ',')
		line++;
	trim_whitespace(&line);
	rgb->green = parse_int(&line);
	if (*line == ',')
		line++;
	trim_whitespace(&line);
	rgb->blue = parse_int(&line);
}

int	get_color_type(const char *line)
{
	if (ft_strncmp(line, "F", 1) == 0)
		return (FLOOR);
	if (ft_strncmp(line, "C", 1) == 0)
		return (CEILING);
	return (-1);
}

void	parse_color_line(char *line, t_colors *colors)
{
	int		type;
	t_rgb	rgb_c;
	t_rgb	rgb_f;

	rgb_c = (t_rgb){0, 0, 0};
	rgb_f = (t_rgb){0, 0, 0};
	type = get_color_type(line);
	(void) colors;

	trim_whitespace(&line);
	if (type == CEILING)
	{
		get_color(line + 1, &rgb_c);
	}
	else if (type == FLOOR)
	{
		get_color(line + 1, &rgb_f);
	}
	// set colors into data
}
