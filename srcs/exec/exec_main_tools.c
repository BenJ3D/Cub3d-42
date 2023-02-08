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

int	calc_mini_pix(t_i_vector *vect, t_i_vector map, t_main *main)
{
	vect->x = map.y % ((main->ps.map.maxh - 1) * MAP_CELL_SIZE);
	if (vect->x < 0 || map.y > (main->ps.map.maxh - 1) * MAP_CELL_SIZE)
		return (-1);
	vect->x *= main->ps.map.maxw * MAP_CELL_SIZE;
	vect->y = map.x % (main->ps.map.maxw * MAP_CELL_SIZE);
	if (vect->y < 0 || map.x > main->ps.map.maxw * MAP_CELL_SIZE)
		return (-1);
	return (1);
}

int	colour_to_nb(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + (b));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp));
	*(unsigned int *)dst = color;
}
