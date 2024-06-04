/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:33:13 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/04 09:24:57 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	display_error(char *str)
{
	write(1, "[ERROR] ", 8);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	exit (1);
}

char	*get_error_message(int error_code)
{
	if (error_code == ERR_TEXTURE_MISSING_OR_DUPLICATED)
	{
		return ("Missing or duplicated texture definitions");
	}
	else if (error_code == ERR_TEXTURE_FILE_CANNOT_OPEN)
	{
		return ("Invalid texture definitions");
	}
	else if (error_code == ERR_COLOR_MISSING_OR_DUPLICATED)
	{
		return ("Missing or duplicated color definitions");
	}
	else if (error_code == ERR_COLOR_RGB_VALUES_MISSING)
	{
		return ("Invalid RGB values for one or more colors");
	}
	else
	{
		return ("Unknown error occurred");
	}
}
