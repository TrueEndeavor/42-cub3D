/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:50:18 by rogalio           #+#    #+#             */
/*   Updated: 2024/06/04 13:13:06 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	increment_ray_distances(t_ray *ray)
{
	if (ray->sideDistX < ray->sideDistY)
	{
		ray->sideDistX += ray->deltaDistX;
		ray->mapX += ray->stepX;
		ray->side = 0;
	}
	else
	{
		ray->sideDistY += ray->deltaDistY;
		ray->mapY += ray->stepY;
		ray->side = 1;
	}
}

int	is_wall_hit(t_data *data, t_ray *ray)
{
	return (data->world_map[ray->mapX][ray->mapY] > 0);
}

void	calculate_perp_wall_dist(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
		ray->perpWallDist = (ray->mapX - data->game.pos_x + \
			(1 - ray->stepX) / 2) / ray->rayDirX;
	else
		ray->perpWallDist = (ray->mapY - data->game.pos_y + \
			(1 - ray->stepY) / 2) / ray->rayDirY;
}

void	detect_walls(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	initialize_ray_steps(data, ray);
	while (hit == 0)
	{
		increment_ray_distances(ray);
		if (is_wall_hit(data, ray))
			hit = 1;
	}
	calculate_perp_wall_dist(data, ray);
}

void	calculate_wall_parameters(t_data *data, t_ray *ray)
{
	ray->lineHeight = (int)(data->win_height / ray->perpWallDist);
	ray->drawStart = -ray->lineHeight / 2 + data->win_height / 2;
	if (ray->drawStart < 0)
		ray->drawStart = 0;
	ray->drawEnd = ray->lineHeight / 2 + data->win_height / 2;
	if (ray->drawEnd >= data->win_height)
		ray->drawEnd = data->win_height - 1;
}
