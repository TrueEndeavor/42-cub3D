/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:07:20 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/29 15:37:48 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	load_map(t_data *data, char *line)
{
	t_list	*new;
	t_list	*last;
	size_t	line_width;	

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	if (ft_strcmp(line, "\n") == 0)
		display_error("Invalid char in map");
	new->content = ft_strdup(line);
	if (!new->content)
		return (0);
	new->next = NULL;
	if (!data->map)
	{
		data->map = new;
		return (1);
	}
	last = ft_lstlast(data->map);
	last->next = new;

	line_width = ft_strlen(line);
	if ((int)line_width > data->map_width)
		data->map_width = (int)line_width;
	return (1);
}
