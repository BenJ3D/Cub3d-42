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
		main->mov_t[0] = 1;
	if (keycode == KEY_S)
		main->mov_t[1] = 1;
	if (keycode == KEY_D)
		main->mov_t[2] = 1;
	if (keycode == KEY_A)
		main->mov_t[3] = 1;
	if (keycode == KEY_RIGHT)
		main->mov_t[4] = 1;
	if (keycode == KEY_LEFT)
		main->mov_t[5] = 1;
	if (keycode == KEY_UP)
		main->mov_t[6] = 1;
	if (keycode == KEY_DOWN)
		main->mov_t[7] = 1;
	if (keycode == KEY_PLUS)
		main->mov_t[8] = 1;
	if (keycode == KEY_MINUS)
		main->mov_t[9] = 1;
	if (keycode == KEY_DOOR)
		main->mov_t[10] = 1;
	return (0);
}

int	key_release(int keycode, t_main *main)
{
	if (keycode == ESC)
		ft_free_all_and_exit(main);
	if (keycode == KEY_W)
		main->mov_t[0] = 0;
	if (keycode == KEY_S)
		main->mov_t[1] = 0;
	if (keycode == KEY_D)
		main->mov_t[2] = 0;
	if (keycode == KEY_A)
		main->mov_t[3] = 0;
	if (keycode == KEY_RIGHT)
		main->mov_t[4] = 0;
	if (keycode == KEY_LEFT)
		main->mov_t[5] = 0;
	if (keycode == KEY_UP)
		main->mov_t[6] = 0;
	if (keycode == KEY_DOWN)
		main->mov_t[7] = 0;
	if (keycode == KEY_PLUS)
		main->mov_t[8] = 0;
	if (keycode == KEY_MINUS)
		main->mov_t[9] = 0;
	if (keycode == KEY_DOOR)
		main->mov_t[10] = 0;
	return (0);
}
