/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 02:44:28 by mal-guna          #+#    #+#             */
/*   Updated: 2022/11/26 13:33:32 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "cub3d.h"
# include "struct_parsing.h"
# include "exec.h"

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
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
	t_vector		playstart;	//xy = position plyaer start
}				t_game;


typedef struct s_main
{
	t_render		render;
	t_data			img;
	t_pars			ps; //tout pour le parsing
	t_game			gm; //setup regles avec les couleurs, resolution, path textures/map etc
	void			*mlx;
	void			*mlx_win;
	int				win_h;
	int				win_w;
	float			velocity;
	float			x;
	float			y;
}				t_main;

#endif
