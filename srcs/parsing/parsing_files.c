/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/20 04:11:12 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_set_parameters_with_file_header(t_data *db)
{
	char	*buf;
	
	while(buf)
	{
		/* tant que pas tous les paranetre TODO: creer une var pour ca*/
		free (buf);
		buf = get_next_line(db->ps.map_fd);
	}
	return (EXIT_SUCCESS);
}