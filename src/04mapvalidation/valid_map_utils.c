/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:05:12 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/03 21:03:26 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	allocate_memory(t_data *data)
{
	int	i;

	i = 0;
	data->world_map = (int **)ft_calloc(data->map_height, sizeof(int *));
	while (i < data->map_height)
	{
		data->world_map[i] = (int *)ft_calloc(data->map_width, sizeof(int));
		i++;
	}
}

void	initialize_world_map(t_data *data, int i, int j)
{
	if (data->dup_map[i][j] == '1')
		data->world_map[i][j] = 1;
	else if (data->dup_map[i][j] == '0')
		data->world_map[i][j] = 0;
	else if (data->dup_map[i][j] == 'N' || data->dup_map[i][j] == 'E' || \
		data->dup_map[i][j] == 'S' || data->dup_map[i][j] == 'W')
	{
		data->game.pos_x = i;
		data->game.pos_y = j;
		data->world_map[i][j] = 0;
	}
	else
		data->world_map[i][j] = 0;
}

void	convert_to_intarray(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	allocate_memory(data);
	while (i < data->map_height && data->dup_map[i] != NULL)
	{
		j = 0;
		while (j < data->map_width)
		{
			initialize_world_map(data, i, j);
			j++;
		}
		i++;
	}
}
