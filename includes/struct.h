/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 02:44:28 by mal-guna          #+#    #+#             */
/*   Updated: 2022/11/21 19:54:14 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "struct_parsing.h"

typedef struct s_vector
{
	int	x;
	int	y;
	int	z;
}			t_vector;

typedef struct s_game
{
	t_vector	ceiling; //RGB
	t_vector	floor; //RGB
	t_data		north;
	char		*pathNO;
	char		*pathSO;
	char		*pathWE;
	char		*pathEA;
}			t_game;

typedef struct s_data
{
	void *img;
	char *addr;
	int bpp;
	int line_length;
	int endian;
}			t_data;

typedef struct s_main
{
	t_data	main;
	t_pars	ps; //tout pour le parsing
	t_game	gm; //setup regles avec les couleurs, resolution, path textures/map etc
	
}			t_main;

#endif
