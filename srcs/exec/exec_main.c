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
	// printf("Key pressed : %d\n", keycode);
	
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
	return (0);
}

int	key_release(int keycode, t_main *main)
{
	// printf("Key release : %d\n", keycode);
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
	return (0);
}

int	stop_mlx(int keycode, t_main *main)
{
	printf("%p\n", main);
	// ft_free_all_and_exit(main); // Sanitize
	exit(0);
	return (0);
}

void	draw_minimap(t_main *game)
{
	int		w;
	int		h;
	double	i;

	h = (game->ps.map.maxh - 1) * MAP_CELL_SIZE;
	while (--h != -1)
	{
		w = (game->ps.map.maxw) * MAP_CELL_SIZE - 1;
		while (--w != -1)
		{
			if (game->gm.map[h / MAP_CELL_SIZE][w / MAP_CELL_SIZE] == '1')
				my_mlx_pixel_put(&game->mini_map, w, h, 0x6600FF);
			else if (game->gm.map[h / MAP_CELL_SIZE][w / MAP_CELL_SIZE] == '0')
				my_mlx_pixel_put(&game->mini_map, w, h, 0x330000);
			else
				my_mlx_pixel_put(&game->mini_map, w, h, 0x124239);
		}
	}
	i = -1;
	while (i < 3)
	{
		my_mlx_pixel_put(&game->mini_map, ((game->x + game->delta_x * i) / \
		CELL_SIZE) * MAP_CELL_SIZE, ((game->y + game->delta_y * i)/ CELL_SIZE) * MAP_CELL_SIZE, \
		0x00F53F);
		i += 0.2;
	}
	//printf("%d,%d\n", game->x / CELL_SIZE, game->y / CELL_SIZE);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->mini_map.img, 0, 0);
}

int	colour_to_nb(int r, int g, int b) {
  return (r << 16) + (g << 8) + (b);
}

void	draw_background(t_main *game)
{
	int h;
	int w;

	h = -1;
	while (++h != SCREEN_HEIGHT)
	{
		w = -1;
		while (++w != SCREEN_WIDTH)
		{
			if (h > SCREEN_HEIGHT / 2)
				my_mlx_pixel_put(&game->background, w, h, colour_to_nb(\
				game->gm.c_rgb.x,game->gm.c_rgb.y,game->gm.c_rgb.z));
			else
				my_mlx_pixel_put(&game->background, w, h, colour_to_nb(\
				game->gm.f_rgb.x,game->gm.f_rgb.y,game->gm.f_rgb.z));
		}
	}
}

// void	check_ray_collision(t_raycast *raycast, t_ray *ray,
// 	t_main *game, int vertical)
// {
// 	ray->traveled_dst = 10000000;
// 	ray->depth_of_field = 0;
// 	raycasting_angle_interpeter(vertical, game, ray, raycast->ray_angle);
// 	while (ray->depth_of_field < (int)((game->ps.map.maxh + game->ps.map.maxw)/1.5))
// 	{
// 		ray->map_x = (int)ray->x >> 6;
// 		ray->map_y = (int)ray->y >> 6;
// 		if (is_in_map_limits(game, ray->map_x, ray->map_y)
// 			&& game->gm.map[ray->map_y][ray->map_x] == '1')
// 		{
// 			ray->depth_of_field = game->game_tab_max_encountred_cell;
// 			ray->traveled_dst = get_traveled_ray_distance(game->x,
// 					game->y, ray->x, ray->y);
// 		}
// 		else
// 		{
// 			ray->x += ray->x_offset;
// 			ray->y += ray->y_offset;
// 			ray->depth_of_field ++;
// 		}
// 	}
// }

// void	raycasting(t_main *game)
// {
// 	int			i;
// 	t_raycast	raycast;

// 	i = 0;
// 	raycast = game->raycast;
// 	raycast.ray_angle = assure_360_deg_angle(game->player_angle + 0.4363325); //DR
// 	while (i < SCREEN_WIDTH)
// 	{
// 		check_ray_collision(raycast, &raycast.vertical_ray, game, 1);
// 		check_ray_collision(raycast, &raycast.horizontal_ray, game, 0);
// 		if (raycast.horizontal_ray.traveled_dst
// 			<= raycast.vertical_ray.traveled_dst)
// 		{
// 			draw_walls(game, raycast, &raycast.horizontal_ray, i);
// 		}
// 		else
// 		{
// 			draw_walls(game, raycast, &raycast.vertical_ray, i);
// 		}
// 		raycast.ray_angle = assure_360_deg_angle(raycast.ray_angle - 0.872665
// 				/ SCREEN_WIDTH);
// 		i++;
// 	}
// }

int	render_next_frame(t_main *main)
{
	int x;
	double cam_x;
	double ray_dir_x;
	double ray_dir_y;

	x = 0;
	update_velocity(main);
	move_player(main);
	mlx_put_image_to_window(main->mlx, main->mlx_win, main->background.img, 0, 0);
	draw_minimap(main); // A OPTI
	int side;
	main->plane_y = FOV_HORIZONTAL;
	while (x < SCREEN_WIDTH)
	{
		 //calculate ray position and direction
      double cameraX = 2*x/(double)(SCREEN_WIDTH)-1; //x-coordinate in camera space
      double rayDirX = main->delta_x + 0 * cameraX; // 0 = planeX
      double rayDirY = main->delta_y + FOV_HORIZONTAL * cameraX; // FOV HORIZONTAL = PLANEY

      //which box of the map we're in
      int map_x = (int)(main->x + 0.5);
      int map_y = (int)(main->y + 0.5);

      //length of ray from current position to next x or y-side
      double side_dist_x;
      double side_dist_y;

      //length of ray from one x or y-side to next x or y-side
      double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
      double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int step_x;
      int step_y;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?

      //calculate step and initial sideDist
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (main->x - map_x) * deltaDistX;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - main->x) * deltaDistX;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (main->y - map_y) * deltaDistY;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - main->y) * deltaDistY;
		}
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += deltaDistX;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += deltaDistY;
				map_y += step_y;
				side = 1;
			}
			if (main->gm.map[map_y / CELL_SIZE][map_x / CELL_SIZE] != '0')
				{
					hit = 1;
				}
			else if (map_x / CELL_SIZE > main->ps.map.maxh - 2 || map_x < 0 || map_y / CELL_SIZE > main->ps.map.maxw - 1 || map_y < 0)
			{
				side = -1;
				break;
			}
			my_mlx_pixel_put(&main->mini_map, (float)(map_x*MAP_CELL_SIZE / CELL_SIZE), (float)(map_y*MAP_CELL_SIZE / CELL_SIZE), 0xFFAA99);
		}
		double wall_hit_dist;
		if (side == 0)
			wall_hit_dist = side_dist_x - deltaDistX;
		else if (side == 1)
			wall_hit_dist = side_dist_y - deltaDistY;
		else
			continue ;
		int line_height = (int)(SCREEN_HEIGHT / wall_hit_dist);
		int draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		int draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_end >= SCREEN_HEIGHT)
			draw_end = SCREEN_HEIGHT - 1;
		x++;
		//printf("%sSide dist : %lf / %f\n %sDelta : %f / %f\n",COLOR_GREEN, side_dist_x, side_dist_y, COLOR_CYAN, deltaDistX, deltaDistY);
	}
	
	//dbg_display_velocity(main); //TODO:TODO:TODO:TODO:TODO:FIXME:FIXME:FIXME:FIXME:
	//mlx_put_image_to_window(main->mlx, main->mlx_win, main->img.img, 0, 0);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp));
	*(unsigned int*)dst = color;
}

t_raycast	init_raycast(void)
{
	t_raycast	raycast;

	raycast.ray_count = FOV_HORIZONTAL;
	return (raycast);
}

// void	shoot_ray(t_main *main)
// {
// 	int i;
// 	while (/* condition */)
// 	{
// 		/* code */
// 	}
	
// }

void	exec_main(t_main *game)
{
	game->x = game->gm.playstart.x * CELL_SIZE + 32;
	game->y = game->gm.playstart.y * CELL_SIZE + 32;
	printf("%d,%d\n", game->gm.playstart.x, game->gm.playstart.y);
	game->plane_x = 0;
	game->plane_y = 0.66;
	//game->mlx_win = mlx_new_window(game->mlx, game->ps.map.maxw * MAP_CELL_SIZE, game->ps.map.maxh * MAP_CELL_SIZE, "cub3D");
	game->mini_map.img = mlx_new_image(game->mlx, game->ps.map.maxw * MAP_CELL_SIZE, (game->ps.map.maxh - 1) * MAP_CELL_SIZE);

	game->background.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->background.addr = mlx_get_data_addr(game->background.img, &game->background.bpp, \
	&game->background.line_length, &game->background.end);
	game->background.bpp /= 8; // SECURITER TODO

	game->mlx_win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	//game->mini_map.img = mlx_new_image(game->mlx, coef * game->ps.map.maxw, coef * game->ps.map.maxh);
	game->mini_map.addr = mlx_get_data_addr(game->mini_map.img, \
	&game->mini_map.bpp, &game->mini_map.line_length, &game->mini_map.end);
	game->mini_map.bpp /= 8; // SECURITER TODO
	draw_background(game);
	//mlx_put_image_to_window(game->mlx, game->mlx_win, game->background.img, 0, 0);
	draw_minimap(game);
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp, \
	&game->img.line_length, &game->img.end);
	game->img.bpp /= 8; // SECURITER TODO

	int i;
	i = 0;

	game->delta_x = cos(game->player_angle) * 5;
	game->delta_y = sin(game->player_angle) * 5;
	// game->raycast = init_raycast();
	// game->fov =  MY_PI * (FOV_HORIZONTAL / 180.);
	// while (i < SCREEN_WIDTH)
	// {
	// 	i++;
	// }
}
