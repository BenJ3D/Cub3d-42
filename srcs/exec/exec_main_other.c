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

void	reboot_ray(t_main *game)
{
	int	h;
	int	w;

	h = -1;
	while (++h != game->ps.map.maxw * MAP_CELL_SIZE)
	{
		w = -1;
		while (++w != game->ps.map.maxh * MAP_CELL_SIZE)
			my_mlx_pixel_put(&game->ray, h, w, colour_to_nb(17, 17, 17));
	}
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
	main->raycast.ray_dir.x = main->delta_x + main->plane_x * \
	main->raycast.camera_x;
	main->raycast.ray_dir.y = main->delta_y + main->plane_y * \
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
