/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/21 20:08:55 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_set_parameters_with_file_header(t_main *main)
{
	char	*buf;
	
	buf = get_next_line(main->ps.map_fd);
	while(buf)
	{
		ft_pars_headerfile(buf, main);
		/* tant que pas tous les paranetres TODO: creer une var pour ca*/
		free (buf);
		buf = get_next_line(main->ps.map_fd);
	}
	puts("Yolo tous les parm sont la\n");
	dbg_display_all_parameter_value(main);
	return (EXIT_SUCCESS);
}