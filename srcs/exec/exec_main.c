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

int	key_press(int keycode, t_main *main)
{
	if (keycode == ESC)
		ft_free_all_and_exit(main);
	if (keycode == KEY_W)
		main->move_tab[0] = 1;
	if (keycode == KEY_S)
		main->move_tab[1] = 1;
	if (keycode == KEY_A)
		main->move_tab[2] = 1;
	if (keycode == KEY_D)
		main->move_tab[3] = 1;
	if (keycode == KEY_RIGHT)
		main->move_tab[4] = 1;
	if (keycode == KEY_LEFT)
		main->move_tab[5] = 1;
	if (keycode == KEY_UP)
		main->move_tab[6] = 1;
	if (keycode == KEY_DOWN)
		main->move_tab[7] = 1;
	if (keycode == KEY_PLUS)
		main->move_tab[8] = 1;
	if (keycode == KEY_MINUS)
		main->move_tab[9] = 1;
	return (0);
}

int	key_release(int keycode, t_main *main)
{
	if (keycode == ESC)
		ft_free_all_and_exit(main);
	if (keycode == KEY_W)
		main->move_tab[0] = 0;
	if (keycode == KEY_S)
		main->move_tab[1] = 0;
	if (keycode == KEY_A)
		main->move_tab[2] = 0;
	if (keycode == KEY_D)
		main->move_tab[3] = 0;
	if (keycode == KEY_RIGHT)
		main->move_tab[4] = 0;
	if (keycode == KEY_LEFT)
		main->move_tab[5] = 0;
	if (keycode == KEY_UP)
		main->move_tab[6] = 0;
	if (keycode == KEY_DOWN)
		main->move_tab[7] = 0;
	if (keycode == KEY_PLUS)
		main->move_tab[8] = 0;
	if (keycode == KEY_MINUS)
		main->move_tab[9] = 0;
	return (0);
}

int	stop_mlx(int keycode, t_main *main)
{
	(void)keycode;
	(void)main;
	exit(0);
	return (0);
}

int	colour_to_nb(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + (b));
}

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
		return(-1);
	vect->x *= main->ps.map.maxw * MAP_CELL_SIZE;
	vect->y = map.x % (main->ps.map.maxw * MAP_CELL_SIZE);
	if (vect->y < 0 || map.x > main->ps.map.maxw * MAP_CELL_SIZE)
		return(-1);
	return (1);
}

int	translucid_minimap(int color)
{
	if (color == colour_to_nb(17, 17, 17))
		return (0);
	return (1);
}

void	put_minimap(t_main *main)
{
	int			*new_addr;
	t_i_vector	img;
	t_i_vector	map;
	t_i_vector	render;

	new_addr = (int *)main->mini_map.addr;
	if (SCREEN_WIDTH / 6 > SCREEN_HEIGHT / 2)
		return ;
	img.x = SCREEN_WIDTH - (SCREEN_WIDTH / 6);
	map.x = main->x * MAP_CELL_SIZE / CELL_SIZE - (SCREEN_WIDTH / 6) / 2;
	while (img.x < SCREEN_WIDTH)
	{
		img.y = -1;
		map.y = main->y * MAP_CELL_SIZE / CELL_SIZE - (SCREEN_WIDTH / 6) / 2;
		while (++img.y < SCREEN_WIDTH / 6)
		{
			if (++map.y < SCREEN_WIDTH && calc_mini_pix(&render, map, main) == 1)
			{
				if (translucid_minimap(new_addr[render.x + render.y]))
				{
					if ((int)main->ray.addr[(map.y + (SCREEN_WIDTH / 6) / 2) * main->ray.line_length + (map.x + (SCREEN_WIDTH / 6) / 2) * main->ray.bpp] == 0xFFFFFF)
						my_mlx_pixel_put(&main->img, img.x - 24, img.y + 24, \
						0xFFFFFF);
					else
						my_mlx_pixel_put(&main->img, img.x - 24, img.y + 24, \
						new_addr[render.x + render.y]);
				}
			}
			
		}
		img.x++;
		map.x++;
	}
}

void	render(t_main *main)
{
	int	x;

	x = 0;
	reboot_ray(main);
	put_minimap(main);
	while (x < SCREEN_WIDTH)
	{
		init_dda(main, x);
		select_step(main);
		if (raycast_to_wall(main) == EXIT_FAILURE)
			continue ;
		define_start_end(main);
		select_wall_to_put_pixel(main, SCREEN_WIDTH - x);
		x++;
	}
	put_minimap(main);
	mlx_put_image_to_window(main->mlx, main->mlx_win, main->img.img, 0, 0);
}

int	render_next_frame(t_main *main)
{
	update_velocity(main);
	move_player(main);
	return (1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp));
	*(unsigned int *)dst = color;
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
	render(game);
}
