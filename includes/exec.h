/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 07:45:57 by abucia            #+#    #+#             */
/*   Updated: 2022/12/09 16:40:33 by abucia           ###   ########lyon.fr   */
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
#  define SCREEN_HEIGHT 1000
# endif

# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 1580
# endif

# ifndef MAX_VELOCITY
#  define MAX_VELOCITY 1.4
# endif

# ifndef ROT_SPEED
#  define ROT_SPEED 0.025
# endif

# ifndef COEF_ACCELERATION
#  define COEF_ACCELERATION 1.01
# endif

# ifndef COEF_DECELERATION
#  define COEF_DECELERATION 0.94
# endif

# ifndef BONUS
#  define BONUS 0
# endif

#endif