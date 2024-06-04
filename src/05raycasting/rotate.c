/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:02:33 by rogalio           #+#    #+#             */
/*   Updated: 2024/06/04 13:50:11 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_left(t_data *data, double rot_speed)
{
	double oldDirX = data->game.dir_x;
	data->game.dir_x = data->game.dir_x * cos(rot_speed) - data->game.dir_y * sin(rot_speed);
	data->game.dir_y = oldDirX * sin(rot_speed) + data->game.dir_y * cos(rot_speed);
	double oldPlaneX = data->game.plane_x;
	data->game.plane_x = data->game.plane_x * cos(rot_speed) - data->game.plane_y * sin(rot_speed);
	data->game.plane_y = oldPlaneX * sin(rot_speed) + data->game.plane_y * cos(rot_speed);
}

void	rotate_right(t_data *data, double rot_speed)
{
	double oldDirX = data->game.dir_x;
	data->game.dir_x = data->game.dir_x * cos(-rot_speed) - data->game.dir_y * sin(-rot_speed);
	data->game.dir_y = oldDirX * sin(-rot_speed) + data->game.dir_y * cos(-rot_speed);
	double oldPlaneX = data->game.plane_x;
	data->game.plane_x = data->game.plane_x * cos(-rot_speed) - data->game.plane_y * sin(-rot_speed);
	data->game.plane_y = oldPlaneX * sin(-rot_speed) + data->game.plane_y * cos(-rot_speed);
}
