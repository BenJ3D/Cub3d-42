# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 01:26:51 by bducrocq          #+#    #+#              #
#    Updated: 2022/12/07 13:17:09 by bducrocq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Si probleme compile mlx (genre "/usr/bin/ld: cannot find -lz")
#	sous ubuntu/debian, try install :
#	sudo apt-get install gcc make xorg libxext-dev libbsd-dev libz-dev balbla


# $< "include one prerequisite"
# $@ "include target"
# $^ "include the full list of prerequisites)"

NAME = cub3d


SRCDIR      := srcs
SRCEXT      := c
SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJS = ${SOURCES:.c=.o}

CFLAGS = -g3 -O3 # -Wall -Wextra -Werror
SANITIZE =# -fsanitize=address
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

all : $(NAME)

$(NAME): $(OBJS) $(HEADER) Makefile
	@$(MAKE) -C $(MLX_PATH) -j
	@$(MAKE) -C $(LIBFT_PATH) -j
	@$(MAKE) -C $(GNL_PATH) -j
	$(CC) $(OBJS) $(MLX_FLAGS) $(GNL) $(LIBFT)  $(CFLAGS) -o $(NAME)

clean:
	$(MAKE) clean -C $(MLX_PATH)
	$(MAKE) clean -C $(LIBFT_PATH)
	$(MAKE) clean -C $(GNL_PATH)
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(MAKE) fclean -C $(GNL_PATH)
re:	fclean all

.PHONY:	all clean fclean re
