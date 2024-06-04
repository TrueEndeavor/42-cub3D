/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:36:05 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/04 09:24:16 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	handle_args(int ac)
{
	if (!check_args(ac))
		exit(0);
}

void	init_and_parse(t_data *data, char *file)
{
	init_data(data);
	if (!check_cub_extension(file))
		on_destroy(data);
	parse_scene_file(data, file);
	if (!validate_map(data))
		on_destroy(data);
	convert_to_intarray(data);
}

void	initialize_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		on_destroy(data);
	if (!set_up(data))
		on_destroy(data);
}

void	setup_hooks(t_data *data)
{
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, data);
	mlx_hook(data->win_ptr, MotionNotify, PointerMotionMask, &on_mouse, data);
	mlx_loop_hook(data->mlx_ptr, render, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, \
		&on_destroy, data);
}

int	main(int ac, char **av)
{
	t_data	data;

	handle_args(ac);
	init_and_parse(&data, av[1]);
	printf("map height and width = %d x %d\n", data.map_height, data.map_width);
	initialize_mlx(&data);
	setup_hooks(&data);
	mlx_loop(data.mlx_ptr);
	on_destroy(&data);
	return (0);
}
