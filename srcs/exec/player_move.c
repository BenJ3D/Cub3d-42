/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:26:23 by abucia            #+#    #+#             */
/*   Updated: 2022/11/27 17:47:55 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_wall_coliding(t_main *game, float x, float y)
{
	if (x < 1 || (int)(x / CELL_SIZE) + 1 >= game->ps.map.maxw
		|| y < 1 || (int)(y / CELL_SIZE) + 2 >= game->ps.map.maxh)
		return (1);
	if (game->gm.map[(int)(y / CELL_SIZE)][(int)(x / CELL_SIZE)] == '1' || \
	game->gm.map[((int)ceil(y + MAX_VELOCITY + 1)) / \
	CELL_SIZE][(int)(x / CELL_SIZE)] == '1' || game->gm.map[((int)ceil(y - \
	MAX_VELOCITY - 1)) / CELL_SIZE][(int)(x / CELL_SIZE)] == '1' || \
	game->gm.map[(int)(y / CELL_SIZE)][((int)ceil(x + MAX_VELOCITY + 1)) / \
	CELL_SIZE] == '1' || game->gm.map[(int)(y / CELL_SIZE)][((int)ceil(x - \
	MAX_VELOCITY - 1)) / CELL_SIZE] == '1')
		return (1);
	return (0);
}

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

	new_x = game->x - game->delta_x * game->velocity;
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

void	move_right(t_main *game)
{
	float	new_x;
	float	new_y;

	new_x = game->x + game->delta_x * game->velocity;
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

void	look_change(t_main *game)
{
	if (game->move_tab[7] && game->up_down > -2)
		game->up_down -= 0.008;
	if (game->move_tab[6] && game->up_down < 3)
		game->up_down += 0.008;
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

void	move_player(t_main *game)
{
	if (game->move_tab[0] || game->move_tab[1] || game->move_tab[2] || \
	game->move_tab[3] || game->move_tab[4] || game->move_tab[5] || \
	game->move_tab[6] || game->move_tab[7] || game->move_tab[8] || \
	game->move_tab[9])
	{
		if (game->move_tab[0])
			move_forward(game);
		if (game->move_tab[1])
			move_backward(game);
		if (game->move_tab[2])
			move_left(game);
		if (game->move_tab[3])
			move_right(game);
		if (game->move_tab[4])
			rotate_right(game);
		if (game->move_tab[5])
			rotate_left(game);
		if (game->move_tab[6] || game->move_tab[7])
			look_change(game);
		if (game->move_tab[8] || game->move_tab[9])
			change_fov(game);
		render(game);
		printf("%f, %f\n", game->delta_x, game->delta_y);
	}
}
