/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:50:18 by rogalio           #+#    #+#             */
/*   Updated: 2024/05/31 17:55:17 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void calculate_ray_parameters(t_data *data, int x, t_ray *ray)
{
    ray->cameraX = 2 * x / (double)data->win_width - 1;
    ray->rayDirX = data->game.dir_x + data->game.plane_x * ray->cameraX;
    ray->rayDirY = data->game.dir_y + data->game.plane_y * ray->cameraX;
    ray->mapX = (int)data->game.pos_x;
    ray->mapY = (int)data->game.pos_y;
    ray->deltaDistX = fabs(1 / ray->rayDirX);
    ray->deltaDistY = fabs(1 / ray->rayDirY);
}

void initialize_ray_steps(t_data *data, t_ray *ray)
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

void detect_walls(t_data *data, t_ray *ray)
{
    int hit;

    hit = 0;
    initialize_ray_steps(data, ray);
    while (hit == 0)
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
        if (data->world_map[ray->mapX][ray->mapY] > 0)
            hit = 1;
    }
    if (ray->side == 0)
        ray->perpWallDist = (ray->mapX - data->game.pos_x + (1 - ray->stepX) / 2) / ray->rayDirX;
    else
        ray->perpWallDist = (ray->mapY - data->game.pos_y + (1 - ray->stepY) / 2) / ray->rayDirY;
}

void calculate_wall_parameters(t_data *data, t_ray *ray)
{
    ray->lineHeight = (int)(data->win_height / ray->perpWallDist);
    ray->drawStart = -ray->lineHeight / 2 + data->win_height / 2;
    if (ray->drawStart < 0) ray->drawStart = 0;
    ray->drawEnd = ray->lineHeight / 2 + data->win_height / 2;
    if (ray->drawEnd >= data->win_height) ray->drawEnd = data->win_height - 1;
}