/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:10:26 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/03 18:29:17 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	duplicate_map_line(char **dup_map, int i, const char *content)
{
	int	j;

	dup_map[i] = ft_strdup(content);
	if (!(dup_map[i]))
		return (display_error("Could not duplicate map"), 0);
	j = 0;
	while (ft_iswhitespace(dup_map[i][j]))
		j++;
	while (dup_map[i][j])
	{
		if (dup_map[i][j] == ' ' && \
			j != (int)ft_strlen(dup_map[i]) - 1)
			dup_map[i][j] = '1';
		j++;
	}
	return (1);
}

int	allocate_dup_map(t_data *data)
{
	data->dup_map = ft_calloc((data->map_height + 1), sizeof(char *));
	if (!data->dup_map)
		return (display_error("Could not duplicate map"), 0);
	return (1);
}

int	set_dup_map(t_data *data)
{
	int		i;
	t_list	*current;

	if (!allocate_dup_map(data))
		return (0);
	i = 0;
	current = data->map;
	while (current)
	{
		if (current->content)
			data->dup_map[i] = ft_strdup(current->content);
		if (!data->dup_map[i])
		{
			display_error("Could not duplicate map");
			return (0);
		}
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
