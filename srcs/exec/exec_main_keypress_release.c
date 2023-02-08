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
	if (keycode == KEY_D)
		main->move_tab[2] = 1;
	if (keycode == KEY_A)
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
	if (keycode == KEY_DOOR)
		main->move_tab[10] = 1;
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
	if (keycode == KEY_D)
		main->move_tab[2] = 0;
	if (keycode == KEY_A)
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
	if (keycode == KEY_DOOR)
		main->move_tab[10] = 0;
	return (0);
}
