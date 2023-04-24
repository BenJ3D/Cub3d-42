/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 02:12:00 by bducrocq          #+#    #+#             */
/*   Updated: 2023/02/08 02:17:13 by bducrocq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_mov_t(t_main *game)
{
	if (game->mov_t[0] || game->mov_t[1] || game->mov_t[2] || game->mov_t[3] \
	|| game->mov_t[4] || game->mov_t[5] || game->mov_t[6] || game->mov_t[7] || \
	game->mov_t[8] || game->mov_t[9] || game->mov_t[10])
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	calc_mini_pix(t_i_vector *vect, t_i_vector map, t_main *main)
{
	static int	var1 = 0;
	static int	var2 = 0;

	if (var1 == 0)
	{
		var1 = (main->ps.map.maxh - 1) * MAP_CELL_SIZE;
		var2 = main->ps.map.maxw * MAP_CELL_SIZE;
	}
	vect->x = map.y % var1;
	if (vect->x < 0 || map.y > var1)
		return (-1);
	vect->x *= var2;
	vect->y = map.x % var2;
	if (vect->y < 0 || map.x > var2)
		return (-1);
	return (1);
}

int	colour_to_nb(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int	*dst;

	dst = (int *)data->addr;
	dst[y * data->line_length + x] = color;
}
