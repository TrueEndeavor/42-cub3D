/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:13:51 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/28 14:55:52 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	if (keysym == XK_Left || keysym == XK_A || keysym == XK_a)
		printf("move_left(data)");
	if (keysym == XK_Up || keysym == XK_W || keysym == XK_w)
		printf("move_up(data);");
	if (keysym == XK_Right || keysym == XK_D || keysym == XK_d)
		printf("move_right(data);");
	if (keysym == XK_Down || keysym == XK_S || keysym == XK_s)
		printf("move_down(data);");
	if (keysym == XK_Escape || keysym == XK_Q || keysym == XK_q)
		on_destroy(data);
	return (0);
}

/* int	on_destroy(t_data *data)
{
	destroy_images(data);
	if (data->mlx_ptr)
	{
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free_maps(data);
	(void) *data;
	exit(0);
}
 */