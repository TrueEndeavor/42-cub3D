/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:10:26 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/04 09:56:39 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_dup_map(t_data *data)
{
	data->dup_map = ft_calloc((data->map_height + 1), sizeof(char *));
	if (!data->dup_map)
		display_error("Could not duplicate map");
}

int	set_map(t_data *data, t_list *current)
{
	int		i;
	int		j;

	i = 0;
	while (current)
	{
		if (current->content)
			data->dup_map[i] = ft_strdup(current->content);
		if (!data->dup_map[i])
			display_error("Could not duplicate map");
		j = 0;
		while (ft_iswhitespace(data->dup_map[i][j]))
			j++;
		while (data->dup_map[i][j] != '\0')
		{
			if (data->dup_map[i][j] == ' '
				&& j != data->dup_map[i][ft_strlen(data->dup_map[i]) - 1])
				data->dup_map[i][j] = '1';
			j++;
		}
		i++;
		current = current->next;
	}
	return (1);
}

int	set_dup_map(t_data *data)
{
	int		i;
	t_list	*current;

	i = 0;
	init_dup_map(data);
	if (!data->dup_map)
		return (0);
	current = data->map;
	if (!set_map(data, current))
		return (0);
	return (1);
}
