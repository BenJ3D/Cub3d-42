/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/24 17:35:48 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	dbg_display_all_parameter_value(t_main *main)
{
	printf("C RGB = %i,%i,%i\n", main->gm.c_rgb.x,main->gm.c_rgb.y, main->gm.c_rgb.z);
	printf("F RGB = %i,%i,%i\n", main->gm.f_rgb.x,main->gm.f_rgb.y,main->gm.f_rgb.z);
	printf("NO path = %s\n", main->ps.txtpath.pathNO);
	printf("SO path = %s\n", main->ps.txtpath.pathSO);
	printf("EA path = %s\n", main->ps.txtpath.pathEA);
	printf("WE path = %s\n", main->ps.txtpath.pathWE);
	printf("map L x h = %i char x %i lines\n", main->ps.map.maxh, main->ps.map.maxw);
}