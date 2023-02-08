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

void	put_pixel_from_ray(t_main *main, t_data *img, int new_x, int j)
{
	int	*new_addr;

	new_addr = (int *)img->addr;
	init_put_pixel_ray(main, img);
	while (++j < SCREEN_HEIGHT)
	{
		if (j >= main->raycast.draw_start && j <= main->raycast.draw_end)
		{
			main->raycast.tex.y = (int)main->raycast.tex_pos & \
			(img->height - 1);
			main->raycast.tex_pos += main->raycast.f_step;
			if (main->raycast.side == 1)
				my_mlx_pixel_put(&main->img, new_x, j, \
				new_addr[main->raycast.tex.y * \
				img->height + main->raycast.tex.x]);
			else
				my_mlx_pixel_put(&main->img, new_x, j, \
				new_addr[main->raycast.tex.y * \
				img->height + main->raycast.tex.x]);
		}
		else if (j < SCREEN_HEIGHT / 2 * main->up_down)
			my_mlx_pixel_put(&main->img, new_x, j, \
			colour_to_nb(main->gm.c_rgb.x, main->gm.c_rgb.y, main->gm.c_rgb.z));
		else
			my_mlx_pixel_put(&main->img, new_x, j, \
			colour_to_nb(main->gm.f_rgb.x, main->gm.f_rgb.y, main->gm.f_rgb.z));
	}
}

void	init_dda(t_main *main, int x)
{
	main->raycast.camera_x = 2 * x / (double)(SCREEN_HEIGHT) - 1;
	main->raycast.ray_dir.x = main->delta_x + 0.2 + main->plane_x * \
	main->raycast.camera_x;
	main->raycast.ray_dir.y = main->delta_y + 0.2 + main->plane_y * \
	main->raycast.camera_x;
	main->raycast.map.x = (int)(main->x);
	main->raycast.map.y = (int)(main->y);
	if (main->raycast.ray_dir.x == 0.0)
		main->raycast.delta_dist.x = 1e30;
	else
		main->raycast.delta_dist.x = fabs(1 / main->raycast.ray_dir.x);
	if (main->raycast.ray_dir.y == 0.0)
		main->raycast.delta_dist.y = 1e30;
	else
		main->raycast.delta_dist.y = fabs(1 / main->raycast.ray_dir.y);
	main->raycast.hit = 0;
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
