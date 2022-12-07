/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   velocity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:26:23 by abucia            #+#    #+#             */
/*   Updated: 2022/11/29 17:49:26 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	update_velocity(t_main *main)
{
	if (main->keyboard[KEY_W] == 1 || main->keyboard[KEY_S] == 1 \
	|| main->keyboard[KEY_A] == 1 || main->keyboard[KEY_D] == 1)
	{
		if (main->velocity < 0.1)
			main->velocity = 0.1;
		if (main->velocity < MAX_VELOCITY)
			main->velocity *= COEF_ACCELERATION;
		else if (main->velocity > MAX_VELOCITY)
			main->velocity = MAX_VELOCITY;
	}
	else
	{
		if (main->velocity > 0.1)
			main->velocity *= COEF_DECELERATION;
		if (main->velocity < 0.1)
			main->velocity = 0;
	}
}