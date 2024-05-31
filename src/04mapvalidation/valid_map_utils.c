/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:05:12 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/31 10:54:04 by lannur-s         ###   ########.fr       */
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
	//print_map_array(data);
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
			else if (data->dup_map[i][j] == 'N')
				data->world_map[i][j] = 'N';
			else if (data->dup_map[i][j] == 'E')
				data->world_map[i][j] = 'E';
			else if (data->dup_map[i][j] == 'S')
				data->world_map[i][j] = 'S';
			else if (data->dup_map[i][j] == 'W')
				data->world_map[i][j] = 'W';
			else
				data->world_map[i][j] = 0;
			j++;
		}
		printf("\n");
		i++;
	}
	//printf("after world map creation\n");
	//print_map_int_array(data->world_map, data->map_height, data->map_width);
}
