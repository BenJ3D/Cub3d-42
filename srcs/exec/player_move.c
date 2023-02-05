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
	//printf("pos : %d, %d | CHAR : '%c'\n", (int)(y / CELL_SIZE), (int)(x / CELL_SIZE), game->gm.map[(int)(y / CELL_SIZE)][(int)(x / CELL_SIZE)]);
	if (x < 1 || (int)(x / CELL_SIZE) + 1 >= game->ps.map.maxw
		|| y < 1 || (int)(y / CELL_SIZE) + 2 >= game->ps.map.maxh)
		return (1);
	if (game->gm.map[(int)(y / CELL_SIZE)][(int)(x / CELL_SIZE)] == '1' || \
	game->gm.map[((int)ceil(y + MAX_VELOCITY + 1)) / CELL_SIZE][(int)(x / CELL_SIZE)] == '1' || \
	game->gm.map[((int)ceil(y - MAX_VELOCITY - 1)) / CELL_SIZE][(int)(x / CELL_SIZE)] == '1' || \
	game->gm.map[(int)(y / CELL_SIZE)][((int)ceil(x + MAX_VELOCITY + 1)) / CELL_SIZE] == '1' || \
	game->gm.map[(int)(y / CELL_SIZE)][((int)ceil(x - MAX_VELOCITY - 1)) / CELL_SIZE] == '1')
		return (1);
	return (0);
}

double	assure_360_deg_angle(double a)
{
	double	two_pi;

	two_pi = 2 * M_PI;
	if (a >= two_pi)
		a -= (two_pi);
	if (a < 0)
		a += (two_pi);
	return (a);
}

void	rotate_right(t_main *game)
{
	double old_delta_x = game->delta_x;
	game->delta_x = game->delta_x * cos(0.075) - game->delta_y * sin(0.075);
	game->delta_y = old_delta_x * sin(0.075) + game->delta_y * cos(0.075);
	double old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(0.075) - game->plane_y * sin(0.075);
	game->plane_y = old_plane_x * sin(0.075) + game->plane_y * cos(0.075);
}

void	rotate_left(t_main *game)
{
	double old_delta_x = game->delta_x;
	game->delta_x = game->delta_x * cos(-0.075) - game->delta_y * sin(-0.075);
	game->delta_y = old_delta_x * sin(-0.075) + game->delta_y * cos(-0.075);
	double old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(-0.075) - game->plane_y * sin(-0.075);
	game->plane_y = old_plane_x * sin(-0.075) + game->plane_y * cos(-0.075);
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

	new_x = game->x + cos(game->player_angle + M_PI_2) * game->velocity;
	new_y = game->y + sin(game->player_angle + M_PI_2) * game->velocity;
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

	new_x = game->x + cos(game->player_angle - M_PI_2) * game->velocity;
	new_y = game->y + sin(game->player_angle - M_PI_2) * game->velocity;
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

void	look_up(t_main *game)
{
	game->up_down -= 0.006;
	if (game->up_down < 0.01)
		game->up_down = 0.01;
}

void	look_down(t_main *game)
{
	game->up_down += 0.006;
	if (game->up_down > 1.99)
		game->up_down = 1.99;
}

void	move_player(t_main *game)
{
	if (game->move_tab[0] || game->move_tab[1] || game->move_tab[2] || \
	game->move_tab[3] || game->move_tab[4] || game->move_tab[5] || \
	game->move_tab[6] || game->move_tab[7])
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
		if (game->move_tab[6])
			look_up(game);
		if (game->move_tab[7])
			look_down(game);
		render(game);
	}
}