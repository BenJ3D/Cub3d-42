/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main_and_renderframe.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:23:05 by abucia            #+#    #+#             */
/*   Updated: 2023/02/08 02:14:53 by bducrocq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	render(t_main *main, double i)
{
	int x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		init_dda(main, x);
		select_step(main);
		if (raycast_to_wall(main) == EXIT_FAILURE)
			continue ;
		define_start_end(main);
		select_wall_to_put_pixel(main, x);
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

void	mouse_move(t_main *main)
{
	t_i_vector	mouse;

	mlx_mouse_get_pos(main->mlx, main->mlx_win, &mouse.x, &mouse.y);
	if (mouse.x < SCREEN_WIDTH / 4)
		rotate_left(main);
	else if (mouse.x > SCREEN_WIDTH - SCREEN_WIDTH / 4)
		rotate_right(main);
	if (mouse.y < SCREEN_HEIGHT / 4)
		look_up(main);
	else if (mouse.y > SCREEN_HEIGHT - SCREEN_HEIGHT / 4)
		look_down(main);
	render(main, 0);
}

int	render_next_frame(t_main *main)
{
	mouse_move(main);
	update_velocity(main);
	move_player(main);
	return (1);
}
