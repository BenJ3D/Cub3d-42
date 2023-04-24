/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 02:44:28 by mal-guna          #+#    #+#             */
/*   Updated: 2022/12/07 13:31:43 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_PARSING_H
# define STRUCT_PARSING_H

# include "cub3d.h"
# ifndef PATH_MAX
#  define PATH_MAX 4096
# endif

enum e_errtype
{
	ERR_NONE,
	ERR_BADEXTENSION,
	ERR_IMGBADEXTENSION,
	ERR_NOARG,
	ERR_ARG_FORBIDEN,
	ERR_TOOMANYARG,
	ERR_MAP_UNKNOWN_CHAR,
	ERR_MAP_WALLNOCLOSE,
	ERR_PLAYER_MISSING,
	ERR_PLAYER_MORE,
	ERR_PLAYER_BAD_POS,
	ERR_PARAM_UNKNOWN,
	ERR_PARAM_INVALID,
	ERR_PARAM_DUPLICATED,
	ERR_PARAM_MISSING,
	ERR_PARAM_TO_HIGH,
	ERR_PARAM_NO_C,
	ERR_PARAM_NO_F,
	ERR_TXTMISSING_NO,
	ERR_TXTMISSING_SO,
	ERR_TXTMISSING_WE,
	ERR_TXTMISSING_EA,
	ERR_MLX_FAILINIT,
	ERR_OTHER
};
typedef struct s_textpath
{
	char			path_no[PATH_MAX];
	char			path_so[PATH_MAX];
	char			path_we[PATH_MAX];
	char			path_ea[PATH_MAX];
}				t_textpath;

typedef struct s_box
{
	int				type;
	int				posx;
	int				posy;
	int				in_map;
}			t_box;

typedef struct s_map
{
	int				maxw;
	int				maxh;
	char			*maptmp;
}			t_map;

typedef struct s_pars
{
	int				ac;
	char			charplayer;
	char			**av;
	char			*map_path;
	int				map_fd;
	int				f_isalreadyset;
	int				c_isalreadyset;
	int				param_count;
	t_textpath		txtpath;
	t_map			map;
	char			**ptrbuf;
}			t_pars;

#endif
