/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:50:42 by rogalio           #+#    #+#             */
/*   Updated: 2024/06/04 16:31:01 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	*init_new_image(t_data *data, int **img_data)
{
	void	*img;

	img = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
	*img_data = (int *)mlx_get_data_addr(img, &data->textures.no_count, \
		&data->textures.ea_count, &data->textures.so_count);
	return (img);
}

void	draw_floor_ceiling(t_data *data, int *img_data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			if (y < data->win_height / 2)
				img_data[y * data->win_width + x] = data->colors.ceiling_hex;
			else
				img_data[y * data->win_width + x] = data->colors.floor_hex;
			x++;
		}
		y++;
	}
}

int	render(t_data *data)
{
	int		x;
	int		*img_data;
	void	*img;
	t_ray	ray;

	x = 0;
	img = init_new_image(data, &img_data);
	draw_floor_ceiling(data, img_data);
	while (x < data->win_width)
	{
		calculate_ray_parameters(data, x, &ray);
		detect_walls(data, &ray);
		calculate_wall_parameters(data, &ray);
		draw_wall(data, x, &ray, img_data);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, img);
	return (0);
}
