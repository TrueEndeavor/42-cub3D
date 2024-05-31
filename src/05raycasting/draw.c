/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:51:42 by rogalio           #+#    #+#             */
/*   Updated: 2024/05/31 17:54:57 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double calculate_wallX(t_data *data, t_ray *ray)
{
    double wallX;
    if (ray->side == 0)
        wallX = data->game.pos_y + ray->perpWallDist * ray->rayDirY;
    else
        wallX = data->game.pos_x + ray->perpWallDist * ray->rayDirX;
    return wallX - floor(wallX);
}

int calculate_texX(t_data *data, t_ray *ray, double wallX)
{
    int texX = (int)(wallX * (double)(data->textures.east_width));
    if (ray->side == 0 && ray->rayDirX > 0)
        texX = data->textures.east_width - texX - 1;
    if (ray->side == 1 && ray->rayDirY < 0)
        texX = data->textures.east_width - texX - 1;
    return texX;
}

int get_wall_color(t_data *data, t_ray *ray, int texX, int texY)
{
    int color;
    if (ray->side == 0 && ray->rayDirX < 0)
        color = data->textures.north_data[texY * data->textures.north_width + texX];
    else if (ray->side == 0 && ray->rayDirX > 0)
        color = data->textures.south_data[texY * data->textures.south_width + texX];
    else if (ray->side == 1 && ray->rayDirY < 0)
        color = data->textures.west_data[texY * data->textures.west_width + texX];
    else
        color = data->textures.east_data[texY * data->textures.east_width + texX];
    if (ray->side == 1)
        color = (color >> 1) & 8355711; // Couleur plus sombre pour les côtés
    return color;
}

void draw_wall_column(t_data *data, t_ray *ray, int x, int *img_data, int texX)
{
    int texY;
    int color;

    while (ray->drawStart < ray->drawEnd)
    {
        int d = ray->drawStart * 256 - data->win_height * 128 + ray->lineHeight * 128;
        texY = ((d * data->textures.east_height) / ray->lineHeight) / 256;
        color = get_wall_color(data, ray, texX, texY);
        img_data[ray->drawStart * data->win_width + x] = color;
        ray->drawStart++;
    }
}

void draw_wall(t_data *data, int x, t_ray *ray, int *img_data)
{
    double wallX;
    int texX;

    wallX = calculate_wallX(data, ray);
    texX = calculate_texX(data, ray, wallX);
    draw_wall_column(data, ray, x, img_data, texX);
}