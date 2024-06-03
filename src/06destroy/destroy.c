/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:51:43 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/03 17:46:05 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_dup_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->dup_map[i])
	{
		free(data->dup_map[i]);
		i++;
	}
	free(data->dup_map);
	data->dup_map = NULL;
}

void	free_maps(t_data *data)
{
	t_list	*current;
	t_list	*next;

	if (data->map)
	{
		current = data->map;
		while (current)
		{
			free(current->content);
			next = current->next;
			free(current);
			current = next;
		}
	}
	if (data->dup_map)
		free_dup_map(data);
}

void	free_textures(t_data *data)
{
	if (data->textures.north_texture)
		free(data->textures.north_texture);
	if (data->textures.east_texture)
		free(data->textures.east_texture);
	if (data->textures.south_texture)
		free(data->textures.south_texture);
	if (data->textures.west_texture)
		free(data->textures.west_texture);
	data->textures.north_texture = NULL;
	data->textures.east_texture = NULL;
	data->textures.south_texture = NULL;
	data->textures.west_texture = NULL;
}

void	destroy_images(t_data *data)
{
	if (data->north_texture)
		mlx_destroy_image(data->mlx_ptr, data->north_texture);
	if (data->east_texture)
		mlx_destroy_image(data->mlx_ptr, data->east_texture);
	if (data->south_texture)
		mlx_destroy_image(data->mlx_ptr, data->south_texture);
	if (data->west_texture)
		mlx_destroy_image(data->mlx_ptr, data->west_texture);
	data->north_texture = NULL;
	data->east_texture = NULL;
	data->south_texture = NULL;
	data->west_texture = NULL;
}

int	on_destroy(t_data *data)
{
	free_maps(data);
	free_textures(data);
	exit(0);
}
