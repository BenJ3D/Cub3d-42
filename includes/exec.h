/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 07:45:57 by abucia            #+#    #+#             */
/*   Updated: 2022/11/30 01:00:13 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
# include "cub3d.h"
# include "struct_parsing.h"

# define MY_PI 3.141592653589793116f

# define CELL_SIZE 64
# define MAP_CELL_SIZE 8

# ifndef RENDER_DIST
#  define RENDER_DIST 1024
# endif

# ifndef FOV_VERTICAL
#  define FOV_VERTICAL 58.75f
# endif

//89 is better for optimisation because 90 can load 3 side of a 1/4 circle.
# ifndef FOV_HORIZONTAL
#  define FOV_HORIZONTAL 89
# endif

# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 720
# endif

# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 1280
# endif

# ifndef MAX_VELOCITY
#  define MAX_VELOCITY 1000
# endif

# ifndef COEF_ACCELERATION
#  define COEF_ACCELERATION 1.01
# endif

# ifndef COEF_DECELERATION
#  define COEF_DECELERATION 0.99
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

typedef struct s_ray {
	struct s_data		*texture;
	float				a_tan;
	float				x;
	float				y;
	float				x_offset;
	float				y_offset;
	int					map_x;
	int					map_y;
	int					depth_of_field;
	float				traveled_dst;
}	t_ray;

typedef struct s_raycast {
	int					ray_count;
	double				ray_angle;
	int					map_x;
	int					map_y;
	int					map_pos;
	t_ray				horizontal_ray;
	t_ray				vertical_ray;
	t_ray				*winning_ray;
}	t_raycast;

#endif