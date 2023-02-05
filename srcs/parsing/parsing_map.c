/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2023/02/05 12:56:02 by bducrocq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

typedef struct s_vector3
{
	int	i;
	int	y;
	int	x;
}		t_vector3;

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
	if (main->ps.map.maxw < ft_strlen(buf))
		main->ps.map.maxw = ft_strlen(buf);
	if (!main->ps.map.maptmp)
		tmp = ft_strdup(buf);
	else
		tmp = ft_strjoin(main->ps.map.maptmp, buf);
	free (main->ps.map.maptmp);
	main->ps.map.maptmp = ft_strdup(tmp);
	free (tmp);
	main->ps.map.maxh++;
	return (EXIT_SUCCESS);
}

int	ft_pars_norm_map(t_main *main)
{
	int	i;
	int	y;
	int	x;

	main->ps.map.maxh += 3;
	main->gm.map = ft_calloc_cub(main->ps.map.maxh, sizeof(char **), main);
	i = 0;
	y = 0;
	x = 0;
	while (main->ps.map.maptmp[y] && i < main->ps.map.maxh)
	{
		main->gm.map[i] = ft_calloc_cub(main->ps.map.maxw + 3, sizeof(char *), main);
		ft_memset(main->gm.map[i], EMPTY, main->ps.map.maxw + 1);
		if (i > 0)
		{
			while (main->ps.map.maptmp[y] && main->ps.map.maptmp[y] != '\n')
			{
				if (!ft_isspace(main->ps.map.maptmp[y]))
					main->gm.map[i][x + 1] = main->ps.map.maptmp[y];
				y++;
				x++;
			}
			if (main->ps.map.maptmp[y] && main->ps.map.maptmp[y] == '\n')
			{
				y++;
				x = 0;
			}
		}
		printf("line %03i = %s\n", i, main->gm.map[i]);
			i++;
	}
		main->gm.map[i] = ft_calloc_cub(main->ps.map.maxw + 3, sizeof(char *), main);
		ft_memset(main->gm.map[i], EMPTY, main->ps.map.maxw + 1);
		printf("line %03i = %s\n", i, main->gm.map[i]);
	return (EXIT_SUCCESS);
}

/**
 * @brief check if the map is close with wall
 * 
 * @param main 
 * @return int 
 */
int	ft_pars_check_wall(t_main *main)
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	while (main->gm.map[i])
	{
		while (main->gm.map[i][y])
		{
			if (main->gm.map[i][y] == FLOOR)
			{
				if (main->gm.map[i][y - 1] == EMPTY \
				|| main->gm.map[i][y + 1] == EMPTY \
				|| main->gm.map[i - 1][y] == EMPTY \
				|| main->gm.map[i + 1][y] == EMPTY)
					ft_err_display_and_exit(ERR_MAP_WALLNOCLOSE, main);
			}
			y++;
		}
		y = 0;
		i++;
	}
	return (EXIT_SUCCESS);
}
