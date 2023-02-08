/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:26:23 by abucia            #+#    #+#             */
/*   Updated: 2023/02/08 02:19:25 by bducrocq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate_right(t_main *game)
{
	float	old_delta_x;
	float	old_plane_x;

	old_delta_x = game->delta_x;
	old_plane_x = game->plane_x;
	game->delta_x = game->delta_x * cos(ROT_SPEED) - \
	game->delta_y * sin(ROT_SPEED);
	game->delta_y = old_delta_x * sin(ROT_SPEED) + \
	game->delta_y * cos(ROT_SPEED);
	game->plane_x = game->plane_x * cos(ROT_SPEED) - \
	game->plane_y * sin(ROT_SPEED);
	game->plane_y = old_plane_x * sin(ROT_SPEED) + \
	game->plane_y * cos(ROT_SPEED);
}

void	rotate_left(t_main *game)
{
	float	old_delta_x;
	float	old_plane_x;

	old_delta_x = game->delta_x;
	old_plane_x = game->plane_x;
	game->delta_x = game->delta_x * cos(-ROT_SPEED) - \
	game->delta_y * sin(-ROT_SPEED);
	game->delta_y = old_delta_x * sin(-ROT_SPEED) + \
	game->delta_y * cos(-ROT_SPEED);
	game->plane_x = game->plane_x * cos(-ROT_SPEED) - \
	game->plane_y * sin(-ROT_SPEED);
	game->plane_y = old_plane_x * sin(-ROT_SPEED) + \
	game->plane_y * cos(-ROT_SPEED);
}
