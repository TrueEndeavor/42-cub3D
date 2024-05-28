/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:00:50 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/27 18:02:17 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	check_cub_extension(char *file_name)
{
	int		len;

	len = ft_strlen(file_name);
	if (file_name[len - 4] != '.' || file_name[len - 3] != 'c'\
		|| file_name[len - 2] != 'u' || file_name[len - 1] != 'b')
	{
		display_error("Files without .cub extension not accepted");
		return (false);
	}
	return (true);
}

bool	check_xpm_extension(char *file_name)
{
	size_t	len;

	len = ft_strlen(file_name);
	if (file_name[len - 4] != '.' || file_name[len - 3] != 'x'\
		|| file_name[len - 2] != 'p' || file_name[len - 1] != 'm')
	{
		display_error("Textures are not in XPM format");
		return (false);
	}
	return (true);
}
