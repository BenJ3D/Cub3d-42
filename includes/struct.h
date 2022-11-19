/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 02:44:28 by mal-guna          #+#    #+#             */
/*   Updated: 2022/11/19 01:48:55 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "struct_parsing.h"

typedef struct s_game
{
	int		ac;
	char	**av;
	char	*map_path;
	
}			t_game;

typedef struct s_data
{
	t_pars	ps; //tout pour le parsing
	t_game	gm; //setup regles avec les couleurs, resolution, path textures/map etc
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}			t_data;

#endif
