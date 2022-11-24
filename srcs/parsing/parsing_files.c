/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/24 16:58:34 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_if_map_has_player(t_main *main)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strdup(main->ps.map.maptmp);
	while(str[i])
	{
		while(str[i] && ft_isspace(str[i]))
			i++;
		if (ft_pars_check_has_chars(str[i], PLAYERSTART, main) == EXIT_SUCCESS)
		{
			free (str);
			return (EXIT_SUCCESS);
		}
		if (str[i])
			i++;
	}
	free (str);
	return (EXIT_FAILURE);
}


int	ft_set_parameters_with_file(t_main *main)
{
	char	*buf;
	
	buf = get_next_line(main->ps.map_fd);
	while(buf)
	{
		if (main->ps.param_count > 5)
			ft_pars_map(buf, main);
		else
			ft_pars_headerfile(buf, main);
		free (buf);
		buf = get_next_line(main->ps.map_fd);
	}
	free (buf);
	dbg_display_all_parameter_value(main);
	if (ft_check_if_map_has_player(main) == EXIT_FAILURE)
		ft_err_display_and_exit(ERR_PLAYER_MISSING, main);
	puts("Yolo tous les parm sont la - on \n");
	printf("map one line == \n%s\n", main->ps.map.maptmp);

	return (EXIT_SUCCESS);
}