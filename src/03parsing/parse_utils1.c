/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:22:29 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/31 16:26:23 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parse_int(char **str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	if (*str == NULL || **str == '\0')
	{
		return (-1);
	}
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		num = num * 10 + (**str - '0');
		(*str)++;
	}
	return (num * sign);
}

int	check_texture_file(char *file_name)
{
	int		fd;

	if (!check_xpm_extension(file_name))
		return (0);
	fd = open(file_name, O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) < 0)
	{
		if (errno == EISDIR)
			display_error("Not a file. Is a dir");
		if (errno == ENOENT)
			display_error("File not found");
		else if (errno == EACCES)
			display_error("File cannot be opened: Permission denied");
		else
			display_error(strerror(errno));
		return (0);
	}
	if (fd > 0)
		close(fd);
	return (1);
}

unsigned long	rgb_to_hex(t_rgb color)
{
	return (((unsigned long)color.red << 16) | \
		((unsigned long)color.green << 8) | \
			(unsigned long)color.blue);
}
