/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:11:01 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/31 10:52:38 by lannur-s         ###   ########.fr       */
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

/* int	check_size(t_data *data)
{
	if (data->win_height < MIN_HEIGHT || data->win_width < MIN_WIDTH
		|| data->win_width > MAX_WIDTH || data->win_height > MAX_HEIGHT)
	{
		display_error("Size not adapted for game");
		return (0);
	}
	return (1);
} */

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
				printf("this is where the char is WRONG = ..%d.. , ..%d..\n", c, (c == '\n'));
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
/* 
int	check_walls(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	if (set_dup_map(data))
	{
		for (int i = 0; i < data->map_height; i++)
		{
			printf("%s\n", data->dup_map[i]);
		}
	}
	for (y = 0; y < data->map_height; y++)
	{
			printf("checkcoucou: y=%d\n", y);
			x = 0;
		if (y == 0 || y == (data->map_height - 1))
		{
			while (data->dup_map[y][x] != '\0')
			{
				printf("current char= %c\n", (data->dup_map[y][x]));
				if (data->dup_map[y][x] != '1' && data->dup_map[y][x] != 'V')
					return (0);
				x++;
			}
		}
		else if ((data->dup_map[y][x] != '1' && data->dup_map[y][x] != 'V') || \
			((data->dup_map[y][(ft_strlen(data->dup_map[y])) - 1] != '1') && (data->dup_map[y][(ft_strlen(data->dup_map[y])-1)] != 'V')))
			return (0); 
		//y++;
		printf("\next line");
		printf("\n");
	}
	return (1);
} */

int	check_outer_enclosure(t_data *data, int i, int j)
{
	if (!data->dup_map || !data->dup_map[i] || !data->dup_map[i][j])
		return (0);
	while (ft_iswhitespace(data->dup_map[i][j]))
		j++;
	while (data->dup_map[i][j])
	{
		if (data->dup_map[i][j] == 'N' || \
			data->dup_map[i][j] == 'E' || \
			data->dup_map[i][j] == 'S' || \
			data->dup_map[i][j] == 'W')
			return (2);
		else if (data->dup_map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int is_row_enclosed(char *row)
{
	int len;
	int i;
	int left_wall;
	int right_wall;
	
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

int is_column_enclosed(t_data *data, int col)
{
	int i;
	int top_wall;
	int bottom_wall;
	
	i = 0;
	top_wall = 0;
	bottom_wall = 0;
	//printf("\nCOLUMN = %d\n", col);
	while (i < data->map_height && data->dup_map[i][col] == ' ')
	{
		//printf("skipping i=%d\n", i);
		i++;
	}
	if (i < data->map_height && data->dup_map[i][col] == '1')
	{
		//printf("..data->dup_map[%d][%d] = %c\n", i, col, data->dup_map[i][col]);
		top_wall = 1;
	}
	i = data->map_height - 1;
	//printf("data->map_height= %d \n..checking column bottom i = %d\n", data->map_height, i);
	while (i >= 0 && data->dup_map[i][col] == ' ')
		i--;
	if (i >= 0 && data->dup_map[i][col] == '1')
	{
		//printf("..data->dup_map[%d][%d] = %c\n", i, col, data->dup_map[i][col]);
		bottom_wall = 1;
	}
	return (top_wall && bottom_wall);
}

int	check_walls(t_data *data)
{
	int	i;
	int	j;
	int	status;

	set_dup_map(data);
	status = check_outer_enclosure(data, 0, 0);
	if (status != 1)
	{
		return (status);
	}
	i = 1;
	while (i < data->map_height - 1)
	{
		if (!is_row_enclosed(data->dup_map[i]))
			return (0);
		i++;
	}
	j = 0;
	while (j < data->map_width)
	{
		if (!is_column_enclosed(data, j))
			return 0;
		j++;
	}
	status = check_outer_enclosure(data, i, 0);
	if (status != 1)
	{
		return (status);
	}
	return (1);
}

/*
int	check_e_p_c_count(t_data *data)
{
	t_list	*current;
	int		x;
	int		y;

	current = data->map;
	y = 0;
	while (current)
	{
		x = 0;
		while (((char *)current->content)[x])
		{
			if (((char *)current->content)[x] == 'C')
				data->c_count++;
			if (((char *)current->content)[x] == 'E')
				data->e_count++;
			if (((char *)current->content)[x] == 'P')
				data->p_count++;
			x++;
		}
		current = current->next;
		y++;
	}
	return (1);
}
 */