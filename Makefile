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

NAME = cub3D

BONUS = 0
C_BONUS = -D BONUS=${BONUS}
NAME_BONUS = cub3D_bonus
SRCS_GLOBAL =		./srcs/libft_custom/ft_calloc_cub.c \
				./srcs/parsing/parsing_parameters_header.c \
				./srcs/parsing/parsing_utils.c \
				./srcs/parsing/init_img.c \
				./srcs/parsing/parsing.c \
				./srcs/parsing/parsing_parameters.c \
				./srcs/parsing/parsing_files.c \
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
OBJS_GLOBAL = ${SRCS_GLOBAL:.c=.o}
OBJS_BONUS = ${SRCS_GLOBAL:.c=_bonus.o}

INCLUDES = libs/libft/libft.h libs/gnl/get_next_line.h libs/mlx_linux/mlx.h
CC = gcc #-g3 #-fsanitize=address
RM = rm -f

FLAGS = -Wall -Wextra -Werror -O3

MLX_FLAG = -Llibs/libft -lft -Lmlx/mlx_mac -lmlx -framework OpenGL -framework Appkit
MLX = libs/mlx_linux

all: lib ${NAME}
UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        MLX_FLAG = -Llibft -lft -Lmlx -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
		MLX = libs/mlx_linux
    endif
    ifeq ($(UNAME_S),Darwin)
        MLX_FLAG = -Llibs/libft -llibs/ft -Lmlx/mlx_mac -lmlx -framework OpenGL -framework Appkit
		MLX = libs/mlx_mac
    endif

bonus:
	make -C ./ bb BONUS=1

bb: lib ${NAME_BONUS}

$(NAME): ${OBJS_GLOBAL}
	${CC} ${OBJS_GLOBAL} ${MLX_FLAG} -o $(NAME)

${NAME_BONUS}: ${OBJS_BONUS}
	${CC} ${OBJS_BONUS} ${MLX_FLAG} -o $(NAME_BONUS)


%.o: %.c ${INCLUDES} Makefile
	${CC} ${C_BONUS} ${FLAGS} -Imlx -Ift -c $< -o $@;

%_bonus.o: %.c ${INCLUDES} Makefile
	${CC} ${C_BONUS} ${FLAGS} -Imlx -Ift -c $< -o $@;

clean:
	${RM} ${OBJS_GLOBAL} ${OBJS_BONUS}
	make clean -C ${MLX}
	make clean -C libs/libft

fclean: clean
	${RM} ${NAME} ${NAME_BONUS}
	make fclean -C libs/libft

lib:
	make -C ${MLX}
	make -C libs/libft

re:    fclean all

.PHONY: all clean fclean re NAME bonus
