/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 02:44:28 by mal-guna          #+#    #+#             */
/*   Updated: 2022/11/23 21:34:01 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./struct.h"
# include "./struct_parsing.h"
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
// # include <sys/syslimits.h>

/* Game Settings */
// # define HEIGHT 768
// # define WIDTH 768
// # define ROTATION_SPEED 0.04
// # define ONE_DEGREE_RAD 0.00116355333
// # define BLOCK_SIZE 32
// # define SPEED 1

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


# define PATH_MAX 1024
# define LEGITCHAR " SNEW01"	//authorized character in map
# define CUBEXT ".cub"			//extension requise

# define PARAM_NO "NO"			//texture wall North
# define PARAM_SO "SO"			//texture wall South
# define PARAM_WE "WE"			//texture wall West
# define PARAM_EA "EA"			//texture wall East
# define PARAM_C "C"			//ceiling color
# define PARAM_F "F"			//floor color

/* Parsing */
int			ft_start_parsing(t_main *main);
int			ft_pars_check_if_legal_char(char c);
t_vector	ft_get_rgb_value(char *buf, t_main *main);

/* parsing files */
int			ft_pars_check_type_file(const char *path, const char *filetype);
int			ft_pars_openfile(const char *path);
int			ft_set_parameters_with_file_header(t_main *main);
void		ft_pars_headerfile(char *buf, t_main *main);

/* init mlx */
t_data		ft_init_mlx_img(char *buf, t_main *main);

/* libft custom */
void		*ft_calloc_cub(size_t count, size_t size, t_main *main); //exit if malloc fail


/* free ft */
void		ft_free_all_and_exit(t_main *main);
void		ft_free_all_and_exit_err(t_main *main, int error);

/* Error display */
void		ft_err_display(int errtype, t_main *main); //FIXME: unless ?
void		ft_err_display_and_exit(int errtype, t_main *main);

/* ft dbg //TODO: del before final push */
void		dbg_display_all_parameter_value(t_main *main);




# define COLOR_BLACK	"\001\033[0;30m\002"
# define COLOR_RED		"\001\033[0;31m\002"
# define COLOR_GREEN	"\001\033[0;32m\002"
# define COLOR_YELLOW	"\001\033[0;33m\002"
# define COLOR_BLUE		"\001\033[0;34m\002"
# define COLOR_PURPLE	"\001\033[0;35m\002"
# define COLOR_CYAN		"\001\033[0;36m\002"
# define COLOR_NONE		"\001\033[0;37m\002"

#endif