/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 07:45:57 by abucia            #+#    #+#             */
/*   Updated: 2023/02/07 13:44:49 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
# include "cub3d.h"
# include "struct_parsing.h"

# define CELL_SIZE 64
# define MAP_CELL_SIZE 4

# ifndef RENDER_DIST
#  define RENDER_DIST 1024
# endif

# ifndef FOV_HORIZONTAL
#  define FOV_HORIZONTAL 0.5
# endif

# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 1440
# endif

# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 2560
# endif

# ifndef MAX_VELOCITY
#  define MAX_VELOCITY 7
# endif

# ifndef ROT_SPEED
#  define ROT_SPEED 0.06
# endif

# ifndef COEF_ACCELERATION
#  define COEF_ACCELERATION 1.17
# endif

# ifndef COEF_DECELERATION
#  define COEF_DECELERATION 0.94
# endif

# ifndef BONUS
#  define BONUS 0
# endif

#endif