/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_access_validation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:41:39 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/22 15:24:20 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_readable(t_data *data, char *scene_file)
{
	int		fd;

	fd = open(scene_file, O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) < 0)
	{
		if (errno == ENOENT)
		{
			display_error("File not found");
		}
		else if (errno == EACCES)
		{
			display_error("File cannot be opened: Permission denied");
		}
		else
		{
			display_error("File cannot be opened: Unknown error");
		}
		on_destroy(data);
		return (false);
	}
	return (fd);
}
