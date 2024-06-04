/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:11:01 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/04 12:21:34 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_outer_enclosure(t_data *data, int i, int j)
{
	if (!data->dup_map || !data->dup_map[i] || !data->dup_map[i][j])
		return (0);
	while (ft_iswhitespace(data->dup_map[i][j]))
		j++;
	while (data->dup_map[i][j])
	{
		if (data->dup_map[i][j] == 'N' || \
			data->dup_map[i][j] == 'E' || \
			data->dup_map[i][j] == 'S' || \
			data->dup_map[i][j] == 'W')
			return (2);
		else if (data->dup_map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	is_row_enclosed(char *row)
{
	int	len;
	int	i;
	int	left_wall;
	int	right_wall;

	len = ft_strlen(row);
	left_wall = 0;
	right_wall = 0;
	i = 0;
	while (i < len && row[i] == ' ')
		i++;
	if (i < len && row[i] == '1')
		left_wall = 1;
	i = len - 1;
	while (i >= 0 && row[i] == ' ')
		i--;
	if (i >= 0 && row[i] == '1')
		right_wall = 1;
	return (left_wall && right_wall);
}

int	is_column_enclosed(t_data *data, int col)
{
	int	i;
	int	top_wall;
	int	bottom_wall;

	i = 0;
	top_wall = 0;
	bottom_wall = 0;
	while (i < data->map_height && \
		(data->dup_map[i][col] == ' ' || data->dup_map[i][col] == '\0'))
	{
		i++;
	}
	if (i < data->map_height && data->dup_map[i][col] == '1')
		top_wall = 1;
	i = data->map_height - 1;
	while (i >= 0 && \
		(data->dup_map[i][col] == ' ' || data->dup_map[i][col] == '\0'))
		i--;
	if (i >= 0 && data->dup_map[i][col] == '1')
		bottom_wall = 1;
	return (top_wall && bottom_wall);
}

int	check_walls(t_data *data)
{
	int	i;
	int	j;

	if (!set_dup_map(data))
		return (0);
	if (check_outer_enclosure(data, 0, 0) != 1)
		return (0);
	i = 1;
	while (i < data->map_height - 1)
	{
		if (!is_row_enclosed(data->dup_map[i]))
			return (0);
		i++;
	}
	j = 0;
	while (j < data->map_width)
	{
		if (!is_column_enclosed(data, j))
			return (0);
		j++;
	}
	if (check_outer_enclosure(data, 0, 0) != 1)
		return (0);
	return (1);
}
