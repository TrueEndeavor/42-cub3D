/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:07:20 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/03 20:43:43 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	load_map(t_data *data, char *line)
{
	t_list	*new;
	size_t	max_width;

	if (!line || !data)
		return (0);
	new = ft_lstnew(ft_strdup(line));
	if (!new || !new->content)
	{
		if (new)
			free(new);
		return (0);
	}
	if (ft_strcmp(line, "\n") == 0)
	{
		free(new->content);
		free(new);
		display_error("Invalid char in map");
		return (0);
	}
	ft_lstadd_back(&data->map, new);
	max_width = ft_strlen(line);
	if ((int)max_width > data->map_width)
		data->map_width = (int)max_width;
	return (1);
}
