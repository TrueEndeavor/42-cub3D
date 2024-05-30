/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:05:12 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/30 14:21:27 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	convert_to_intarray(t_data *data)
{
	int		i;
	int		j;
	//int		**int_map;

	i = 0;
	data->world_map = (int **)malloc(data->map_width * sizeof(int *));
	while (i < data->map_width)
	{
		data->world_map[i] = (int *)malloc(data->map_height * sizeof(int));
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
	/* printf("after int_array creation\n");
	print_map_int_array(int_map, data->map_height, data->map_width);
	i = 0;
	data->world_map = (int **)calloc(data->map_width, sizeof(int *));
	while (i < data->map_width)
	{
		data->world_map[i] = (int *)calloc(data->map_height, sizeof(int));
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
	 */
/* 	 int temp[13][15] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 0, 0, 'N', 0, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
		{1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1},
		{1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1},
		{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
		{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	data->world_map = (int **)malloc(13 * sizeof(int *));
	for (i = 0; i < 13; i++) {
		data->world_map[i] = (int *)malloc(15 * sizeof(int));
	}
	data->map_height = 13;
	data->map_width = 15;
	for (int y = 0; y < 13; y++) {
		for (int x = 0; x < 15; x++) 
		{
			data->world_map[y][x] = temp[y][x];
		}
	} */
	printf("after world map creation\n");
	print_map_int_array(data->world_map, data->map_height, data->map_width);
}
