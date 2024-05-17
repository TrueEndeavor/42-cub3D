/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:51:43 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/17 11:45:34 by lannur-s         ###   ########.fr       */
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
	if (data->floor_ptr)
		mlx_destroy_image(data->mlx_ptr, data->floor_ptr);
	if (data->paw_ptr)
		mlx_destroy_image(data->mlx_ptr, data->paw_ptr);
	if (data->wall_ptr)
		mlx_destroy_image(data->mlx_ptr, data->wall_ptr);
	if (data->player_ptr)
		mlx_destroy_image(data->mlx_ptr, data->player_ptr);
	if (data->flower_ptr)
		mlx_destroy_image(data->mlx_ptr, data->flower_ptr);
	if (data->lover_ptr)
		mlx_destroy_image(data->mlx_ptr, data->lover_ptr);
	if (data->fluffy_love_ptr)
		mlx_destroy_image(data->mlx_ptr, data->fluffy_love_ptr);		
}

int	on_destroy(t_data *data)
{
	(void) *data;
	exit(0);
}
