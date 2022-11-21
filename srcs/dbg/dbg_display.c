/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/21 19:44:01 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	dbg_display_all_parameter_value(t_main *main)
{
	printf("C RGB = %i,%i,%i\n", main->gm.ceiling.x,main->gm.ceiling.y, main->gm.ceiling.z);
	printf("F RGB = %i,%i,%i\n", main->gm.floor.x,main->gm.floor.y,main->gm.floor.z);
	printf("NO path = %s\nSO path = %s\nWE path = %s\nEA path = %s\n", \
					main->gm.pathNO, main->gm.pathSO, main->gm.pathWE, main->gm.pathEA);
}