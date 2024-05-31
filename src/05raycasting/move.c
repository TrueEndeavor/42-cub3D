/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:49:05 by rogalio           #+#    #+#             */
/*   Updated: 2024/05/31 17:49:30 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void move_up(t_data *data, double move_speed)
{
    if (data->world_map[(int)(data->game.pos_x + data->game.dir_x * move_speed)][(int)data->game.pos_y] == 0)
        data->game.pos_x += data->game.dir_x * move_speed;
    if (data->world_map[(int)data->game.pos_x][(int)(data->game.pos_y + data->game.dir_y * move_speed)] == 0)
        data->game.pos_y += data->game.dir_y * move_speed;
}

void move_down(t_data *data, double move_speed)
{
    if (data->world_map[(int)(data->game.pos_x - data->game.dir_x * move_speed)][(int)data->game.pos_y] == 0)
        data->game.pos_x -= data->game.dir_x * move_speed;
    if (data->world_map[(int)data->game.pos_x][(int)(data->game.pos_y - data->game.dir_y * move_speed)] == 0)
        data->game.pos_y -= data->game.dir_y * move_speed;
}

void rotate_left(t_data *data, double rot_speed)
{
    double oldDirX = data->game.dir_x;
    data->game.dir_x = data->game.dir_x * cos(rot_speed) - data->game.dir_y * sin(rot_speed);
    data->game.dir_y = oldDirX * sin(rot_speed) + data->game.dir_y * cos(rot_speed);
    double oldPlaneX = data->game.plane_x;
    data->game.plane_x = data->game.plane_x * cos(rot_speed) - data->game.plane_y * sin(rot_speed);
    data->game.plane_y = oldPlaneX * sin(rot_speed) + data->game.plane_y * cos(rot_speed);
}

void rotate_right(t_data *data, double rot_speed)
{
    double oldDirX = data->game.dir_x;
    data->game.dir_x = data->game.dir_x * cos(-rot_speed) - data->game.dir_y * sin(-rot_speed);
    data->game.dir_y = oldDirX * sin(-rot_speed) + data->game.dir_y * cos(-rot_speed);
    double oldPlaneX = data->game.plane_x;
    data->game.plane_x = data->game.plane_x * cos(-rot_speed) - data->game.plane_y * sin(-rot_speed);
    data->game.plane_y = oldPlaneX * sin(-rot_speed) + data->game.plane_y * cos(-rot_speed);
}