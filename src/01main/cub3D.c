/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:36:05 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/31 16:20:43 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void check_user_position_and_set_camera(t_data *data)
{
		int i;
		int j;

		i = 0;
		while (i < data->map_height)
		{
				j = 0;
				while (j < data->map_width)
				{
						if (data->world_map[i][j] == 'N')
						{
								data->game.pos_x = i + 0.5  ;
								data->game.pos_y = j + 0.5 ;
								data->game.dir_x = -1;
								data->game.dir_y = 0;
								data->game.plane_x = 0;
								data->game.plane_y = 0.66;
								return ;
						}
						j++;
				}
				i++;
		}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (!check_args(ac))
		return (0);
	init_data(&data);
	if (!check_cub_extension(av[1]))
		on_destroy(&data);
	parse_scene_file(&data, av[1]);
	if (!validate_map(&data))
		on_destroy(&data);
	convert_to_intarray(&data);
	check_user_position_and_set_camera(&data);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		on_destroy(&data);
	if (!set_up(&data))
	{
		on_destroy(&data);
	}
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, MotionNotify, PointerMotionMask, &on_mouse, &data);
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask,
		&on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
