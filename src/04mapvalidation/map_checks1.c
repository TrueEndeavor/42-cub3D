/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:11:01 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/04 16:34:27 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_map_size(t_data *data)
{
	if (ft_lstsize(data->map) <=0)
	{
		display_error("Missing map info");
		return (0);
	}
	if (ft_lstsize(data->map) < 3)
	{
		display_error("The map size is too small");
		return (0);
	}
	return (1);
}

int	check_chars(t_data *data)
{
	t_list	*current;
	int		i;
	int		j;
	char	c;

	j = 0;
	current = data->map;
	while (current)
	{
		i = 0;
		while (((char *)current->content)[i] != '\0')
		{
			c = ((char *)current->content)[i];
			if (c != '0' && c != '1' && c != 'N' && c != 'E' && \
				c != 'S' && c != 'W' && c != ' ' && c != '\n')
			{
				display_error("Invalid char in map");
				return (0);
			}
			i++;
		}
		current = current->next;
		j++;
	}
	return (1);
}
