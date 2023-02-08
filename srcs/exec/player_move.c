/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:26:23 by abucia            #+#    #+#             */
/*   Updated: 2023/02/08 02:23:44 by bducrocq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_forward(t_main *game)
{
	float	new_x;
	float	new_y;

	new_x = game->x + game->delta_x * game->velocity;
	new_y = game->y + game->delta_y * game->velocity;
	if (!is_wall_coliding(game, new_x, new_y))
	{
		game->x = new_x;
		game->y = new_y;
	}
	else if (!is_wall_coliding(game, new_x, game->y))
		game->x = new_x;
	else if (!is_wall_coliding(game, game->x, new_y))
		game->y = new_y;
}

void	move_backward(t_main *game)
{
	float	new_x;
	float	new_y;

	new_x = game->x - game->delta_x * game->velocity;
	new_y = game->y - game->delta_y * game->velocity;
	if (!is_wall_coliding(game, new_x, new_y))
	{
		game->x = new_x;
		game->y = new_y;
	}
	else if (!is_wall_coliding(game, new_x, game->y))
		game->x = new_x;
	else if (!is_wall_coliding(game, game->x, new_y))
		game->y = new_y;
}

void	move_left(t_main *game)
{
	float	new_x;
	float	new_y;
	float	tmp_delta_x;
	float	tmp_delta_y;

	tmp_delta_x = game->delta_x * cos(M_PI_2) - \
	game->delta_y * sin(M_PI_2);
	tmp_delta_y = game->delta_x * sin(M_PI_2) + \
	game->delta_y * cos(M_PI_2);
	new_x = game->x + tmp_delta_x * game->velocity;
	new_y = game->y + tmp_delta_y * game->velocity;
	if (!is_wall_coliding(game, new_x, new_y))
	{
		game->x = new_x;
		game->y = new_y;
	}
	else if (!is_wall_coliding(game, new_x, game->y))
		game->x = new_x;
	else if (!is_wall_coliding(game, game->x, new_y))
		game->y = new_y;
}

void	move_right(t_main *game)
{
	float	new_x;
	float	new_y;
	float	tmp_delta_x;
	float	tmp_delta_y;

	tmp_delta_x = game->delta_x * cos(-M_PI_2) - \
	game->delta_y * sin(-M_PI_2);
	tmp_delta_y = game->delta_x * sin(-M_PI_2) + \
	game->delta_y * cos(-M_PI_2);
	new_x = game->x + tmp_delta_x * game->velocity;
	new_y = game->y + tmp_delta_y * game->velocity;
	if (!is_wall_coliding(game, new_x, new_y))
	{
		game->x = new_x;
		game->y = new_y;
	}
	else if (!is_wall_coliding(game, new_x, game->y))
		game->x = new_x;
	else if (!is_wall_coliding(game, game->x, new_y))
		game->y = new_y;
}

void	move_player(t_main *game)
{
	if (game->move_tab[0] || game->move_tab[1] || game->move_tab[2] || \
	game->move_tab[3] || game->move_tab[4] || game->move_tab[5] || \
	game->move_tab[6] || game->move_tab[7] || game->move_tab[8] || \
	game->move_tab[9] || game->move_tab[10])
	{
		if (game->move_tab[0])
			move_forward(game);
		if (game->move_tab[1])
			move_backward(game);
		if (game->move_tab[2])
			move_left(game);
		if (game->move_tab[3])
			move_right(game);
		if (game->move_tab[5])
			rotate_left(game);
		if (game->move_tab[4])
			rotate_right(game);
		if (game->move_tab[6] || game->move_tab[7])
			look_change(game);
		if (game->move_tab[8] || game->move_tab[9])
			change_fov(game);
		if (game->move_tab[10])
			open_door(game);
		render(game, -1);
	}
}
