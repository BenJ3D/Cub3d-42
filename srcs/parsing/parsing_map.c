/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/24 03:35:15 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_pars_map(char *buf, t_main *main)
{
	int		i;
	char	*tmp;
	
	i = 0;
	while (ft_isspace(buf[i]))
		i++;
	if (buf[0] == '\n' || buf[i] == '\0')
		return (EXIT_SUCCESS);
	while (buf[i])
	{
		if (ft_pars_check_has_chars(buf[i], LEGITCHAR, main) && buf[i] != '\n')
			ft_err_display_and_exit(ERR_MAP_UNKNOWN_CHAR, main);
		i++;
	}
	if (main->ps.map.max_width < ft_strlen(buf))
		main->ps.map.max_width = ft_strlen(buf);
	if (!main->ps.map.maptmp)
		tmp = ft_strdup(buf);
	else
		tmp = ft_strjoin(main->ps.map.maptmp, buf);
	free (main->ps.map.maptmp);
	main->ps.map.maptmp = ft_strdup(tmp);
	free (tmp);
	main->ps.map.max_h++;
	return (EXIT_SUCCESS);
}

int	ft_norm_map(t_main *main)
{
	int	i;
	
	main->ps.map.max_h += 3;
	main->gm.map = ft_calloc_cub(main->ps.map.max_h, sizeof(char **), main);
	i = 0;
	while(i < main->ps.map.max_h)
	{
		//TODO: split et remplir de EMPTYCHAR
	}
	return (EXIT_SUCCESS);
}