/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:10:26 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/28 15:33:47 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
