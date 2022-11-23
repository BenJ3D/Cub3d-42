/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/23 22:59:17 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_set_parameters_with_file_header(t_main *main)
{
	char	*buf;
	
	buf = get_next_line(main->ps.map_fd);
	while(buf && main->ps.param_count < 6)
	{
		ft_pars_headerfile(buf, main);
		free (buf);
		buf = get_next_line(main->ps.map_fd);
	}
	free (buf);
	// printf("dgb path EA = %s\n", main->ps.txtpath.pathEA);
	dbg_display_all_parameter_value(main);
	// printf("dgb path EA = %s\n", main->ps.txtpath.pathEA);
	puts("Yolo tous les parm sont la\n");
	return (EXIT_SUCCESS);
}