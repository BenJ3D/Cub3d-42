/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 02:44:28 by mal-guna          #+#    #+#             */
/*   Updated: 2022/11/21 04:24:54 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_PARSING_H
# define STRUCT_PARSING_H

enum e_errtype
{
	ERR_NONE,
	ERR_BADEXTENSION,
	ERR_NOARG,
	ERR_ARG_FORBIDEN,
	ERR_TOOMANYARG,
	ERR_WALL,
	ERR_PLAYER_MISSING,
	ERR_PLAYER_BAD_POS,
	ERR_PARAM_UNKNOWN,
	ERR_PARAM_INVALID,
	ERR_PARAM_TO_HIGH,
	ERR_PARAM_NO_C,
	ERR_PARAM_NO_F,
	ERR_TXTMISSING_NO,
	ERR_TXTMISSING_SO,
	ERR_TXTMISSING_WE,
	ERR_TXTMISSING_EA,
	ERR_OTHER
};

enum e_boxtype
{
	BOX_UNKNOWN,
	BOX_WALL,
	BOX_FLOOR,
	BOX_PLAYER_S,
	BOX_PLAYER_N,
	BOX_PLAYER_E,
	BOX_PLAYER_W,
	BOX_SPACE
};

typedef struct s_box
{
	int		type;
	int		posx;
	int		posy;
	int		in_map;
}			t_box;

typedef struct s_map
{
	int		max_width;
	int		height;
}			t_map;

typedef struct s_pars
{
	int		ac;
	char	**av;
	char	*map_path;
	int		map_fd;
	int		param_ok;
}			t_pars;

#endif
