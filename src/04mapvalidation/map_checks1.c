/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:11:01 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/03 11:36:29 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_map_size(t_data *data)
{
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

int	is_row_enclosed(char *row)
{
	int	len;
	int	i;
	int	left_wall;
	int	right_wall;

	len = ft_strlen(row);
	left_wall = 0;
	right_wall = 0;
	i = 0;
	while (i < len && row[i] == ' ')
		i++;
	if (i < len && row[i] == '1')
		left_wall = 1;
	i = len - 1;
	while (i >= 0 && row[i] == ' ')
		i--;
	if (i >= 0 && row[i] == '1')
		right_wall = 1;
	return (left_wall && right_wall);
}

int	check_rows(t_data *data)
{
	int	i;

	i = 1;
	while (i < data->map_height - 1)
	{
		if (!is_row_enclosed(data->dup_map[i]))
			return (0);
		i++;
	}
	return (1);
}
