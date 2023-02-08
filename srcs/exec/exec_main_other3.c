/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main_other3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:23:05 by abucia            #+#    #+#             */
/*   Updated: 2023/02/08 01:46:58 by bducrocq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
			if (++map.y < SCREEN_WIDTH && \
			calc_mini_pix(&render, map, main) == 1)
				if (translucid_minimap(new_addr[render.x + render.y]))
					my_mlx_pixel_put(&main->img, img.x - 24, img.y + 24, \
					new_addr[render.x + render.y]);
		img.x++;
		map.x++;
	}
}

void	render(t_main *main, int x, double i)
{
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
	while (i < 3)
	{
		i += 0.2;
		my_mlx_pixel_put(&main->img, (SCREEN_WIDTH - (SCREEN_WIDTH / 6) / 2 \
		- 24 + main->delta_x * i), ((SCREEN_WIDTH / 6) / 2 \
		+ 24 + main->delta_y * i), 0x00F53F);
	}
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
