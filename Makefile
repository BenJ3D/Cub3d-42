# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 23:43:27 by vducoulo          #+#    #+#              #
#    Updated: 2022/12/09 18:47:58 by abucia           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCDIR := srcs
SRCEXT := c
BONUS = 0
C_BONUS = -D BONUS=${BONUS}
NAME_BONUS = cub3D_bonus
SRCS_GLOBAL = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))

OBJS_GLOBAL = ${SRCS_GLOBAL:.c=.o}
OBJS_MANDATORY = ${SRCS_MANDATORY:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

LIBFT = libs/libft/libft.a
GNL = libs/gnl/gnl.a

INCLUDES = includes/cub3d.h libs/libft/libft.h libs/gnl/get_next_line.h
CC = gcc -g3 #-fsanitize=address
RM = rm -f

FLAGS = -O3 #-Wall -Wextra -Werror

all: lib ${NAME}

bonus: 
	make -C ./ bb BONUS=1

bb: lib ${NAME_BONUS}

$(NAME): ${OBJS_GLOBAL} ${OBJS_MANDATORY}
	${CC}  -D BONUS=0 ${OBJS_GLOBAL} ${OBJS_MANDATORY} ${MLX_FLAG} ${LIBFT} ${GNL} -o $(NAME)

${NAME_BONUS}: ${OBJS_GLOBAL} ${OBJS_BONUS}
	${CC}  -D BONUS=1 ${OBJS_GLOBAL} ${OBJS_BONUS} ${MLX_FLAG} ${LIBFT} ${GNL} -o $(NAME_BONUS)

MLX_FLAG = -Llibs/libft -lft -Llibs/mlx_mac -lmlx -framework OpenGL -framework Appkit
MLX = libs/mlx_mac

%.o: %.c ${INCLUDES} Makefile
		${CC} ${C_BONUS} ${FLAGS} -Imlx -Ift -c $< -o $@

clean:
	${RM} ${OBJS_GLOBAL} ${OBJS_MANDATORY} ${OBJS_BONUS}
	make clean -C libs/mlx_mac
	make clean -C libs/libft
	make clean -C libs/gnl

fclean: clean
	${RM} ${NAME} ${NAME_BONUS}
	make fclean -C libs/libft
	make fclean -C libs/gnl

lib:
	make -C libs/mlx_mac
	make -C libs/libft
	make -C libs/gnl

re: fclean all

.PHONY: all clean fclean re NAME bonus