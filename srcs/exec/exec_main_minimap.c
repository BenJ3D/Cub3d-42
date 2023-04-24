/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:23:05 by abucia            #+#    #+#             */
/*   Updated: 2023/02/08 02:16:39 by bducrocq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_minimap(t_main *game)
{
	int		w;
	int		h;

	h = (game->ps.map.maxh - 1) * MAP_CELL_SIZE;
	while (--h != -1)
	{
		w = (game->ps.map.maxw) * MAP_CELL_SIZE;
		while (--w != -1)
		{
			if (game->gm.map[h / MAP_CELL_SIZE][w / MAP_CELL_SIZE] == '1')
				my_mlx_pixel_put(&game->mini_map, w, h, \
				colour_to_nb(43, 52, 62));
			else if (game->gm.map[h / MAP_CELL_SIZE][w / MAP_CELL_SIZE] == '0')
				my_mlx_pixel_put(&game->mini_map, w, h, \
				colour_to_nb(25, 25, 40));
			else if (game->gm.map[h / MAP_CELL_SIZE][w / MAP_CELL_SIZE] == 'P')
				my_mlx_pixel_put(&game->mini_map, w, h, \
				colour_to_nb(40, 25, 25));
			else
				my_mlx_pixel_put(&game->mini_map, w, h, \
				colour_to_nb(17, 17, 17));
		}
	}
}

int	translucid_minimap(int color)
{
	if (color == colour_to_nb(17, 17, 17))
		return (0);
	return (1);
}

void	put_minimap(t_main *main)
{
	int					*new_addr;
	t_i_vector			img;
	t_i_vector			map;
	t_i_vector			render;
	static const int	opti = SCREEN_WIDTH / 6;

	new_addr = (int *)main->mini_map.addr;
	if (opti > (SCREEN_HEIGHT >> 1))
		return ;
	img.x = SCREEN_WIDTH - opti;
	map.x = main->x * MAP_CELL_SIZE / CELL_SIZE - (opti >> 1);
	while (img.x < SCREEN_WIDTH)
	{
		img.y = -1;
		map.y = main->y * MAP_CELL_SIZE / CELL_SIZE - (opti >> 1);
		while (++img.y < opti)
			if (++map.y < SCREEN_WIDTH && \
			calc_mini_pix(&render, map, main) == 1)
				if (translucid_minimap(new_addr[render.x + render.y]))
					my_mlx_pixel_put(&main->img, img.x - 24, img.y + 24, \
					new_addr[render.x + render.y]);
		img.x++;
		map.x++;
	}
}
