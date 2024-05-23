/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:32:27 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/22 16:14:37 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	trim_whitespace(char **line)
{
	while (ft_iswhitespace(**line) && **line != '\n')
	{
		(*line)++;
	}
}

char	*trim_newline(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
	}
	return (str);
}

int	is_texture_line(const char *line)
{
	return (ft_strncmp(line, "NO", 2) == 0 || \
			ft_strncmp(line, "EA", 2) == 0 || \
			ft_strncmp(line, "SO", 2) == 0 || \
			ft_strncmp(line, "WE", 2) == 0);
}

int	is_color_line(const char *line)
{
	return (ft_strncmp(line, "C", 1) == 0 || ft_strncmp(line, "F", 1) == 0);
}

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

/* int	check_texture_file(char *arg, bool cub)
{
	int	fd;

	if (is_dir(arg))
		return (err_msg(arg, ERR_FILE_IS_DIR, FAILURE));
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (err_msg(arg, strerror(errno), FAILURE));
	close(fd);
	if (cub && !is_cub_file(arg))
		return (err_msg(arg, ERR_FILE_NOT_CUB, FAILURE));
	if (!cub && !is_xpm_file(arg))
		return (err_msg(arg, ERR_FILE_NOT_XPM, FAILURE));
	return (SUCCESS);
} */

int	check_texture_file(char *file_name)
{
	int		fd;

	if (!check_xpm_extension(file_name))
		return (0);
	fd = open(file_name, O_RDONLY);
	//Check for directory
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
