/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:00:14 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/04 15:42:07 by rogalio          ###   ########.fr       */
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
# include <math.h>
# include <stdio.h> // to be deleted later

/* *****************************   CONSTANTS   *******************************/

# define screenWidth 640
# define screenHeight 480

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

# define ERR_TEXTURE_MISSING_OR_DUPLICATED 11
# define ERR_COLOR_MISSING_OR_DUPLICATED 12

# define ERR_TEXTURE_FILE_CANNOT_OPEN 21
# define ERR_COLOR_RGB_VALUES_MISSING 22

# define ERR_MAP_POSITION_INVALID 31

/* *****************************   STRUCTURES   *******************************/

typedef struct RGB_STRUCT
{
	int			red;
	int			green;
	int			blue;
}	t_rgb;


typedef struct TEXTURE_ELEMENT
{
	char	*north_texture;
	void	*north_img;
	int		*north_data;
	int		north_width;
	int		north_height;
	int		no_count;

	char	*east_texture;
	void	*east_img;
	int		*east_data;
	int		east_width;
	int		east_height;
	int		ea_count;

	char	*south_texture;
	void	*south_img;
	int		*south_data;
	int		south_width;
	int		south_height;
	int		so_count;

	char	*west_texture;
	void	*west_img;
	int		*west_data;
	int		west_width;
	int		west_height;
	int		we_count;
}	t_textures;

typedef struct COLORS
{
	t_rgb			floor;
	int				floor_count;
	t_rgb			ceiling;
	int				ceiling_count;
	unsigned long	floor_hex;
	unsigned long	ceiling_hex;
}	t_colors;

typedef struct s_game
{
	double	pos_x;
	double	pos_y;
	double	move_speed;
	double	rot_speed;
	double	mouserot_speedfactor;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_game;

typedef struct s_ray
{
	double cameraX;
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int stepX;
	int stepY;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;
}	t_ray;


typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;

	int			win_height;
	int			win_width;

	t_game		game;

	t_textures	textures;
	t_colors	colors;

	t_list		*map;
	int			map_height;
	int			map_width;

	void		*player_ptr;

	int			**world_map;
	char		**dup_map;

	void	*north_texture;
	void	*east_texture;
	void	*south_texture;
	void	*west_texture;

}	t_data;


/* *****************************   CONSTANTS   ********************************/

# define PIXELS 64
/* # define MAX_HEIGHT 15
# define MAX_WIDTH 30
# define MIN_HEIGHT 3
# define MIN_WIDTH 3 */

/* *************************   INPUT VALIDATION   ****************************/
void	init_data(t_data *data);
void	initialize_game(t_game *game);
bool	check_args(int ac);
bool	check_cub_extension(char *file_name);
int		check_readable(t_data *data, char *scene_file);

/* *************************   PARSING   ****************************/

void	parse_scene_file(t_data *data, char *scene_file);
void	parse_texture_line(char *line, t_textures *textures);
void	parse_color_line(char *line, t_colors *colors);
void	parse_textures(int direction, t_textures *textures, char *line);

bool	textures_are_valid(t_textures *textures);
bool	texture_files_exist(t_textures *textures);
bool	colors_are_valid(t_colors *colors);
bool	colors_have_valid_rgb(t_colors *colors);
int		check_tex_col(t_data *data, bool tex_flag, bool col_flag);
int		check_map_size(t_data *data);
int		set_dup_map(t_data *data);
/* *************************   PARSING UTILS  ****************************/
void	trim_whitespace(char **line);
void	cleanup_and_exit(t_data *data, char *line, int fd, int error_code);
void	handle_error(t_data *data, bool tex_flag, bool col_flag);
char	*trim_newline(char *str);
int		is_texture_line(char *line);
int		is_color_line(char *line);
int		is_map_line(char *line);
int		parse_int(char **str);
bool	check_xpm_extension(char *file_name);
void	print_all(t_data *data);
void	print_map_array(t_data *data);
void	print_textures(t_data *data);
int		check_players(t_data *data);
void	load_north_texture(t_data *data);
void	load_east_texture(t_data *data);
void	load_south_texture(t_data *data);
void	load_west_texture(t_data *data);
void	initialize_ray_steps(t_data *data, t_ray *ray);
void	calculate_ray_parameters(t_data *data, int x, t_ray *ray);

int		check_texture_file(char *file_name);
unsigned long	rgb_to_hex(t_rgb color);
void	free_dup_map(t_data *data);

int		load_map(t_data *data, char *line);

int		validate_map(t_data *data);
void	convert_to_intarray(t_data *data);
void	print_map_int_array(int **int_map, int height, int width);
int		check_size(t_data *data);
int		check_chars(t_data *data);
int		check_walls(t_data *data);
int		check_e_p_c_count(t_data *data);

int		check_valid_path(t_data *data);

int		set_up(t_data *data);

int		on_keypress(int keysym, t_data *data);
int		on_mouse(int x, int y, t_data *data);
int		render(t_data *data);

void rotate_left(t_data *data, double rot_speed);
void rotate_right(t_data *data, double rot_speed);
void draw_wall(t_data *data, int x, t_ray *ray, int *img_data);
void calculate_wall_parameters(t_data *data, t_ray *ray);
void detect_walls(t_data *data, t_ray *ray);
void calculate_ray_parameters(t_data *data, int x, t_ray *ray);
void	move_up(t_data *data, double move_speed);
void	move_down(t_data *data, double move_speed);
void move_left(t_data *data, double move_speed);
void move_right(t_data *data, double move_speed);
char	check_next_move(t_data *data, int x, int y);
void	check_collected(t_data *data, int x, int y);

int		on_destroy(t_data *data);
void	free_maps(t_data *data);
void	destroy_images(t_data *data);

int		display_error(char *str);
char	*get_error_message(int error_code);

void	win_game(t_data *data, char move);
void	win_in_direction(t_data *data, int delta_x, int delta_y);

#endif
