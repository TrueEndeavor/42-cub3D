/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:51:42 by rogalio           #+#    #+#             */
/*   Updated: 2024/06/04 13:42:45 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	calculate_wall_x(t_data *data, t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = data->game.pos_y + ray->perpWallDist * ray->rayDirY;
	else
		wall_x = data->game.pos_x + ray->perpWallDist * ray->rayDirX;
	return (wall_x - floor(wall_x));
}

int	calculate_tex_x(t_data *data, t_ray *ray, double wall_x)
{
	int	tex_x;

	tex_x = (int)(wall_x * (double)(data->textures.east_width));
	if (ray->side == 0 && ray->rayDirX > 0)
		tex_x = data->textures.east_width - tex_x - 1;
	if (ray->side == 1 && ray->rayDirY < 0)
		tex_x = data->textures.east_width - tex_x - 1;
	return (tex_x);
}

int	get_wall_color(t_data *data, t_ray *ray, int tex_x, int tex_y)
{
	int	color;

	if (ray->side == 0 && ray->rayDirX < 0)
		color = data->textures.north_data[tex_y * data->textures.north_width + tex_x];
	else if (ray->side == 0 && ray->rayDirX > 0)
		color = data->textures.south_data[tex_y * data->textures.south_width + tex_x];
	else if (ray->side == 1 && ray->rayDirY < 0)
		color = data->textures.west_data[tex_y * data->textures.west_width + tex_x];
	else
		color = data->textures.east_data[tex_y * data->textures.east_width + tex_x];
	if (ray->side == 1)
		color = (color >> 1) & 8355711;
	return (color);
}

void	draw_wall_column(t_data *data, t_ray *ray, int x, int *img_data, int tex_x)
{
	int	tex_y;
	int	color;
	int	d;

	while (ray->drawStart < ray->drawEnd)
	{
		d = ray->drawStart * 256 - data->win_height * 128 + \
			ray->lineHeight * 128;
		tex_y = ((d * data->textures.east_height) / ray->lineHeight) / 256;
		color = get_wall_color(data, ray, tex_x, tex_y);
		img_data[ray->drawStart * data->win_width + x] = color;
		ray->drawStart++;
	}
}

void	draw_wall(t_data *data, int x, t_ray *ray, int *img_data)
{
	double	wall_x;
	int		tex_x;

	wall_x = calculate_wall_x(data, ray);
	tex_x = calculate_tex_x(data, ray, wall_x);
	draw_wall_column(data, ray, x, img_data, tex_x);
}
