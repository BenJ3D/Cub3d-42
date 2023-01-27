/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 02:44:28 by mal-guna          #+#    #+#             */
/*   Updated: 2022/12/09 16:24:45 by abucia           ###   ########lyon.fr   */
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
// # define HEIGHT 768
// # define WIDTH 768
// # define ROTATION_SPEED 0.04
// # define ONE_DEGREE_RAD 0.00116355333
// # define BLOCK_SIZE 32
// # define SPEED 1

# define LEGITCHAR "SNEW01"	//authorized character in map
# define PLAYERSTART "SNEW"	// char for player start position
# define FLOOR '0'	// char for player start position
# define CUBEXT ".cub"		//extension requise pour la map
# define IMGEXT ".xpm"		//extension requise pour les images
# define WALL '1'
# define EMPTY '-'		//char de substitution dans les vides de la map

# define PARAM_NO "NO"		//texture wall North
# define PARAM_SO "SO"		//texture wall South
# define PARAM_WE "WE"		//texture wall West
# define PARAM_EA "EA"		//texture wall East
# define PARAM_C "C"		//ceiling color
# define PARAM_F "F"		//floor color

/* Linux Keys */
# ifdef __linux__
#  define KEY_RIGHT 65363
#  define KEY_LEFT 65361
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 100
#  define KEY_D 113
#  define DOORS 101 // E
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

typedef struct s_raycast {
	int					ray_count;
	double				ray_angle;
	int					map_x;
	int					map_y;
	int					map_pos;
	t_ray				horizontal_ray;
	t_ray				vertical_ray;
	t_ray				winning_ray;
}	t_raycast;

typedef struct s_render
{
	float	other;
}	t_render;

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
}				t_vector;
typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				end;
	int				width;
	int				height;
}				t_data;

typedef struct s_game
{
	char			**map;
	t_vector		c_rgb; // ceiling color RGB (xyz)
	t_vector		f_rgb; // floor color RGB (xyz)
	t_data			img_no;
	t_data			img_so;
	t_data			img_we;
	t_data			img_ea;
	int				cell_size;
	t_vector		playstart;	//xy = position plyaer start
}				t_game;

typedef struct s_main
{
	t_render		render;
	t_data			mini_map;
	t_data			img;
	t_data			background;
	t_pars			ps; //tout pour le parsing
	t_game			gm; //setup regles avec les couleurs, resolution, path textures/map etc
	void			*mlx;
	void			*mlx_win;
	int				win_h;
	int				win_w;
	float			velocity;
	float			x;
	float			y;
	double			fov;
	float			player_angle;
	float			delta_x;
	float			delta_y;
	float			plane_x;
	float			plane_y;
	t_raycast		raycast;
	int				move_tab[10];
}				t_main;

/* exec utils */
float		deg_to_rad(float i_deg);
float		rad_to_deg(float i_rad);
void		exec_main(t_main *game);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			key_release(int keycode, t_main *main);
int			key_press(int keycode, t_main *main);
int			stop_mlx(int keycode, t_main *main);

void		move_player(t_main *game);
void		move_backward(t_main *game);
void		move_right(t_main *game);
void		move_left(t_main *game);
void		move_forward(t_main *game);

void		update_velocity(t_main *main);

int	render_next_frame(t_main *main);

/* Parsing */
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

/* init mlx */
void		ft_init_mlx_img(t_main *main);

/* libft custom */
void		*ft_calloc_cub(size_t count, size_t size, t_main *main);

/* free ft */
void		ft_free_all_and_exit(t_main *main);
void		ft_free_all_and_exit_err(t_main *main, int error);

/* Error display */
void		ft_err_display(int errtype, t_main *main); //FIXME: unless ?
void		ft_err_display_and_exit(int errtype, t_main *main);

/* ft dbg //TODO: del before final push */
void		dbg_display_all_parameter_value(t_main *main);
void		dbg_display_velocity(t_main *main);

# define COLOR_BLACK	"\001\033[0;30m\002"
# define COLOR_RED		"\001\033[0;31m\002"
# define COLOR_GREEN	"\001\033[0;32m\002"
# define COLOR_YELLOW	"\001\033[0;33m\002"
# define COLOR_BLUE		"\001\033[0;34m\002"
# define COLOR_PURPLE	"\001\033[0;35m\002"
# define COLOR_CYAN		"\001\033[0;36m\002"
# define COLOR_NONE		"\001\033[0;37m\002"

#endif