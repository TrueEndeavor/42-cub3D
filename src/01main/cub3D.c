/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:36:05 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/17 11:50:24 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#include <string.h>
#include <stdio.h>

int	main(int ac, char **av)
{
 	t_data	data;

	data = (t_data){0};
	if (!check_args(ac))
		return (0);
	if (!check_cub_extension(av[1]))
		on_destroy(&data);
	read_and_initialize_map(&data, av[1]);
/*	if (!validate_map(&data))
		on_destroy(&data);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		on_destroy(&data);
	if (!set_up(&data))
	{
		on_destroy(&data);
	}
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask,
		&on_destroy, &data);
	mlx_loop(data.mlx_ptr); */
	return (0);
}
