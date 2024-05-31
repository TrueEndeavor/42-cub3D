/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:47:25 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/31 16:28:35 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_color(char *line, int type, t_colors *colors)
{
	trim_whitespace(&line);
	if (type == CEILING)
		colors->ceiling.red = parse_int(&line);
	if (type == FLOOR)
		colors->floor.red = parse_int(&line);
	if (*line == ',')
		line++;
	trim_whitespace(&line);
	if (type == CEILING)
		colors->ceiling.green = parse_int(&line);
	if (type == FLOOR)
		colors->floor.green = parse_int(&line);
	if (*line == ',')
		line++;
	trim_whitespace(&line);
	if (type == CEILING)
		colors->ceiling.blue = parse_int(&line);
	if (type == FLOOR)
		colors->floor.blue = parse_int(&line);
	if (type == CEILING)
		colors->ceiling_hex = rgb_to_hex(colors->ceiling);
	if (type == FLOOR)
		colors->floor_hex = rgb_to_hex(colors->floor);
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

	type = get_color_type(line);
	trim_whitespace(&line);
	if (type == CEILING)
	{
		get_color(line + 1, type, colors);
		colors->ceiling_count++;
	}
	else if (type == FLOOR)
	{
		get_color(line + 1, type, colors);
		colors->floor_count++;
	}
}
