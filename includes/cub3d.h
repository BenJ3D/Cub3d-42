/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 02:44:28 by mal-guna          #+#    #+#             */
/*   Updated: 2022/11/18 00:46:55 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/mlx_mac/mlx.h"
# include "../libs/libft/libft.h"
# include "../libs/gnl/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

/* Game Settings */
# define HEIGHT 768
# define WIDTH 768
# define ROTATION_SPEED 0.04
# define ONE_DEGREE_RAD 0.00116355333
# define BLOCK_SIZE 32
# define SPEED 1

/* Linux Keys */
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define DOORS 101 // E
# define ESC 65307

/* Mac Keys */
// # define KEY_RIGHT 124
// # define KEY_LEFT 123
// # define KEY_W 13
// # define KEY_S 1
// # define KEY_A 0
// # define KEY_D 2
// # define DOORS 14
// # define ESC 53

#endif