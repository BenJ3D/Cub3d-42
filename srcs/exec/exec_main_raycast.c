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
	if (main->cast.side_dist.x < main->cast.side_dist.y)
	{
		main->cast.side_dist.x += main->cast.delta_dist.x;
		main->cast.map.x += main->cast.step.x;
		main->cast.side = 0;
	}
	else
	{
		main->cast.side_dist.y += main->cast.delta_dist.y;
		main->cast.map.y += main->cast.step.y;
		main->cast.side = 1;
	}
}

int	raycast_to_wall(t_main *main)
{
	while (main->cast.hit == 0)
	{
		increase_raycast_step(main);
		if (main->gm.map[main->cast.map.y / CELL_SIZE] \
		[main->cast.map.x / CELL_SIZE] != '0')
			main->cast.hit = 1;
		else if (main->cast.map.y / CELL_SIZE > main->ps.map.maxh - 1 || \
		main->cast.map.x <= 0 || main->cast.map.x / CELL_SIZE > \
		main->ps.map.maxw - 1 || main->cast.map.y <= 0)
		{
			main->cast.side = -1;
			return (EXIT_FAILURE);
		}
	}
	if (main->cast.side == 0)
		main->cast.wall_hit_dist = \
		main->cast.side_dist.x - main->cast.delta_dist.x;
	else if (main->cast.side == 1)
		main->cast.wall_hit_dist = \
		main->cast.side_dist.y - main->cast.delta_dist.y;
	return (EXIT_SUCCESS);
}

void	init_put_pixel_ray(t_main *main, t_data *img, t_data *shine)
{
	if (main->cast.side == 0)
		main->cast.wallx = main->y / CELL_SIZE + \
		main->cast.perp_wall_dist / CELL_SIZE * main->cast.ray_dir.y;
	else
		main->cast.wallx = main->x / CELL_SIZE + \
		main->cast.perp_wall_dist / CELL_SIZE * main->cast.ray_dir.x;
	main->cast.wallx -= floorf(main->cast.wallx);
	if (BOOL == 1 && main->cast.a_time < 6)
	{
		main->cast.s_tex.x = (int)(main->cast.wallx * shine->height);
		main->cast.s_tex.x = shine->width - main->cast.s_tex.x - 1;
		main->cast.s_f_step = 1.0 * shine->height / main->cast.line_height;
		main->cast.s_tex_pos = (main->cast.draw_start - SCREEN_HEIGHT / 2 * \
		main->up_down + main->cast.line_height / 2) * main->cast.s_f_step;
		main->cast.s_tex.y = (int)main->cast.s_tex_pos & (shine->height - 1);
	}
	main->cast.tex.x = (int)(main->cast.wallx * img->height);
	main->cast.tex.x = img->width - main->cast.tex.x - 1;
	main->cast.f_step = 1.0 * img->height / main->cast.line_height;
	main->cast.tex_pos = (main->cast.draw_start - SCREEN_HEIGHT / 2 * \
	main->up_down + main->cast.line_height / 2) * main->cast.f_step;
	main->cast.tex.y = (int)main->cast.tex_pos & (img->height - 1);
}
