/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main_other4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:23:05 by abucia            #+#    #+#             */
/*   Updated: 2023/02/08 01:48:52 by bducrocq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	select_step(t_main *main)
{
	if (main->raycast.ray_dir.x < 0)
	{
		main->raycast.step.x = -1;
		main->raycast.side_dist.x = (main->x - main->raycast.map.x) \
		* main->raycast.delta_dist.x;
	}
	else
	{
		main->raycast.step.x = 1;
		main->raycast.side_dist.x = (main->raycast.map.x + 1.0 - main->x) \
		* main->raycast.delta_dist.x;
	}
	if (main->raycast.ray_dir.y < 0)
	{
		main->raycast.step.y = -1;
		main->raycast.side_dist.y = (main->y - main->raycast.map.y) \
		* main->raycast.delta_dist.y;
	}
	else
	{
		main->raycast.step.y = 1;
		main->raycast.side_dist.y = (main->raycast.map.y + 1.0 - main->y) \
		* main->raycast.delta_dist.y;
	}
}

void	exec_main(t_main *game)
{
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
	game->ray.img = mlx_new_image(game->mlx, game->ps.map.maxw * MAP_CELL_SIZE, (game->ps.map.maxh - 1) * MAP_CELL_SIZE);
	game->ray.addr = mlx_get_data_addr(game->ray.img, &game->ray.bpp, \
	&game->ray.line_length, &game->ray.end);
	game->ray.bpp /= 8;
	game->up_down = 1;
	game->fov = FOV_HORIZONTAL;
	draw_minimap(game);
	render(game, 0, -1);
}
