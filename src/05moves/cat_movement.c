/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:02:17 by lannur-s          #+#    #+#             */
/*   Updated: 2023/12/12 10:07:11 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_data *data, int new_cat_x, int new_cat_y, char direction)
{
	char	next_move;

	next_move = check_next_move(data, new_cat_x, new_cat_y);
	if (next_move == '1')
		return ;
	if (next_move == 'E' && data->collected == data->c_count)
		win_game(data, direction);
	if (next_move == 'E' && data->collected != data->c_count)
		return ;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
							data->paw_ptr, data->cat_x * PIXELS, \
							data->cat_y * PIXELS);
	data->cat_x = new_cat_x;
	data->cat_y = new_cat_y;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
							data->player_ptr, data->cat_x * PIXELS, \
							data->cat_y * PIXELS);
	data->moves++;
	ft_printf("moves: %d\n", data->moves);
	if (next_move == 'C')
		check_collected(data, data->cat_x, data->cat_y);
}

void	move_left(t_data *data)
{
	move(data, data->cat_x - 1, data->cat_y, 'l');
}

void	move_right(t_data *data)
{
	move(data, data->cat_x + 1, data->cat_y, 'r');
}

void	move_up(t_data *data)
{
	move(data, data->cat_x, data->cat_y - 1, 'u');
}

void	move_down(t_data *data)
{
	move(data, data->cat_x, data->cat_y + 1, 'd');
}
