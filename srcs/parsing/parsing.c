/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/18 01:57:58 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_start_parsing(t_data *db)
{
	if (db->ps.ac < 2)
		ft_err_display(ERR_NOARG);
	else if (db->ps.ac > 2)
		ft_err_display(ERR_TOOMANYARG);
	else
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
