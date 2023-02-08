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

int	stop_mlx(int keycode, t_main *main)
{
	(void)keycode;
	// ft_free_all_and_exit(main); //provoque segfault car *main est non valid
	(void)main;
	exit(0);
	return (0);
}

void	exec_main(t_main *game)
{
	ft_bzero(game->move_tab, 11);
	game->move_tab[10] = 0;
	game->x = game->gm.playstart.x * CELL_SIZE + 32;
	game->y = game->gm.playstart.y * CELL_SIZE + 32;
	game->delta_x = game->gm.start_rot.x;
	game->delta_y = game->gm.start_rot.y;
	game->mini_map.img = mlx_new_image(game->mlx, game->ps.map.maxw * \
	MAP_CELL_SIZE, (game->ps.map.maxh - 1) * MAP_CELL_SIZE);
	game->mlx_win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, \
	"cub3D");
	game->mini_map.addr = mlx_get_data_addr(game->mini_map.img, \
	&game->mini_map.bpp, &game->mini_map.line_length, &game->mini_map.end);
	game->mini_map.bpp /= 8;
	draw_minimap(game);
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp, \
	&game->img.line_length, &game->img.end);
	game->img.bpp /= 8;
	game->up_down = 1;
	game->fov = FOV_HORIZONTAL;
	draw_minimap(game);
	render(game, -1);
}
