/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/29 17:42:08 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	dbg_display_all_parameter_value(t_main *main)
{
	printf("C RGB = %i,%i,%i\n", main->gm.c_rgb.x,main->gm.c_rgb.y, main->gm.c_rgb.z);
	printf("F RGB = %i,%i,%i\n", main->gm.f_rgb.x,main->gm.f_rgb.y,main->gm.f_rgb.z);
	printf("NO path = %s\n", main->ps.txtpath.path_no);
	printf("SO path = %s\n", main->ps.txtpath.path_so);
	printf("EA path = %s\n", main->ps.txtpath.path_ea);
	printf("WE path = %s\n", main->ps.txtpath.path_we);
	printf("map L x h = %i char x %i lines\n", main->ps.map.maxh, main->ps.map.maxw);
}

void	dbg_display_velocity(t_main *main)
{
	printf ("\n\n");
	if (main->keyboard[KEY_A] == 1)
		printf ("key press A\n");
	else if (main->keyboard[KEY_D] == 1)
		printf ("key press D\n");
	else if (main->keyboard[KEY_W] == 1)
		printf ("key press W\n");
	else if (main->keyboard[KEY_S] == 1)
		printf ("key press S\n");
	else
		printf ("key press NONE\n");
	printf ("velocity =  %1.2f\n", main->velocity);
}
