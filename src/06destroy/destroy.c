/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:51:43 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/28 14:49:03 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_maps(t_data *data)
{
	t_list	*current;
	t_list	*next;
	int		i;

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
	{
		i = 0;
		while (data->dup_map[i])
		{
			free(data->dup_map[i]);
			i++;
		}
		free(data->dup_map);
	}
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
}

int	on_destroy(t_data *data)
{
	(void) *data;
	exit(0);
}
