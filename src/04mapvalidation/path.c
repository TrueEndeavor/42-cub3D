/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:10:26 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/28 13:19:30 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* 
int	set_dup_map(t_data *data)
{
	int		i;
	int		j;
	int		max_width;
	t_list	*current;

	max_width = 0;
	i = 0;
	j = 0;
	current = data->map;
	while (current)
	{
		if ((int)ft_strlen(current->content) > max_width)
			max_width = ft_strlen(current->content);
		current = current->next;
	}
	data->map_width = max_width;
	data->dup_map = ft_calloc((data->win_height + 1), sizeof(char *));
	if (!data->dup_map)
	{
		display_error("Could not duplicate map");
		return (0);
	}
	i = 0;
	current = data->map;
	while (current)
	{
		data->dup_map[i] = ft_strdup(current->content);
		if (!data->dup_map[i])
		{
			display_error("Could not duplicate map");
			return (0);
		
		}
		int map_area_started = 0;
		j = 0;
		while (j < max_width)
		{
			if (j < (int)ft_strlen(data->dup_map[i]))
			{
				if (data->dup_map[i][j] == '1')
					map_area_started = 1;
				if (data->dup_map[i][j] == ' ')
					if (map_area_started)
						data->dup_map[i][j] = '0';
					else
						data->dup_map[i][j] = 'V';
			}
			else
				data->dup_map[i][j] = 'V';
			j++;
		}
		data->dup_map[i][max_width] = '\0';
		i++;
		current = current->next;
	}
	return (1);
} */

/*
int	find_player_position(t_data *data)
{
	int	i;
	int	j;

	if (!set_dup_map(data))
		return (0);
	j = 0;
	while (data->dup_map[j])
	{
		i = 0;
		while (data->dup_map[j][i])
		{
			if (data->dup_map[j][i] == 'P')
			{
				data->start_x = i;
				data->start_y = j;
			}
			i++;
		}
		j++;
	}
	return (0);
} */

int	set_dup_map(t_data *data)
{
	int		i;
	int		j;
	t_list	*current;

	data->dup_map = ft_calloc((data->map_height + 1), sizeof(char *));
	if (!data->dup_map)
	{
		display_error("Could not duplicate map");
		return (0);
	}
	i = 0;
	current = data->map;
	while (current)
	{
		data->dup_map[i] = ft_strdup(current->content);
		if (!data->dup_map[i])
		{
			display_error("Could not duplicate map");
			return (0);
		}
		j = 0;
		while (ft_iswhitespace(data->dup_map[i][j]))
			j++;
		while (data->dup_map[i][++j])
		{
			if (data->dup_map[i][j] == ' '
				&& j != data->dup_map[i][ft_strlen(data->dup_map[i]) - 1])
				data->dup_map[i][j] = '1';
		}
		i++;
		current = current->next;
	}
	return (1);
}
