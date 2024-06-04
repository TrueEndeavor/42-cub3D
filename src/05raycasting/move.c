/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:49:05 by rogalio           #+#    #+#             */
/*   Updated: 2024/06/04 16:28:32 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_up(t_data *data, double move_speed)
{
	if (data->world_map[(int)(data->game.pos_x + data->game.dir_x * move_speed)][(int)data->game.pos_y] == 0)
		data->game.pos_x += data->game.dir_x * move_speed;
	if (data->world_map[(int)data->game.pos_x][(int)(data->game.pos_y + data->game.dir_y * move_speed)] == 0)
		data->game.pos_y += data->game.dir_y * move_speed;
}

void	move_down(t_data *data, double move_speed)
{
	if (data->world_map[(int)(data->game.pos_x - data->game.dir_x * move_speed)][(int)data->game.pos_y] == 0)
		data->game.pos_x -= data->game.dir_x * move_speed;
	if (data->world_map[(int)data->game.pos_x][(int)(data->game.pos_y - data->game.dir_y * move_speed)] == 0)
		data->game.pos_y -= data->game.dir_y * move_speed;
}

void	move_left(t_data *data, double move_speed)
{
	if (data->world_map[(int)(data->game.pos_x - data->game.dir_y * move_speed)][(int)data->game.pos_y] == 0)
		data->game.pos_x -= data->game.dir_y * move_speed;
	if (data->world_map[(int)data->game.pos_x][(int)(data->game.pos_y + data->game.dir_x * move_speed)] == 0)
		data->game.pos_y += data->game.dir_x * move_speed;
}

void	move_right(t_data *data, double move_speed)
{
	if (data->world_map[(int)(data->game.pos_x + data->game.dir_y * move_speed)][(int)data->game.pos_y] == 0)
		data->game.pos_x += data->game.dir_y * move_speed;
	if (data->world_map[(int)data->game.pos_x][(int)(data->game.pos_y - data->game.dir_x * move_speed)] == 0)
		data->game.pos_y -= data->game.dir_x * move_speed;
}
