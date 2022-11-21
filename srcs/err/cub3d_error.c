/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/21 16:59:37 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_err_display_textures(int errtype);

void	ft_err_display(int errtype)
{
	if (errtype != ERR_NONE)
		ft_putstr_fd("Error\n", 2);
	if (errtype == ERR_NOARG)
		ft_putstr_fd("NO ARG : \
Please fill in the path of a map .cub extension\n", 2);
	else if (errtype == ERR_TOOMANYARG)
		ft_putstr_fd("Please enter just one argument : the path map.\n", 2);
	else if (errtype == ERR_WALL)
		ft_putstr_fd("The map must be completely closed with walls\n", 2);
	else if (errtype == ERR_PLAYER_MISSING)
		ft_putstr_fd("Position of the player is missing\n", 2);
	else if (errtype == ERR_PLAYER_BAD_POS)
		ft_putstr_fd("Player must be placed between the closed walls\n", 2);
	else if (errtype == ERR_ARG_FORBIDEN)
		ft_putstr_fd("Forbidden arguments in the map\n", 2);
	else if (errtype == ERR_PARAM_NO_C)
		ft_putstr_fd("Please add C parameter in map(celling color RGB)\n", 2);
	else if (errtype == ERR_PARAM_NO_F)
		ft_putstr_fd("Please add F parameter in map(floor color RGB)\n", 2);
	else if (errtype == ERR_TXTMISSING_EA)
		ft_putstr_fd("Please add F parameter in map(floor color RGB)\n", 2);
	else
		ft_err_display_textures(errtype);
	if (errtype != ERR_NONE)
		exit (EXIT_FAILURE);
}

static int	ft_err_display_textures(int errtype)
{
	if (errtype == ERR_TXTMISSING_EA)
		return (ft_putstr_fd("Missing texture : EAST.\n", 2));
	else if (errtype == ERR_TXTMISSING_WE)
		return (ft_putstr_fd("Missing texture : WEST.\n", 2));
	else if (errtype == ERR_TXTMISSING_SO)
		return (ft_putstr_fd("Missing texture : SOUTH.\n", 2));
	else if (errtype == ERR_TXTMISSING_NO)
		return (ft_putstr_fd("Missing texture : NORTH.\n", 2));
	else if (errtype == ERR_BADEXTENSION)
		ft_putstr_fd("The map must be in \"*.cub\" format\n", 2);
	else if (errtype == ERR_PARAM_UNKNOWN)
		ft_putstr_fd("Unknown parameter detected\n", 2);
	else if (errtype == ERR_PARAM_INVALID)
		ft_putstr_fd("Invalid value for one of the parameters\n", 2);
	else if (errtype == ERR_PARAM_TO_HIGH)
		ft_putstr_fd("Invalid value : range for RGB is [0-255]\n", 2);
	return (EXIT_SUCCESS);
}
