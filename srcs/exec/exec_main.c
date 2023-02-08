/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 02:15:01 by bducrocq          #+#    #+#             */
/*   Updated: 2023/02/08 02:17:20 by bducrocq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	stop_mlx(t_main *main)
{
	ft_free_all_and_exit(main);
	return (0);
}

void	exec_main(t_main *game)
{
	game->mlx_win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, \
	"cub3D");
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->mini_map.img = mlx_new_image(game->mlx, game->ps.map.maxw * \
	MAP_CELL_SIZE, (game->ps.map.maxh - 1) * MAP_CELL_SIZE);
	ft_bzero(game->mov_t, 11);
	if (!game->img.img || game->mini_map.img)
		stop_mlx(game);
	game->x = game->gm.playstart.x * CELL_SIZE + 32;
	game->y = game->gm.playstart.y * CELL_SIZE + 32;
	game->delta_x = game->gm.start_rot.x;
	game->delta_y = game->gm.start_rot.y;
	game->mini_map.addr = mlx_get_data_addr(game->mini_map.img, \
	&game->mini_map.bpp, &game->mini_map.line_length, &game->mini_map.end);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp, \
	&game->img.line_length, &game->img.end);
	game->mini_map.bpp /= 8;
	draw_minimap(game);
	game->img.bpp /= 8;
	game->up_down = 1;
	game->fov = FOV_HORIZONTAL;
	draw_minimap(game);
	render(game, -1);
}
