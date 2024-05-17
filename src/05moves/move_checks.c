/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:57:47 by lannur-s          #+#    #+#             */
/*   Updated: 2023/12/12 10:06:55 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	check_next_move(t_data *data, int x, int y)
{
	t_list	*current;
	int		i;

	current = data->map;
	i = 0;
	while (i < y && current)
	{
		current = current->next;
		i++;
	}
	if (((char *)current->content)[x] == '1')
		return ('1');
	if (((char *)current->content)[x] == 'C')
		return ('C');
	if (((char *)current->content)[x] == 'E')
		return ('E');
	if (((char *)current->content)[x] == '0')
		return ('0');
	return ('0');
}

void	check_collected(t_data *data, int x, int y)
{
	if (data->dup_map[y][x] != 'D')
	{
		data->dup_map[y][x] = 'D';
		data->collected++;
	}
}
