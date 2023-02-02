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
	if (keycode == KEY_UP)
		main->move_tab[6] = 1;
	if (keycode == KEY_DOWN)
		main->move_tab[7] = 1;
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

// t_vector2_f dda(t_main *game, t_vector2_f dest)
// {
// 	static const t_vector2_d origin = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
// 	t_vector2_d map = origin; // Position used to check tab value
// 	t_vector2_f dir = {dest.x - origin.x, dest.y - origin.y};

// 	t_vector2_f side_dist; // Origin point offset to the nearest int positon
// 	t_vector2_f delta_dist; // Length of the hyptenuse

// 	delta_dist.x = (dir.x == 0) ? 1e30 : fabs(1.0f / dir.x); // 1e30 is a large value
// 	delta_dist.y = (dir.y == 0) ? 1e30 : fabs(1.0f / dir.y);

// 	t_vector2_f step;
// 	if (dir.x < 0)
// 	{
// 		step.x = -1; // Calculating X step (depending on the direction)
// 		side_dist.x = (origin.x - map.x) * delta_dist.x; // Calculating X gap to the nearest integer coordinate
// 	}
// 	else
// 	{
// 		step.x = 1;
// 		side_dist.x = (map.x + 1.0f - origin.x) * delta_dist.x;
// 	}

// 	if (dir.y < 0)
// 	{
// 		step.y = -1; // Calculating Y step (depending on the direction)
// 		side_dist.y = (origin.y - map.y) * delta_dist.y; // Calculating Y gap to the nearest integer coordinate
// 	}
// 	else
// 	{
// 		step.y = 1;
// 		side_dist.y = (map.y + 1.0f - origin.y) * delta_dist.y;
// 	}
// 	while (1)
// 	{
// 		if (side_dist.x < side_dist.y)
// 		{
// 			side_dist.x += delta_dist.x;
// 			map.x += step.x;
// 		}
// 		else
// 		{
// 			side_dist.y += delta_dist.y;
// 			map.y += step.y;
// 		}

// 		// Converting pixel coordinates to tab coordinates
// 		t_vector2_d cell = {
// 			map.x / data->cell_size,
// 			map.y / data->cell_size
// 		};

// 		if (data->tab[cell.y][cell.x] == 1) // Is a wall
// 		{
// 			return (vector_d_to_f(map));
// 		}
// 	}
// }

void	put_pixel_from_ray(t_main *main, t_data *img, int posX, int posY, \
int side, int draw_start, int draw_end, int rayDirX, int rayDirY, int perpWallDist, int x, int line_height)
{
	int j = 0;
	int new_x = SCREEN_WIDTH - x;
	char *dst;
	int *new_addr = (int *)img->addr;

	float	wallx;

	if (side == 0)
		wallx = main->y + perpWallDist * rayDirY;
	else
		wallx = main->x + perpWallDist * rayDirX;
	wallx -= floorf(wallx);
	int texX = (int)(wallx * img->height);
	if (side == 0 && rayDirX > 0)
		texX = img->width - texX - 1;
	if (side == 1 && rayDirY < 0)
		texX = img->width - texX - 1;
	float step = 1.0 * img->height / line_height;
	float texPos = (draw_start - SCREEN_HEIGHT / 2 + line_height / 2) * step;
	int texY = (int)texPos & (img->height - 1);

	//printf(" dst height : %f /----/  x : %d y : %d \n", texPos, 1, (j-draw_start));
	while (j != SCREEN_HEIGHT)
	{
		j++;
		if (j >= draw_start && j <= draw_end)
		{
			texY = (int)texPos & (img->height - 1);
			texPos += step;
			//dst = img->addr + ((j-draw_start) * img->line_length + 1 * img->bpp);
			if (side == 1)
				my_mlx_pixel_put(&main->img, new_x, j, new_addr[texY * img->height + texX]);
			else
				my_mlx_pixel_put(&main->img, new_x, j, new_addr[texY * img->height + texX]);
		}
		else if (j > SCREEN_HEIGHT / 2)
			my_mlx_pixel_put(&main->img, new_x, j, colour_to_nb(main->gm.c_rgb.x, main->gm.c_rgb.y, main->gm.c_rgb.z));
		else
			my_mlx_pixel_put(&main->img, new_x, j, colour_to_nb(main->gm.f_rgb.x, main->gm.f_rgb.y, main->gm.f_rgb.z));
	}
}

void	render(t_main *main)
{
	int x;

	x = 0;
	draw_minimap(main); // A OPTI
	while (x < SCREEN_WIDTH)
	{
		// calculate ray position and direction
		double cameraX = 2 * x / (double)(SCREEN_HEIGHT) - 1; // x-coordinate in camera space
		double rayDirX = main->delta_x + main->plane_x * cameraX; // 0 = planeX
		double rayDirY = main->delta_y + main->plane_y * cameraX; // FOV HORIZONTAL = PLANEY
		//printf("%sRayDir X et Y : %f, %f //%s player Angle : %f\n", COLOR_GREEN, rayDirX, rayDirY, COLOR_CYAN, main->player_angle);

		// which box of the map we're in
		int mapX = (int)(main->x);
		int mapY = (int)(main->y);

		// length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		// length of ray from one x or y-side to next x or y-side
		double deltaDistX = (rayDirX == 0.0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0.0) ? 1e30 : fabs(1 / rayDirY);
		double perpWallDist;

		// what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; // was there a wall hit?
		int side;	 // was a NS or a EW wall hit?

		// calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (main->x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - main->x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (main->y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - main->y) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			my_mlx_pixel_put(&main->mini_map, (float)(mapX * MAP_CELL_SIZE / CELL_SIZE), (float)(mapY * MAP_CELL_SIZE / CELL_SIZE), 0xFFFFFF);
			if (main->gm.map[mapY / CELL_SIZE][mapX / CELL_SIZE] != '0')
			{
				hit = 1;
			}
			else if (mapY / CELL_SIZE > main->ps.map.maxh - 1 || mapX <= 0 || mapX / CELL_SIZE > main->ps.map.maxw - 1 || mapY <= 0)
			{
				printf("%d,%d\n", mapX, mapY);
				side = -1;
				break;
			}
		}
		double wall_hit_dist;
		if (side == 0)
			wall_hit_dist = sideDistX - deltaDistX;
		else if (side == 1)
			wall_hit_dist = sideDistY - deltaDistY;
		else
			break;
		int line_height = (int)(SCREEN_HEIGHT / (wall_hit_dist * 0.017));
		int draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		int draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_end >= SCREEN_HEIGHT)
			draw_end = SCREEN_HEIGHT - 1;
		//i fking forgot perpWallDist i'm dumb
		if (side == 0)
			perpWallDist = (main->ps.map.maxw * CELL_SIZE - main->x +
								   (1 - stepX) / 2) /
								  rayDirX;
		else
			perpWallDist = (main->ps.map.maxh * CELL_SIZE - main->y +
								   (1 - stepY) / 2) /
								  rayDirY;
		if (perpWallDist == 0)
			perpWallDist = 0.1;
		//end of dumb section
		if (side == 0)
			put_pixel_from_ray(main, &main->gm.img_no, main->x, main->y, side, draw_start, draw_end, rayDirX, rayDirY, perpWallDist, x, line_height);
		else if (side == 1)
			put_pixel_from_ray(main, &main->gm.img_we, main->x, main->y, side, draw_start, draw_end, rayDirX, rayDirY, perpWallDist, x, line_height);
		x++;
		// printf("%sSide dist : %lf / %f\n %sDelta : %f / %f\n",COLOR_GREEN, side_dist_x, side_dist_y, COLOR_CYAN, deltaDistX, deltaDistY);
	}
	mlx_put_image_to_window(main->mlx, main->mlx_win, main->img.img, 0, 0);
	mlx_put_image_to_window(main->mlx, main->mlx_win, main->gm.img_no.img, 0, 0);
	mlx_put_image_to_window(main->mlx, main->mlx_win, main->gm.img_we.img, main->gm.img_no.width, 0);
	//mlx_put_image_to_window(main->mlx, main->mlx_win, main->mini_map.img, 0, 0);
}

int	render_next_frame(t_main *main)
{
	update_velocity(main);
	move_player(main);
	//mlx_put_image_to_window(main->mlx, main->mlx_win, main->background.img, 0, 0);
	// dbg_display_velocity(main); //TODO:TODO:TODO:TODO:TODO:FIXME:FIXME:FIXME:FIXME:
	// mlx_put_image_to_window(main->mlx, main->mlx_win, main->img.img, 0, 0);
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
	game->plane_y = FOV_HORIZONTAL;
	//game->mlx_win = mlx_new_window(game->mlx, game->ps.map.maxw * MAP_CELL_SIZE, game->ps.map.maxh * MAP_CELL_SIZE, "cub3D");
	game->mini_map.img = mlx_new_image(game->mlx, game->ps.map.maxw * MAP_CELL_SIZE, (game->ps.map.maxh - 1) * MAP_CELL_SIZE);

	game->mlx_win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	//game->mini_map.img = mlx_new_image(game->mlx, coef * game->ps.map.maxw, coef * game->ps.map.maxh);
	game->mini_map.addr = mlx_get_data_addr(game->mini_map.img, \
	&game->mini_map.bpp, &game->mini_map.line_length, &game->mini_map.end);
	game->mini_map.bpp /= 8; // SECURITER TODO
	//mlx_put_image_to_window(game->mlx, game->mlx_win, game->background.img, 0, 0);
	draw_minimap(game);
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp, \
	&game->img.line_length, &game->img.end);
	game->img.bpp /= 8; // SECURITER TODO

	game->delta_x = cos(game->player_angle) * 5;
	game->delta_y = sin(game->player_angle) * 5;
	game->delta_x = -1; game->delta_y = 0;
	game->plane_x = 0; game->plane_y = 0.66;
	game->up_down = 1;
}
