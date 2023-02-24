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
	if (main->cast.ray_dir.x < 0)
	{
		main->cast.step.x = -1;
		main->cast.side_dist.x = (main->x - main->cast.map.x) \
		* main->cast.delta_dist.x;
	}
	else
	{
		main->cast.step.x = 1;
		main->cast.side_dist.x = (main->cast.map.x + 1.0 - main->x) \
		* main->cast.delta_dist.x;
	}
	if (main->cast.ray_dir.y < 0)
	{
		main->cast.step.y = -1;
		main->cast.side_dist.y = (main->y - main->cast.map.y) \
		* main->cast.delta_dist.y;
	}
	else
	{
		main->cast.step.y = 1;
		main->cast.side_dist.y = (main->cast.map.y + 1.0 - main->y) \
		* main->cast.delta_dist.y;
	}
}

static void	manage_animation(t_main *main)
{
	if (main->cast.a_time == 6)
	{
		if (++main->cast.time_h >= ANIMATION_TIME)
		{
			main->cast.a_time = 0;
			main->cast.time_h = 0;
		}
	}
	else
		main->cast.a_time++;
}

void	render(t_main *main, double i)
{
	int	x;

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
	while (i < 4)
	{
		i += 0.2;
		my_mlx_pixel_put(&main->img, (SCREEN_WIDTH - ((SCREEN_WIDTH / 6) >> 1) \
		- 24 + main->delta_x * i), (((SCREEN_WIDTH / 6) >> 1) \
		+ 24 + main->delta_y * i), 0x00F53F);
	}
	mlx_put_image_to_window(main->mlx, main->mlx_win, main->img.img, 0, 0);
	manage_animation(main);
}

void	mouse_move(t_main *main)
{
	t_i_vector	mouse;

	mlx_mouse_get_pos(main->mlx, main->mlx_win, &mouse.x, &mouse.y);
	if (mouse.x < (SCREEN_WIDTH >> 2))
		rotate_left(main);
	else if (mouse.x > SCREEN_WIDTH - (SCREEN_WIDTH >> 2))
		rotate_right(main);
	if (mouse.y < (SCREEN_HEIGHT >> 2))
		look_up(main);
	else if (mouse.y > SCREEN_HEIGHT - (SCREEN_HEIGHT >> 2))
		look_down(main);
	render(main, 0);
}

int	render_next_frame(t_main *main)
{
	if (BOOL == 1)
		mouse_move(main);
	update_velocity(main);
	move_player(main);
	return (1);
}
