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
	if (check_mov_t(game) == EXIT_SUCCESS)
	{
		if (game->mov_t[0])
			move_forward(game);
		if (game->mov_t[1])
			move_backward(game);
		if (game->mov_t[2])
			move_left(game);
		if (game->mov_t[3])
			move_right(game);
		if (game->mov_t[5])
			rotate_left(game);
		if (game->mov_t[4])
			rotate_right(game);
		if (game->mov_t[6])
			look_up(game);
		if (game->mov_t[7])
			look_down(game);
		if (game->mov_t[8] || game->mov_t[9])
			change_fov(game);
		if (game->mov_t[10])
			open_door(game);
		render(game, -1);
	}
}
