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
	if (main->mov_t[0] == 1 || main->mov_t[1] == 1 \
	|| main->mov_t[2] == 1 || main->mov_t[3] == 1)
	{
		if (main->velocity < 0.1f)
			main->velocity = 0.1f;
		if (main->velocity < MAX_VELOCITY)
			main->velocity *= COEF_ACCELERATION;
		else if (main->velocity > MAX_VELOCITY)
			main->velocity = MAX_VELOCITY;
	}
	else
		main->velocity = 0;
}
