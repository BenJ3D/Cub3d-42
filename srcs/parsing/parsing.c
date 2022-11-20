/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/20 02:58:25 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_start_parsing(t_data *db)
{
	if (db->ps.ac < 2)
		ft_err_display(ERR_NOARG);
	else if (db->ps.ac > 2)
		ft_err_display(ERR_TOOMANYARG);
	else if (ft_pars_check_type_file(db->ps.av[1], CUBEXT))
		ft_err_display(ERR_BADEXTENSION);
	db->ps.map_path = ft_strdup(db->ps.av[1]);
	db->ps.map_fd = ft_pars_openfile(db->ps.map_path);
	if (db->ps.map_fd < 0)
		exit (errno);
	else
		ft_set_parameters_with_file_header(db);
	return (EXIT_SUCCESS);
}
