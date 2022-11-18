/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/18 01:59:30 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_err_display(int errtype)
{
	if (errtype == ERR_NOARG)
		ft_putstr_fd("NO ARG : \
Please fill in the path of a map .cub extension\n", 2);
	else if (errtype == ERR_TOOMANYARG)
		ft_putstr_fd("TOO MANY ARG : Please enter just one argument.\n", 2);
	else if (errtype == ERR_WALL)
		ft_putstr_fd("The map must be completely closed with walls\n", 2);
	else if (errtype == ERR_MISSPLAYER)
		ft_putstr_fd("Position of the player is missing\n", 2);
	else
		ft_putstr_fd("Error\n", 2);
}
