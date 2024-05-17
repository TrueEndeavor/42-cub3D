/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:00:14 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/17 12:45:22 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* *****************************   INCLUDES   ******************************* */
/* For function open() */
# include <fcntl.h>

/* close(), read(), write()  */
# include <unistd.h>

/* malloc(), free(), exit() */
# include <stdlib.h>

/* errno */
# include <errno.h>

/* Libft functions */
# include "libft.h"

# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"

/* *****************************   STRUCTURES   *******************************/
typedef struct s_data
{
	int		height;
	int		width;

	int		e_count;
	int		p_count;
	int		c_count;

	t_list	*map;
	char	**dup_map;

	int		start_x;
	int		start_y;

	void	*mlx_ptr;
	void	*win_ptr;

	void	*floor_ptr;
	void	*paw_ptr;
	void	*wall_ptr;
	void	*player_ptr;
	void	*flower_ptr;
	void	*lover_ptr;
	void	*fluffy_love_ptr;

	int		cat_x;
	int		cat_y;
	int		collected;
	int		moves;
}	t_data;

/* *****************************   CONSTANTS   ********************************/

# define PIXELS 64
# define MAX_HEIGHT 15
# define MAX_WIDTH 30
# define MIN_HEIGHT 3
# define MIN_WIDTH 3

bool	check_args(int ac);
bool	check_cub_extension(char *file_name);
int 	check_readable(t_data *data, char *map);

void	read_and_initialize_map(t_data *data, char *file_name);
int		load_map(t_data *data, char *line);

int		validate_map(t_data *data);
int		check_rectangle(t_data *data);
int		check_size(t_data *data);
int		check_chars(t_data *data);
int		check_walls(t_data *data);
int		check_e_p_c_count(t_data *data);

int		check_valid_path(t_data *data);

int		set_up(t_data *data);

int		on_keypress(int keysym, t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
char	check_next_move(t_data *data, int x, int y);
void	check_collected(t_data *data, int x, int y);

int		on_destroy(t_data *data);
void	free_maps(t_data *data);
void	destroy_images(t_data *data);

int		display_error(char *str);

void	win_game(t_data *data, char move);
void	win_in_direction(t_data *data, int delta_x, int delta_y);

#endif
