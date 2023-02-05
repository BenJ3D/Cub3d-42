/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2023/02/05 14:32:43 by bducrocq         ###   ########lyon.fr   */
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
	if (main->ps.map.maxw < (int)ft_strlen(buf))
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

void	ft_pars_norm_map2(t_main *main, t_vector *v)
{
	while (main->ps.map.maptmp[v->y] && v->i < main->ps.map.maxh)
	{
		main->gm.map[v->i] = ft_calloc_cub(main->ps.map.maxw + 3, \
														sizeof(char *), main);
		ft_memset(main->gm.map[v->i], EMPTY, main->ps.map.maxw + 1);
		if (v->i > 0)
		{
			while (main->ps.map.maptmp[v->y] \
			&& main->ps.map.maptmp[v->y] != '\n')
			{
				if (!ft_isspace(main->ps.map.maptmp[v->y]))
					main->gm.map[v->i][v->x + 1] = main->ps.map.maptmp[v->y];
				v->y++;
				v->x++;
			}
			if (main->ps.map.maptmp[v->y] && main->ps.map.maptmp[v->y] == '\n')
			{
				v->y++;
				v->x = 0;
			}
		}
		// printf("line %03i = %s\n", v->i, main->gm.map[v->i]);
		v->i++;
	}
}

int	ft_pars_norm_map(t_main *main)
{
	t_vector	vec;

	main->ps.map.maxh += 3;
	main->gm.map = ft_calloc_cub(main->ps.map.maxh, sizeof(char **), main);
	ft_bzero(&vec, sizeof(t_vector));
	ft_pars_norm_map2(main, &vec);
	main->gm.map[vec.i] = ft_calloc_cub(main->ps.map.maxw + 3, \
														sizeof(char *), main);
	ft_memset(main->gm.map[vec.i], EMPTY, main->ps.map.maxw + 1);
	// printf("line %03i = %s\n", vec.i, main->gm.map[vec.i]);
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
