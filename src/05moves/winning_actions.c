/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winning_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:52:11 by lannur-s          #+#    #+#             */
/*   Updated: 2023/12/12 10:15:55 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_in_direction(t_data *data, int delta_x, int delta_y)
{
	data->cat_x += delta_x;
	data->cat_y += delta_y;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
							data->fluffy_love_ptr, data->cat_x * PIXELS, \
							data->cat_y * PIXELS);
}

void	win_game(t_data *data, char move)
{
	data->moves++;
	ft_printf("moves: %d\n", data->moves);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
							data->paw_ptr, data->cat_x * PIXELS, \
							data->cat_y * PIXELS);
	if (move == 'l')
		move_in_direction(data, -1, 0);
	else if (move == 'r')
		move_in_direction(data, 1, 0);
	else if (move == 'u')
		move_in_direction(data, 0, -1);
	else if (move == 'd')
		move_in_direction(data, 0, 1);
	ft_printf("WINNER! So long from solitude. Say 'Meow' to love.\n");
	on_destroy(data);
}
