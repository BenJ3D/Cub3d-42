/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_coliding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:26:23 by abucia            #+#    #+#             */
/*   Updated: 2023/02/08 02:20:42 by bducrocq         ###   ########lyon.fr   */
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
	MAX_VELOCITY - 1)) / CELL_SIZE] == '1' || \
	game->gm.map[(int)(y / CELL_SIZE)][(int)(x / CELL_SIZE)] == 'P' || \
	game->gm.map[((int)ceil(y + MAX_VELOCITY + 1)) / \
	CELL_SIZE][(int)(x / CELL_SIZE)] == 'P' || game->gm.map[((int)ceil(y - \
	MAX_VELOCITY - 1)) / CELL_SIZE][(int)(x / CELL_SIZE)] == 'P' || \
	game->gm.map[(int)(y / CELL_SIZE)][((int)ceil(x + MAX_VELOCITY + 1)) / \
	CELL_SIZE] == 'P' || game->gm.map[(int)(y / CELL_SIZE)][((int)ceil(x - \
	MAX_VELOCITY - 1)) / CELL_SIZE] == 'P')
		return (1);
	return (0);
}
