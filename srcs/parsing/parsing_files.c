/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2023/02/05 12:33:43 by bducrocq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_if_map_has_player(t_main *main)
{
	int		i;
	int		ret;
	char	*str;

	i = 0;
	ret = 0;
	str = ft_strdup(main->ps.map.maptmp);
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (ft_pars_check_has_chars(str[i], PLAYERSTART, main) == EXIT_SUCCESS)
		{
			main->ps.charplayer = str[i];
			ret++;
		}
		if (str[i])
			i++;
	}
	free (str);
	return (ret);
}

int	ft_set_parameters_with_file(t_main *main)
{
	char	*buf;
	int		ret;

	ret = 0;
	buf = get_next_line(main->ps.map_fd);
	main->ps.ptrbuf = &buf;
	while (buf)
	{
		if (main->ps.param_count > 5)
			ft_pars_map(buf, main);
		else
			ft_pars_headerfile(buf, main);
		free(buf);
		buf = get_next_line(main->ps.map_fd);
	}
	free(buf);
	buf = NULL;
	main->ps.ptrbuf = NULL;
	ret = ft_check_if_map_has_player(main);
	if (ret == 0)
		ft_err_display_and_exit(ERR_PLAYER_MISSING, main);
	else if (ret > 1)
		ft_err_display_and_exit(ERR_PLAYER_MORE, main);
	return (EXIT_SUCCESS);
}
