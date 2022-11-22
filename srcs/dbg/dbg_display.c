/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/22 01:37:10 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	dbg_display_all_parameter_value(t_main *main)
{
	printf("C RGB = %i,%i,%i\n", main->gm.c_rgb.x,main->gm.c_rgb.y, main->gm.c_rgb.z);
	printf("F RGB = %i,%i,%i\n", main->gm.f_rgb.x,main->gm.f_rgb.y,main->gm.f_rgb.z);
	printf("NO path = %s\nSO path = %s\nWE path = %s\nEA path = %s\n", \
					main->gm.pathNO, main->gm.pathSO, main->gm.pathWE, main->gm.pathEA);
}