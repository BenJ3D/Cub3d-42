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

void	look_change(t_main *game)
{
	if (game->move_tab[7] && game->up_down > -2)
		game->up_down -= 0.03;
	if (game->move_tab[6] && game->up_down < 3)
		game->up_down += 0.03;
}

void	change_fov(t_main *game)
{
	game->plane_x = 0;
	game->delta_x = -1;
	game->delta_y = 0;
	if (game->move_tab[8] && game->fov < 0.80)
		game->fov += 0.005;
	if (game->move_tab[9] && game->fov > 0.30)
		game->fov -= 0.005;
	game->plane_y = game->fov;
}
