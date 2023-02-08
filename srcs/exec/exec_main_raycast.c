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

void	init_put_pixel_ray(t_main *main, t_data *img)
{
	if (main->raycast.side == 0)
		main->raycast.wallx = main->y / CELL_SIZE + \
		main->raycast.perp_wall_dist / CELL_SIZE * main->raycast.ray_dir.y;
	else
		main->raycast.wallx = main->x / CELL_SIZE + \
		main->raycast.perp_wall_dist / CELL_SIZE * main->raycast.ray_dir.x;
	main->raycast.wallx -= floorf(main->raycast.wallx);
	main->raycast.tex.x = (int)(main->raycast.wallx * img->height);
	if (main->raycast.side == 0 && main->raycast.ray_dir.x > 0)
		main->raycast.tex.x = img->width - main->raycast.tex.x - 1;
	if (main->raycast.side == 1 && main->raycast.ray_dir.y < 0)
		main->raycast.tex.x = img->width - main->raycast.tex.x - 1;
	main->raycast.f_step = 1.0 * img->height / main->raycast.line_height;
	main->raycast.tex_pos = (main->raycast.draw_start - SCREEN_HEIGHT / 2 * \
	main->up_down + main->raycast.line_height / 2) * main->raycast.f_step;
	main->raycast.tex.y = (int)main->raycast.tex_pos & (img->height - 1);
}
