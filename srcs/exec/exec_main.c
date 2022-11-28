/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:23:05 by abucia            #+#    #+#             */
/*   Updated: 2022/11/28 02:44:25 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int keycode, t_main *main)
{
	printf("Key pressed : %d\n", keycode);
	
	if (keycode == ESC)
		ft_free_all_and_exit(main);
	if (keycode < 200)
		main->keyboard[keycode] = 1;

	return (0);
}

int	key_release(int keycode, t_main *main)
{
	if (keycode == ESC)
		ft_free_all_and_exit(main);
	if (keycode < 200)
		main->keyboard[keycode] = 0;

	return (0);
}

int	stop_mlx(int keycode, t_main *main)
{
	// ft_free_all_and_exit(main); // Sanitize
	exit(0);
	return (0);
}

int	draw_cube(t_main *main, int x, int y, int color)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	while(h < main->gm.cell_size)
	{
		while (w < main->gm.cell_size)
		{
			my_mlx_pixel_put(&main->img, x + w, y + h, color);
			w++;
		}
		w = 0;
		h++;
	}
	return (EXIT_SUCCESS);
}
			// my_mlx_pixel_put(&main->img, 100, 100, 0x00FF0000);

int	draw_map(t_main *main)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	// main->gm.cell_size = SCREEN_WIDTH / main->ps.map.maxw;
	main->gm.cell_size = SCREEN_HEIGHT / main->ps.map.maxh;
	// main->gm.cell_size = 8;
	while (main->gm.map[y])
	{
		while (main->gm.map[y][x])
		{
			if ((x * main->gm.cell_size  + main->gm.cell_size) > SCREEN_WIDTH \
			|| (y * main->gm.cell_size + main->gm.cell_size) > SCREEN_HEIGHT)
				break ;
			if (main->gm.map[y][x] == '1')
				draw_cube(main, x * main->gm.cell_size, \
										y * main->gm.cell_size, 0x63EA07);
			if (main->gm.map[y][x] == EMPTY)
				draw_cube(main, x * main->gm.cell_size, \
										y * main->gm.cell_size, 0x9c3d00);
			if (main->gm.map[y][x] == FLOOR)
				draw_cube(main, x * main->gm.cell_size, \
										y * main->gm.cell_size, 0x454545);
			x++;
		}
		x = 0;
		y++;
	}
	
	return (EXIT_SUCCESS);
}

int	render_next_frame(t_main *main)
{
	draw_map(main);
	mlx_put_image_to_window(main->mlx, main->mlx_win, main->img.img, 0, 0);
	mlx_put_image_to_window(main->mlx, main->mlx_win, main->gm.img_ea.img, 1270, 0);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp));
	*(unsigned int*)dst = color;
}

void	exec_main(t_main *game)
{
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp, \
	&game->img.line_length, &game->img.end);
	game->img.bpp /= 8;
	game->mlx_win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
}