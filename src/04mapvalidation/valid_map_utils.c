/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:05:12 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/03 18:30:02 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	**allocate_world_map(int height, int width)
{
	int	**world_map;
	int	i;

	world_map = (int **)ft_calloc(height, sizeof(int *));
	if (!world_map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		world_map[i] = (int *)ft_calloc(width, sizeof(int));
		if (!world_map[i])
			return (NULL);
		i++;
	}
	return (world_map);
}

static void	fill_world_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->dup_map[i][j] == '1')
				data->world_map[i][j] = 1;
			else if (data->dup_map[i][j] == '0')
				data->world_map[i][j] = 0;
			else if (strchr("NESW", data->dup_map[i][j]))
			{
				data->game.pos_x = i;
				data->game.pos_y = j;
				data->world_map[i][j] = 0;
			}
			else
				data->world_map[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	convert_to_intarray(t_data *data)
{
	data->world_map = allocate_world_map(data->map_height, data->map_width);
	if (!data->world_map)
		return ;
	fill_world_map(data);
	print_map_int_array(data->world_map, data->map_height, data->map_width);
}
