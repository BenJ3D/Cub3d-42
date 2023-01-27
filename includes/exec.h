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

# define MY_PI 3.141592653589793116f

# define CELL_SIZE 64
# define MAP_CELL_SIZE 20

# ifndef RENDER_DIST
#  define RENDER_DIST 1024
# endif

# ifndef FOV_VERTICAL
#  define FOV_VERTICAL 58.75f
# endif

//89 is better for optimisation because 90 can load 3 side of a 1/4 circle.
# ifndef FOV_HORIZONTAL
#  define FOV_HORIZONTAL 70
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

# ifndef COEF_ACCELERATION
#  define COEF_ACCELERATION 1.01
# endif

# ifndef COEF_DECELERATION
#  define COEF_DECELERATION 0.94
# endif

// to optimise the performance we will limit the render to only 60 frame/sec
// 1 divided by 60 = 16.667 microsec
// for BONUS
# ifndef BONUS
#  define BONUS 1
#  include <time.h>
#  ifndef FRAME_TIME
#   define FRAME_TIME 16667
#  endif
# else
#  define BONUS 0
# endif

#endif