/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:44:27 by lannur-s          #+#    #+#             */
/*   Updated: 2023/12/11 09:35:58 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_data *data)
{
	if (!check_rectangle(data))
		return (0);
	if (!check_size(data))
		return (0);
	if (!check_chars(data))
		return (0);
	if (!check_walls(data))
	{
		display_error("Invalid walls");
		return (0);
	}
	data->e_count = 0;
	data->p_count = 0;
	data->c_count = 0;
	check_e_p_c_count(data);
	if (data->c_count < 1 || data->e_count != 1 || data->p_count != 1)
	{
		display_error("Invalid exit, start position or collectible count");
		return (0);
	}
	if (!check_valid_path(data))
		return (0);
	return (1);
}
