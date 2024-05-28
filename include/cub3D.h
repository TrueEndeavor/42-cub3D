/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:00:14 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/27 17:47:04 by rogalio          ###   ########.fr       */
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

# include <stdio.h> // to be deleted later

/* *****************************   CONSTANTS   *******************************/
# define NORTH 1
# define EAST 2
# define SOUTH 3
# define WEST 4

# define CEILING 1
# define FLOOR 2

/* # define WIN_WIDTH 960 */
/* # define WIN_HEIGHT 720 */
# define WIN_WIDTH 640
# define WIN_HEIGHT 480

/* *****************************   STRUCTURES   *******************************/

typedef struct RGB_STRUCT
{
	int			red;
	int			green;
	int			blue;
}	t_rgb;


/*
typedef struct TEXTURE_ELEMENT
{
	char		*north_texture;
	int			no_count;
	char		*east_texture;
	int			ea_count;
	char		*south_texture;
	int			so_count;
	char		*west_texture;
	int			we_count;
}	t_textures;
*/

typedef struct TEXTURE_ELEMENT
{
    char    *north_texture;
    void    *north_img;
    int     *north_data;
    int     north_width;
    int     north_height;
    int     no_count;

    char    *east_texture;
    void    *east_img;
    int     *east_data;
    int     east_width;
    int     east_height;
    int     ea_count;

    char    *south_texture;
    void    *south_img;
    int     *south_data;
    int     south_width;
    int     south_height;
    int     so_count;

    char    *west_texture;
    void    *west_img;
    int     *west_data;
    int     west_width;
    int     west_height;
    int     we_count;
}   t_textures;
typedef struct COLORS
{
	t_rgb	floor;
	int		floor_count;
	t_rgb	ceiling;
	int		ceiling_count;
}	t_colors;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;

	int			win_height;
	int			win_width;

	t_textures	textures;
	t_colors	colors;

	t_list		*map;

	void		*player_ptr;

	char		**dup_map;
	int		e_count;
	int		p_count;
	int		c_count;
	int		start_x;
	int		start_y;


}	t_data;

/* *****************************   CONSTANTS   ********************************/

# define PIXELS 64
# define MAX_HEIGHT 15
# define MAX_WIDTH 30
# define MIN_HEIGHT 3
# define MIN_WIDTH 3

/* *************************   INPUT VALIDATION   ****************************/
void	init_data(t_data *data);
bool	check_args(int ac);
bool	check_cub_extension(char *file_name);
int		check_readable(t_data *data, char *scene_file);

/* *************************   PARSING   ****************************/

void	parse_scene_file(t_data *data, char *scene_file);
void	parse_texture_line(char *line, t_textures *textures);
void	parse_color_line(char *line, t_colors *colors);

void	parse_textures(int direction, t_textures *textures, char *line);

/* *************************   PARSING UTILS  ****************************/
void	trim_whitespace(char **line);
char	*trim_newline(char *str);
int		is_texture_line(char *line);
int		is_color_line(char *line);
int		is_map_line(char *line);
int		parse_int(char **str);
bool	check_xpm_extension(char *file_name);

int		check_texture_file(char *file_name);

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
