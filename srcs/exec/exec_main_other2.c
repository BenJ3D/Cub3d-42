/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:23:05 by abucia            #+#    #+#             */
/*   Updated: 2022/12/10 15:40:10 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	increase_raycast_step(t_main *main)
{
	if (main->raycast.side_dist.x < main->raycast.side_dist.y)
	{
		main->raycast.side_dist.x += main->raycast.delta_dist.x;
		main->raycast.map.x += main->raycast.step.x;
		main->raycast.side = 0;
	}
	else
	{
		main->raycast.side_dist.y += main->raycast.delta_dist.y;
		main->raycast.map.y += main->raycast.step.y;
		main->raycast.side = 1;
	}
}

int	raycast_to_wall(t_main *main)
{
	while (main->raycast.hit == 0)
	{
		increase_raycast_step(main);
		my_mlx_pixel_put(&main->ray, main->raycast.map.x * \
		MAP_CELL_SIZE / CELL_SIZE, main->raycast.map.y * \
		MAP_CELL_SIZE / CELL_SIZE, 0xFFFFFF);
		if (main->gm.map[main->raycast.map.y / CELL_SIZE] \
		[main->raycast.map.x / CELL_SIZE] != '0')
			main->raycast.hit = 1;
		else if (main->raycast.map.y / CELL_SIZE > main->ps.map.maxh - 1 || \
		main->raycast.map.x <= 0 || main->raycast.map.x / CELL_SIZE > \
		main->ps.map.maxw - 1 || main->raycast.map.y <= 0)
		{
			main->raycast.side = -1;
			return (EXIT_FAILURE);
		}
	}
	if (main->raycast.side == 0)
		main->raycast.wall_hit_dist = \
		main->raycast.side_dist.x - main->raycast.delta_dist.x;
	else if (main->raycast.side == 1)
		main->raycast.wall_hit_dist = \
		main->raycast.side_dist.y - main->raycast.delta_dist.y;
	return (EXIT_SUCCESS);
}

void	define_start_end(t_main *main)
{
	main->raycast.line_height = (int)(SCREEN_HEIGHT / \
	(main->raycast.wall_hit_dist / (CELL_SIZE - 100.0f * main->fov + 50)));
	main->raycast.draw_start = -main->raycast.line_height / 2 + \
	SCREEN_HEIGHT / 2 * main->up_down + 1;
	if (main->raycast.draw_start < 0)
		main->raycast.draw_start = 0;
	main->raycast.draw_end = main->raycast.line_height / 2 + \
	SCREEN_HEIGHT / 2 * main->up_down - 1;
	if (main->raycast.draw_end >= SCREEN_HEIGHT)
		main->raycast.draw_end = SCREEN_HEIGHT - 1;
}

void	select_wall_to_put_pixel(t_main *main, int x)
{
	if (main->raycast.side == 0)
		main->raycast.perp_wall_dist = (main->raycast.map.x - main->x + \
		(1 - main->raycast.step.x) / 2) / main->raycast.ray_dir.x;
	else
		main->raycast.perp_wall_dist = (main->raycast.map.y - main->y + \
		(1 - main->raycast.step.y) / 2) / main->raycast.ray_dir.y;
	if (main->raycast.perp_wall_dist == 0)
		main->raycast.perp_wall_dist = 0.1;
	if (main->raycast.side == 1 && main->raycast.map.y < main->y)
		put_pixel_from_ray(main, &main->gm.img_no, x, -1);
	else if (main->raycast.side == 1)
		put_pixel_from_ray(main, &main->gm.img_so, x, -1);
	else if (main->raycast.map.x > main->x && main->raycast.side == 0)
		put_pixel_from_ray(main, &main->gm.img_we, x, -1);
	else
		put_pixel_from_ray(main, &main->gm.img_ea, x, -1);
}

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
