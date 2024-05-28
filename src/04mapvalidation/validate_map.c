/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:44:27 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/28 14:03:44 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	validate_map(t_data *data)
{
	int	status;
	
	if (!data->map)
	{
		display_error("Missing map info");
		return (0);
	}
	if (!check_map_size(data))
		return (0);
	if (!check_chars(data))
		return (0);
	status = check_walls(data);
	if (status != 1)
	{
		display_error("Map is not surrounded by walls");
		return (0);
	}
	else if (status == 2)
	{
		display_error("Player position on the edge");
		return (0);
	}
	/*data->e_count = 0;
	data->p_count = 0;
	data->c_count = 0;
	check_e_p_c_count(data);
	if (data->c_count < 1 || data->e_count != 1 || data->p_count != 1)
	{
		display_error("Invalid exit, start position or collectible count");
		return (0);
	}*/
	return (1);
}
