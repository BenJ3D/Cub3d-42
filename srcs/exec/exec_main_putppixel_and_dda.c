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

void	shiny_texture(t_main *main, t_data *img, int new_x, int j)
{
	int	*new_addr;
	int	*shiny_addr;

	if (BOOL == 1 && main->cast.a_time < 6)
	{
		shiny_addr = (int *)main->gm.img_reflet[main->cast.a_time].addr;
		main->cast.s_tex.y = (int)main->cast.s_tex_pos & \
		(main->gm.img_reflet[main->cast.a_time].height - 1);
		main->cast.s_tex_pos += main->cast.s_f_step;
	}
	new_addr = (int *)img->addr;
	main->cast.tex.y = (int)main->cast.tex_pos & (img->height - 1);
	main->cast.tex_pos += main->cast.f_step;
	if (main->cast.a_time < 6 && BOOL == 1 && shiny_addr[main->cast.s_tex.y * \
	main->gm.img_reflet[main->cast.a_time].height + main->cast.s_tex.x] > 1000)
		my_mlx_pixel_put(&main->img, new_x, j, 0xFFFFFF);
	else if (main->cast.side == 1)
		my_mlx_pixel_put(&main->img, new_x, j, \
		new_addr[main->cast.tex.y * img->height + main->cast.tex.x]);
	else
		my_mlx_pixel_put(&main->img, new_x, j, \
		new_addr[main->cast.tex.y * img->height + main->cast.tex.x]);
}

void	put_pixel_from_ray(t_main *main, t_data *img, int new_x, int j)
{
	init_put_pixel_ray(main, img, &main->gm.img_reflet[main->cast.a_time]);
	while (++j < SCREEN_HEIGHT)
	{
		if (j >= main->cast.draw_start && j <= main->cast.draw_end)
			shiny_texture(main, img, new_x, j);
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
	main->cast.camera_x = 2 * x / (double)(SCREEN_HEIGHT) - 1;
	main->cast.ray_dir.x = main->delta_x + main->plane_x * \
	main->cast.camera_x;
	main->cast.ray_dir.y = main->delta_y + main->plane_y * \
	main->cast.camera_x;
	main->cast.map.x = (int)(main->x);
	main->cast.map.y = (int)(main->y);
	if (main->cast.ray_dir.x == 0.0)
		main->cast.delta_dist.x = 1e30;
	else
		main->cast.delta_dist.x = fabs(1 / main->cast.ray_dir.x);
	if (main->cast.ray_dir.y == 0.0)
		main->cast.delta_dist.y = 1e30;
	else
		main->cast.delta_dist.y = fabs(1 / main->cast.ray_dir.y);
	main->cast.hit = 0;
}

void	define_start_end(t_main *main)
{
	main->cast.line_height = (int)(SCREEN_HEIGHT / \
	(main->cast.wall_hit_dist / (CELL_SIZE - 100.0f * main->fov + 50)));
	main->cast.draw_start = -main->cast.line_height / 2 + \
	SCREEN_HEIGHT / 2 * main->up_down + 1;
	if (main->cast.draw_start < 0)
		main->cast.draw_start = 0;
	main->cast.draw_end = main->cast.line_height / 2 + \
	SCREEN_HEIGHT / 2 * main->up_down - 1;
	if (main->cast.draw_end >= SCREEN_HEIGHT)
		main->cast.draw_end = SCREEN_HEIGHT - 1;
}

void	select_wall_to_put_pixel(t_main *main, int x)
{
	if (main->cast.side == 0)
		main->cast.perp_wall_dist = (main->cast.map.x - main->x + \
		(1 - main->cast.step.x) / 2) / main->cast.ray_dir.x;
	else
		main->cast.perp_wall_dist = (main->cast.map.y - main->y + \
		(1 - main->cast.step.y) / 2) / main->cast.ray_dir.y;
	if (main->cast.perp_wall_dist == 0)
		main->cast.perp_wall_dist = 0.1;
	if (main->gm.map[main->cast.map.y / CELL_SIZE] \
	[main->cast.map.x / CELL_SIZE] == 'P')
		put_pixel_from_ray(main, &main->gm.img_door, x, -1);
	else if (main->cast.side == 1 && main->cast.map.y < main->y)
		put_pixel_from_ray(main, &main->gm.img_no, x, -1);
	else if (main->cast.side == 1)
		put_pixel_from_ray(main, &main->gm.img_so, x, -1);
	else if (main->cast.map.x > main->x && main->cast.side == 0)
		put_pixel_from_ray(main, &main->gm.img_we, x, -1);
	else
		put_pixel_from_ray(main, &main->gm.img_ea, x, -1);
}
