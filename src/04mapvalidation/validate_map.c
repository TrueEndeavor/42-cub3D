/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:44:27 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/03 18:18:53 by lannur-s         ###   ########.fr       */
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
	if (status == 0)
	{
		display_error("Map is not surrounded by walls");
		free_dup_map(data);
		return (0);
	}
	else if (status == 2)
	{
		display_error("Player position on the edge");
		free_dup_map(data);
		return (0);
	}
	status = check_players(data);
	if (status == 0)
	{
		display_error("No or multiple players found");
		free_dup_map(data);
		return (0);
	}
	return (1);
}
