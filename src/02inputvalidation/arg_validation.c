/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:51:40 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/17 11:19:55 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	check_args(int ac)
{
	if (ac == 1)
	{
		display_error("cub3D needs a map");
		return (false);
	}
	if (ac > 2)
	{
		display_error("Too many arguments to cub3d");
		return (false);
	}
	return (true);
}
