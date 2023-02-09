# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 01:26:51 by bducrocq          #+#    #+#              #
#    Updated: 2023/02/05 13:46:53 by bducrocq         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#	Si probleme compile mlx (genre "/usr/bin/ld: cannot find -lz")
#	sous ubuntu/debian, try install :
#	sudo apt-get install gcc make xorg libxext-dev libbsd-dev libz-dev balbla


# $< "include one prerequisite"
# $@ "include target"
# $^ "include the full list of prerequisites)"
# SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))

NAME = cub3d
NAME_BONUS = cub3d_bonus

SRCDIR      := srcs
SRCEXT      := c
SOURCES =		./srcs/libft_custom/ft_calloc_cub.c \
				./srcs/parsing/parsing_parameters_header.c \
				./srcs/parsing/parsing_utils.c \
				./srcs/parsing/init_img.c \
				./srcs/parsing/parsing.c \
				./srcs/parsing/parsing_parameters.c \
				./srcs/parsing/parsing_files.c \
				./srcs/parsing/init_img_b.c \
				./srcs/parsing/parsing_map.c \
				./srcs/exec/exec_main_minimap.c \
				./srcs/exec/exec_main_raycast.c \
				./srcs/exec/exec_main_keypress_release.c \
				./srcs/exec/exec_main_tools.c \
				./srcs/exec/player_move_rotate.c \
				./srcs/exec/velocity.c \
				./srcs/exec/player_coliding.c \
				./srcs/exec/exec_main_renderframe.c \
				./srcs/exec/exec_main.c \
				./srcs/exec/player_lookchange_and_fov.c \
				./srcs/exec/exec_main_putppixel_and_dda.c \
				./srcs/exec/player_move.c \
				./srcs/err/free.c \
				./srcs/err/cub3d_error.c \
				./srcs/main.c

C_BONUS=-DBONUS=0

OBJS = ${SOURCES:.c=.o}
OBJS_B = ${SOURCES:.c=_bonus.o}

CFLAGS = -g3 -Wall -Wextra -O3 #-Werror 
SANITIZE = #-fsanitize=address
CC = cc $(SANITIZE)

OS	= $(shell uname)
LIBFT = libs/libft/libft.a
GNL = libs/gnl/gnl.a
LIBFT_PATH = libs/libft
GNL_PATH = libs/gnl
HEADER   = includes/exec.h includes/struct_parsing.h includes/cub3d.h libs/libft/libft.h libs/gnl/get_next_line.h

ifeq ($(OS), Linux)
	MLX_FLAGS = -Llibs/mlx_linux -lmlx -Ilibs/mlx_linux -lXext -lX11 -lm -lz
	MLX_PATH = libs/mlx_linux
else
	MLX_FLAGS = -Llibs/mlx_mac -lmlx -Ilibs/mlx_mac -framework OpenGL -framework AppKit
	MLX_PATH = libs/mlx_mac
endif

all :
	${MAKE} -C $(MLX_PATH) -j
	${MAKE} -C $(LIBFT_PATH) -j
	${MAKE} -C $(GNL_PATH) -j
	${MAKE} -C ./ norm

bonus :
	${MAKE} -C $(MLX_PATH) -j
	${MAKE} -C $(LIBFT_PATH) -j
	${MAKE} -C $(GNL_PATH) -j
	${MAKE} -C ./ bb C_BONUS="-DBONUS=1"

norm : $(NAME)

norminette:
	norminette srcs/ includes/ libs/gnl libs/libft

bb : $(NAME_BONUS)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) $(GNL) $(LIBFT) $(CFLAGS) -o $(NAME)

$(NAME_BONUS): $(OBJS_B)
	$(CC) $(OBJS_B) $(MLX_FLAGS) $(GNL) $(LIBFT) $(CFLAGS) -o $(NAME_BONUS)

%.o: %.c ${INCLUDES} Makefile ./libs/libft/Makefile $(HEADER)
	${CC} ${CFLAGS} -Imlx -Ift -c $< -o $@;

%_bonus.o: %.c ${INCLUDES} Makefile ./libs/libft/Makefile $(HEADER)
	${CC} ${C_BONUS} ${CFLAGS} -Imlx -Ift -c $< -o $@;

clean:
	$(MAKE) clean -C $(MLX_PATH)
	$(MAKE) clean -C $(LIBFT_PATH)
	$(MAKE) clean -C $(GNL_PATH)
	rm -rf $(OBJS)
	rm -rf $(OBJS_B)
	rm -rf $(NAME_BONUS)
	rm -rf $(NAME)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(MAKE) fclean -C $(GNL_PATH)

re:	fclean
	${MAKE} -C $(MLX_PATH) re -j
	${MAKE} -C $(LIBFT_PATH) re -j
	${MAKE} -C $(GNL_PATH) re -j
	${MAKE} -C ./ norm