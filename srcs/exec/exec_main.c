/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:23:05 by abucia            #+#    #+#             */
/*   Updated: 2022/12/09 18:51:18 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int keycode, t_main *main)
{
	// printf("Key pressed : %d\n", keycode);
	
	if (keycode == ESC)
		ft_free_all_and_exit(main);
	if (keycode <= 200)
		main->keyboard[keycode] = 1;
	if (keycode < 200)
		main->keyboard[keycode % 200] = 1;
	return (0);
}

int	key_release(int keycode, t_main *main)
{
	// printf("Key release : %d\n", keycode);
	if (keycode == ESC)
		ft_free_all_and_exit(main);
	if (keycode < 200)
		main->keyboard[keycode % 200] = 0;

	return (0);
}

int	stop_mlx(int keycode, t_main *main)
{
	printf("%p\n", main);
	// ft_free_all_and_exit(main); // Sanitize
	exit(0);
	return (0);
}

void	draw_minimap(t_main *game, int coef)
{
	int	w;
	int	h;

	h = coef * game->ps.map.maxh - coef*2;
	while (--h != coef)
	{
		w = coef * game->ps.map.maxw - coef;
		while (--w != coef)
		{
			//printf("%d=%d %d=%d %d\n", w, 4 * game->ps.map.maxw, h, 4 * game->ps.map.maxh, coef);
			if (game->gm.map[h / coef][w / coef] == '1')
				my_mlx_pixel_put(&game->mini_map, w, h, 0x6600FF);
			else if (game->gm.map[h / coef][w / coef] == '0')
				my_mlx_pixel_put(&game->mini_map, w, h, 0x330000);
			else
				my_mlx_pixel_put(&game->mini_map, w, h, 0xFF3300);
		}
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->mini_map.img, 0, 0);
}

// int	render_next_frame(t_main *main)
// {
// 	draw_map(main);
// 	update_velocity(main);
// 	dbg_display_velocity(main); //TODO:TODO:TODO:TODO:TODO:FIXME:FIXME:FIXME:FIXME:
// 	mlx_put_image_to_window(main->mlx, main->mlx_win, main->img.img, 0, 0);
// }

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

void	shoot_ray(t_main *main)
{
	int i;
	while (/* condition */)
	{
		/* code */
	}
	
}

void	exec_main(t_main *game)
{
	int		coef;

	coef = (SCREEN_HEIGHT * SCREEN_WIDTH * COEF_MINIMAP);
	game->mlx_win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	game->mini_map.img = mlx_new_image(game->mlx, coef * game->ps.map.maxw, coef * game->ps.map.maxh);
	game->mini_map.addr = mlx_get_data_addr(game->mini_map.img, \
	&game->mini_map.bpp, &game->mini_map.line_length, &game->mini_map.end);
	game->mini_map.bpp /= 8; // SECURITER TODO
	draw_minimap(game, coef);
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp, \
	&game->img.line_length, &game->img.end);
	game->img.bpp /= 8; // SECURITER TODO

	int i;
	i = 0;

	game->delta_x = cos(game->player_angle) * 5;
	game->delta_y = sin(game->player_angle) * 5;
	game->raycast = init_raycast();
	while (i < SCREEN_WIDTH)
	{
		
		i++;
	}
	
}