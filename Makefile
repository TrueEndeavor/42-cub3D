# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 13:43:15 by lannur-s          #+#    #+#              #
#    Updated: 2024/05/23 09:44:45 by lannur-s         ###   ########.fr        #
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

SRCS			=	src/01main/cub3D.c \
					src/02inputvalidation/arg_validation.c \
					src/02inputvalidation/ext_validation.c	\
					src/02inputvalidation/file_access_validation.c	\
					src/03parsing/initialize_all.c \
					src/03parsing/parse_scene_file.c	\
					src/03parsing/parse_textures.c	\
					src/03parsing/parse_colors.c	\
					src/03parsing/parse_utils.c	\
					src/07error/error_handling.c \
					src/03parsing/load_map.c \
					src/06destroy/destroy.c
#					src/03structureinitialization/setup.c \
#					src/04mapvalidation/validate_map.c \
#					src/04mapvalidation/path.c \
#					src/04mapvalidation/map_checks.c \
#					src/05moves/events.c \
#					src/05moves/cat_movement.c \
#					src/05moves/move_checks.c \
#					src/05moves/winning_actions.c \
					
OBJS = $(SRCS:%.c=%.o)

$(NAME): $(LIBFT_DIR)/$(LIBFTNAME) $(OBJS)
	$(CC) $(CCFLAGS) $(SRCS) $(LIBFT_DIR)/$(LIBFTNAME) $(INCLUDES) -o ${NAME} $(MLX_FLAGS)

$(LIBFT_DIR)/$(LIBFTNAME):
	make -C $(LIBFT_DIR)

%.o: %.c $(HEADERS)
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