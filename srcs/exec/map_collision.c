/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:47:40 by abucia            #+#    #+#             */
/*   Updated: 2022/11/26 08:47:40 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	map_collision(float x, float y, t_main *game)
{
	float	cell_x;
	float	cell_y;
	int		i;

	cell_x = x / CELL_SIZE;
	cell_y = y / CELL_SIZE;
	i = 0;
	if (0 <= x && 0 <= y && game->ps.map.maxh > cell_y && game->ps.map.maxh > cell_x)
		return (1);
	while (i < MAX_VELOCITY)
	{
		if (game->gm.map[(int)cell_x][(int)cell_y])
		i++;
	}
	
}