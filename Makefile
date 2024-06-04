# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 13:43:15 by lannur-s          #+#    #+#              #
#    Updated: 2024/06/04 15:42:39 by rogalio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBFTNAME = libft.a

CC = cc
CCFLAGS = -g -Wall -Werror -Wextra

AR = ar
ARFLAGS = -rcs

MLX       =	minilibx-linux/Makefile.gen
MLX_FLAGS = -L ./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd

LIBFT_DIR = ./include/libft_combined

INCLUDES = -I./include -I$(LIBFT_DIR)/include -I./minilibx-linux
#SRCS			=	src/01main/cub3D1.c

SRCS			=	src/01main/cub3D.c \
					src/02inputvalidation/arg_validation.c \
					src/02inputvalidation/ext_validation.c	\
					src/02inputvalidation/file_access_validation.c	\
					src/03parsing/initialize_all.c \
					src/03parsing/parse_scene_file.c	\
					src/03parsing/parse_data_validation.c	\
					src/03parsing/parse_textures.c	\
					src/03parsing/parse_colors.c	\
					src/03parsing/parse_utils.c	\
					src/03parsing/parse_utils1.c	\
					src/04mapvalidation/validate_map.c \
					src/04mapvalidation/map_checks.c \
					src/04mapvalidation/map_checks1.c \
					src/04mapvalidation/player_check.c \
					src/07error/error_handling.c \
					src/03parsing/load_map.c \
					src/dev/print_debug.c	\
					src/04mapvalidation/duplicate_map.c \
					src/04mapvalidation/valid_map_utils.c \
					src/06destroy/destroy.c \
					src/05raycasting/setup.c \
					src/05raycasting/load_textures.c \
					src/05raycasting/events.c \
					src/05raycasting/render.c \
					src/05raycasting/raycasting.c \
					src/05raycasting/raycasting1.c \
					src/05raycasting/move.c \
					src/05raycasting/rotate.c \
					src/05raycasting/draw.c

OBJS_DIR = obs
OBJS = $(SRCS:src/%.c=$(OBJS_DIR)/%.o)

$(NAME): $(LIBFT_DIR)/$(LIBFTNAME) $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFTNAME) $(INCLUDES) -o ${NAME} $(MLX_FLAGS)

$(LIBFT_DIR)/$(LIBFTNAME):
	make -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: src/%.c $(HEADERS)
	mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME) $(MLX)

clean:
	rm -f $(OBJS)
	cd $(LIBFT_DIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBFT_DIR) && make fclean

re: fclean all

test: ${NAME}
	./${NAME}

vtest: ${NAME}
	valgrind --leak-check=full --show-leak-kinds=all ./${NAME}

.PHONY: all clean fclean re test vtest

