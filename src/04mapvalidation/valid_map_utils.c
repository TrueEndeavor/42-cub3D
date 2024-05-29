/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:05:12 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/29 16:01:49 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	convert_to_intarray(t_data *data)
{
	int		i;
	int		j;
	int		**int_map;

	i = 0;
	int_map = (int **)malloc(data->map_width * sizeof(int *));
	while (i < data->map_width)
	{
		int_map[i] = (int *)malloc(data->map_height * sizeof(int));
		i++;
	}

	i = 0;
	//print_map_array(data);
	while (i < data->map_width)
	{
		if (data->dup_map[i] == NULL)
		{
			break ;
		}
		j = 0;
		while (j < data->map_height)
		{
			if (data->dup_map[i][j] == '1')
				int_map[i][j] = 1;
			else if (data->dup_map[i][j] == '0')
				int_map[i][j] = 0;
			else if (data->dup_map[i][j] == 'N')
				int_map[i][j] = 'N';
			else if (data->dup_map[i][j] == 'E')
				int_map[i][j] = 'E';
			else if (data->dup_map[i][j] == 'S')
				int_map[i][j] = 'S';
			else if (data->dup_map[i][j] == 'W')
				int_map[i][j] = 'W';
			else
				int_map[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	data->world_map = (int **)malloc(data->map_width * sizeof(int *));
	while (i < data->map_width)
	{
		data->world_map[i] = (int *)malloc(data->map_height * sizeof(int));
		i++;
	}
	i = 0;
	while (i < data->map_width)
	{
		j = 0;
		while (j < data->map_height)
		{
			data->world_map[i][j] = int_map[i][j];
			j++;
		}
		i++;
	}
	i = 0;
	while (i < data->map_width)
	{
		free(int_map[i]);
		i++;
	}
	free(int_map);
}