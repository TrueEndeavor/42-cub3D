/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:13:51 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/04 13:53:39 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	on_keypress(int key, t_data *data)
{
	double	moveSpeed = 0.6;
	double	rotSpeed = 0.3;

	if (key == 65307)
	{
		on_destroy(data);
		exit(0);
	}
	if (key == 119)
		move_up(data, moveSpeed);
	if (key == 115)
		move_down(data, moveSpeed);
	if (key == 97)
		rotate_left(data, rotSpeed);
	if (key == 100)
		rotate_right(data, rotSpeed);
	return (0);
}

int	on_mouse(int x, int y, t_data *data)
{
	static int	lastX = screenWidth / 2;
	int			diffX = x - lastX;
	double		rotSpeed = 0.005 * diffX;
	(void)data;
	(void)y;
	double		oldDirX =  data->game.dir_x;
	data->game.dir_x = data->game.dir_x * cos(-rotSpeed) - data->game.dir_y * sin(-rotSpeed);
	data->game.dir_y = oldDirX * sin(-rotSpeed) + data->game.dir_y * cos(-rotSpeed);
	double 		oldPlaneX = data->game.plane_x;
	data->game.plane_x = data->game.plane_x * cos(-rotSpeed) - data->game.plane_y * sin(-rotSpeed);
	data->game.plane_y = oldPlaneX * sin(-rotSpeed) + data->game.plane_y * cos(-rotSpeed);
	lastX = x;
	return (0);
}

















