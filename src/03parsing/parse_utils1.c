/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:22:29 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/23 17:48:58 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parse_int(char **str)
{
	int	num;

	num = 0;
	while (**str >= '0' && **str <= '9')
	{
		num = num * 10 + (**str - '0');
		(*str)++;
	}
	return (num);
}

int	check_texture_file(char *file_name)
{
	int		fd;

	if (!check_xpm_extension(file_name))
		return (0);
	fd = open(file_name, O_RDONLY);
	//TODO: Check for directory
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
			display_error(strerror(errno));
		}
		return (0);
	}
	if (fd > 0)
		close(fd);
	return (1);
}
