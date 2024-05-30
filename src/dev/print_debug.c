/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:44:25 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/30 14:28:07 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3D.h"

void	print_colors(t_data *data)
{
	printf("\n****PRINT COLORS****\n");
	printf("Ceiling rgb = %d, %d, %d\n", data->colors.ceiling.red, \
		data->colors.ceiling.green, data->colors.ceiling.blue);
	printf("Ceiling count = %d\n", data->colors.ceiling_count);
	printf("Floor rgb = %d, %d, %d\n", data->colors.floor.red, \
		data->colors.floor.green, data->colors.floor.blue);
	printf("Floor count = %d\n", data->colors.floor_count);
}

void	print_content(void *c)
{
	printf("%s", (char *)c);
	printf("\n");
}

void	print_map(t_data *data)
{
	printf("\n****PRINT MAP****\n");
	ft_lstiter(data->map, &print_content);
}

void	print_map_array(t_data *data)
{
	int	i;

	i = 0;
	printf("\n****PRINT MAP CHAR ARRAY****\n");
	while (data->dup_map[i] != NULL)
	{
		printf("%s\n", data->dup_map[i]);
		i++;
	}
}

void	print_map_int_array(int **int_map, int height, int width)
{
	int	i;
	int	j;

	printf("\n****PRINT MAP INT ARRAY****\n");
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (int_map[i][j] == 'N')
				printf("N");
			else
				printf("%d", int_map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

void	print_textures(t_data *data)
{
	printf("\n****PRINT TEXTURES****\n");
	printf("North texture = %s\n", data->textures.north_texture);
	printf("East texture = %s\n", data->textures.east_texture);
	printf("South texture = %s\n", data->textures.south_texture);
	printf("West texture = %s\n", data->textures.west_texture);
	printf("North count = %d\n", data->textures.no_count);
	printf("East count = %d\n", data->textures.ea_count);
	printf("South count = %d\n", data->textures.so_count);
	printf("West count = %d\n", data->textures.we_count);
}

void	print_all(t_data *data)
{
	print_textures(data);
	print_colors(data);
	print_map(data);
	printf("\n");
}
