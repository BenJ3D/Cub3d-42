/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 02:44:28 by mal-guna          #+#    #+#             */
/*   Updated: 2022/11/20 03:53:17 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "struct_parsing.h"

typedef struct s_game
{
	int		ceiling[3]; //RGB
	int		floor[3]; //RGB
	char	*pathNO;
	char	*pathSO;
	char	*pathWE;
	char	*pathEA;
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
