/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:07:20 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/28 13:55:28 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	load_map(t_data *data, char *line)
{
	t_list	*new;
	t_list	*last;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	//printf("line = %s\n", line);
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
	return (1);
}
