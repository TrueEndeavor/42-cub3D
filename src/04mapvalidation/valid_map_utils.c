/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:05:12 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/03 15:57:04 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	convert_to_intarray(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	data->world_map = (int **)ft_calloc(data->map_height, sizeof(int *));
	while (i < data->map_height)
	{
		data->world_map[i] = (int *)ft_calloc(data->map_width, sizeof(int));
		i++;
	}

	i = 0;
	while (i < data->map_height)
	{
		if (data->dup_map[i] == NULL)
		{
			break ;
		}
		j = 0;
		while (j < data->map_width)
		{
			if (data->dup_map[i][j] == '1')
				data->world_map[i][j] = 1;
			else if (data->dup_map[i][j] == '0')
				data->world_map[i][j] = 0;
			else if (data->dup_map[i][j] == 'N' || \
				(data->dup_map[i][j] == 'E') || \
				(data->dup_map[i][j] == 'S') || \
				(data->dup_map[i][j] == 'W'))
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
	print_map_int_array(data->world_map, data->map_height, data->map_width);
}
