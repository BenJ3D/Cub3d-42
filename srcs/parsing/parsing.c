/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/21 19:44:44 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_start_parsing(t_main *main)
{
	if (main->ps.ac < 2)
		ft_err_display(ERR_NOARG);
	else if (main->ps.ac > 2)
		ft_err_display(ERR_TOOMANYARG);
	else if (ft_pars_check_type_file(main->ps.av[1], CUBEXT))
		ft_err_display(ERR_BADEXTENSION);
	main->ps.map_path = ft_strdup(main->ps.av[1]);
	main->ps.map_fd = ft_pars_openfile(main->ps.map_path);
	if (main->ps.map_fd < 0)
		exit (errno);
	else
		ft_set_parameters_with_file_header(main);
	return (EXIT_SUCCESS);
}
