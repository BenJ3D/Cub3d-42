/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 02:44:28 by mal-guna          #+#    #+#             */
/*   Updated: 2023/02/08 03:29:20 by bducrocq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./exec.h"
# include "./struct_parsing.h"
# ifdef __linux__
#  include "../libs/mlx_linux/mlx.h"
# else
#  include "../libs/mlx_mac/mlx.h"
# endif
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
// # define SCREEN_HEIGHT 1080
// # define SCREEN_WIDTH 1920
// # define ROTATION_SPEED 0.04
// # define ONE_DEGREE_RAD 0.00116355333
// # define BLOCK_SIZE 32
// # define SPEED 1

# ifndef BONUS
#  define LEGITCHAR "SNEW01"
# else
#  define LEGITCHAR "PSNEW01"
# endif

# define PLAYERSTART "SNEW"	// char for player start position
# define FLOOR '0'	// char for player start position
# define CUBEXT ".cub"		//extension requise pour la map
# define IMGEXT ".xpm"		//extension requise pour les images
# define DOOR 'P'
# define WALL '1'
# define EMPTY '-'		//char de substitution dans les vides de la map

# define PARAM_NO "NO"		//texture wall North
# define PARAM_SO "SO"		//texture wall South
# define PARAM_WE "WE"		//texture wall West
# define PARAM_EA "EA"		//texture wall East
# define PARAM_C "C"		//ceiling color
# define PARAM_F "F"		//floor color

# define IMG_DOOR "./assets/textures/door/door.xpm"

/* Linux Keys */
# ifdef __linux__
#  define KEY_RIGHT 65363
#  define KEY_LEFT 65361
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_PLUS 65451
#  define KEY_MINUS 65453
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_Q 113
#  define KEY_D 100
#  define KEY_DOOR 101 // E
#  define ESC 65307
# endif

/* Mac Keys */
# ifdef __APPLE__
#  define KEY_RIGHT 124
#  define KEY_LEFT 123
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_A 0
#  define KEY_D 2
#  define DOORS 14
#  define ESC 53
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

typedef struct s_d_vector
{
	double	x;
	double	y;
}	t_d_vector;

typedef struct s_i_vector
{
	int	x;
	int	y;
}	t_i_vector;

typedef struct s_raycast {
	int			x;
	double		camera_x;
	t_d_vector	ray_dir;
	t_i_vector	map;
	t_d_vector	side_dist;
	t_d_vector	delta_dist;
	double		perp_wall_dist;
	t_i_vector	step;
	int			hit;
	int			side;
	double		wall_hit_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	float		wallx;
	t_i_vector	tex;
	float		tex_step;
	float		tex_pos;
	float		f_step;
	double		fov;
}	t_raycast;

/**
 * @brief xyz = RGB values
 * 
 */
typedef struct s_vector
{
	int				x;
	int				y;
	int				z;
	int				i;
	int				s;
	char			*tmp;
}	t_vector;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				end;
	int				width;
	int				height;
}	t_data;

typedef struct s_game
{
	char			**map;
	t_vector		c_rgb;
	t_vector		f_rgb;
	t_data			img_no;
	t_data			img_so;
	t_data			img_we;
	t_data			img_ea;
	t_data			img_door;
	int				cell_size;
	t_vector		playstart;
	t_d_vector		start_rot;
	float			pi;
}	t_game;

typedef struct s_main
{
	t_data		mini_map;
	t_data		img;
	t_pars		ps;
	t_game		gm;
	void		*mlx;
	void		*mlx_win;
	int			win_h;
	int			win_w;
	float		velocity;
	float		x;
	float		y;
	double		fov;
	float		player_angle;
	float		delta_x;
	float		delta_y;
	float		plane_x;
	float		plane_y;
	double		up_down;
	t_raycast	cast;
	int			mov_t[11];
}	t_main;

/* exec utils */
float		deg_to_rad(float i_deg); // FIXME: introuvable ?
float		rad_to_deg(float i_rad); // FIXME: introuvable ?
void		exec_main(t_main *game);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			key_release(int keycode, t_main *main);
int			key_press(int keycode, t_main *main);
int			stop_mlx(t_main *main);

int			colour_to_nb(int r, int g, int b);
void		draw_minimap(t_main *game);
void		init_put_pixel_ray(t_main *main, t_data *img);
void		put_pixel_from_ray(t_main *main, t_data *img, int new_x, int j);
void		init_dda(t_main *main, int x);
void		select_step(t_main *main);

void		increase_raycast_step(t_main *main);
int			raycast_to_wall(t_main *main);
void		define_start_end(t_main *main);
void		select_wall_to_put_pixel(t_main *main, int x);
int			calc_mini_pix(t_i_vector *vect, t_i_vector map, t_main *main);

int			translucid_minimap(int color);
void		put_minimap(t_main *main);
void		render(t_main *main, double i);
int			render_next_frame(t_main *main);
int			check_mov_t(t_main *main);

/* exec player */
void		move_player(t_main *game);
void		move_backward(t_main *game);
void		move_right(t_main *game);
void		move_left(t_main *game);
void		move_forward(t_main *game);

void		rotate_right(t_main *game);
void		rotate_left(t_main *game);

void		update_velocity(t_main *main);

int			is_wall_coliding(t_main *game, float x, float y);
void		change_fov(t_main *game);
void		look_up(t_main *game);
void		look_down(t_main *game);
void		open_door(t_main *game);

/* Parsing */
void		calc_n_and_s(t_main *game, double pi, double fov);
int			ft_start_parsing(t_main *main);
int			ft_pars_check_has_chars(char c, char *legalchar, t_main *main);
t_vector	ft_get_rgb_value(char *buf, t_main *main);
void		ft_err_rgb(int errtype, char *tofree, t_main *main);

/* parsing files */
int			ft_pars_check_type_file(const char *path, const char *filetype);
int			ft_pars_openfile(const char *path);
int			ft_set_parameters_with_file(t_main *main);
void		ft_pars_headerfile(char *buf, t_main *main);
void		ft_pars_check_range_rgb(t_vector vec, t_main *main);
void		ft_getpath_texture(char *str, char dest[PATH_MAX], t_main *main);

/* parsing map */
int			ft_pars_map(char *buf, t_main *main);
int			ft_pars_norm_map(t_main *main);
int			ft_pars_check_wall(t_main *main);
void		ft_pars_check_player_pos(t_main *main);
char		*ft_get_next_word_custom_i(char *buf, int *i2, t_main *main);

/* init mlx */
void		ft_init_mlx_img(t_main *main);

/* libft custom */
void		*ft_calloc_cub(size_t count, size_t size, t_main *main);

/* free ft */
void		ft_free_all_and_exit(t_main *main);
void		ft_free_all_and_exit_err(t_main *main, int error);

/* Error display */
void		ft_err_display(int errtype, t_main *main);
void		ft_err_display_and_exit(int errtype, t_main *main);

# define COLOR_BLACK	"\001\033[0;30m\002"
# define COLOR_RED		"\001\033[0;31m\002"
# define COLOR_GREEN	"\001\033[0;32m\002"
# define COLOR_YELLOW	"\001\033[0;33m\002"
# define COLOR_BLUE		"\001\033[0;34m\002"
# define COLOR_PURPLE	"\001\033[0;35m\002"
# define COLOR_CYAN		"\001\033[0;36m\002"
# define COLOR_NONE		"\001\033[0;37m\002"

#endif
