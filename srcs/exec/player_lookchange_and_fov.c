/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_look_and_fov.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:26:23 by abucia            #+#    #+#             */
/*   Updated: 2023/02/08 02:24:18 by bducrocq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	look_up(t_main *game)
{
	if (game->up_down < 3)
		game->up_down += 0.03;
}

void	look_down(t_main *game)
{
	if (game->up_down > -2)
		game->up_down -= 0.03;
}

void	change_fov(t_main *game)
{
	game->plane_x = 0;
	game->delta_x = -1;
	game->delta_y = 0;
	if (game->mov_t[8] && game->fov < 0.80)
		game->fov += 0.005;
	if (game->mov_t[9] && game->fov > 0.30)
		game->fov -= 0.005;
	game->plane_y = game->fov;
}

void	open_door(t_main *game)
{
	double	i;

	i = 0.2;
	while (i < 1.9)
	{
		if (game->gm.map[(int)(game->y / CELL_SIZE + game->delta_y * i)][(int)(game->x / CELL_SIZE + game->delta_x * i)] == 'P')
		{
		game->gm.map[(int)(game->y / CELL_SIZE + game->delta_y * i)][(int)(game->x / CELL_SIZE + game->delta_x * i)] = '0';
			break;
		}
		i += 0.02;
	}
}