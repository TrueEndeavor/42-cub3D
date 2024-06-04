/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:50:18 by rogalio           #+#    #+#             */
/*   Updated: 2024/06/04 13:10:53 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calculate_ray_parameters(t_data *data, int x, t_ray *ray)
{
	ray->cameraX = 2 * x / (double)data->win_width - 1;
	ray->rayDirX = data->game.dir_x + data->game.plane_x * ray->cameraX;
	ray->rayDirY = data->game.dir_y + data->game.plane_y * ray->cameraX;
	ray->mapX = (int)data->game.pos_x;
	ray->mapY = (int)data->game.pos_y;
	ray->deltaDistX = fabs(1 / ray->rayDirX);
	ray->deltaDistY = fabs(1 / ray->rayDirY);
}

void	initialize_ray_steps(t_data *data, t_ray *ray)
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (data->game.pos_x - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - data->game.pos_x) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (data->game.pos_y - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - data->game.pos_y) * ray->deltaDistY;
	}
}
