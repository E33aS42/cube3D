# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esommier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/06 12:24:12 by esommier          #+#    #+#              #
#    Updated: 2020/11/18 12:39:29 by esommier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	cub3D

SRCS 		=	cub3d.c \
			ft_lib.c \
			check_line.c \
			get_param.c \
			init_delta.c \
			dda.c \
			ft_str.c \
			get_raw_map.c \
			init_map.c \
			draw_sprites.c \
			ft_tabdup.c \
			get_resolution.c \
			move.c \
			find_sprites.c \
			get_colors_ceil.c \
			get_colors.c \
			get_sprites.c \
			player_position.c \
			free_variables.c \
			get_colors_floor.c \
			get_text_spr.c \
			read_keys_rotate.c \
			ft_error.c \
			get_next_line.c \
			get_textures.c \
			save_bmp.c \
			ft_init.c \
			get_next_line_utils.c \
			init_cub_prm.c


MLX_DIR		= 	minilibx-linux
OBJ_DIR 	= 	objs
SRC_DIR 	= 	srcs
INCLUDE		= 	-I ./include/cub3d.h

CC		= 	clang
CFLAGS		= 	-Wall -Wextra -Werror
LIB_MLX 	= 	-lmlx -lXext -lX11 -lm -lbsd

RM		= 	rm -rf

OBJ 		= 	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))


all:			$(NAME)

$(NAME): 		$(OBJ)
			${CC} $(CFLAGS) $(INCLUDE) $(OBJ) -o $(NAME) -L $(MLX_DIR) $(LIB_MLX)
			@echo $(NAME) was created.

$(OBJ_DIR)/%.o: 	$(SRC_DIR)/%.c
			@mkdir -p $(OBJ_DIR)
			${CC} $(CFLAGS) $(INCLUDE) -I $(MLX_DIR) -c $< -o $@

# to run and check for leaks: valgrind -v --leak-check=full --show-leak-kinds=all ./Cub3D maps/map01.cub  

clean:
			$(RM) $(OBJ_DIR)

fclean:			clean
			$(RM) $(NAME)

re: 			fclean all

.PHONY: 		all, clean, fclean, re
