/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/25 23:29:07 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_start_parsing(t_main *main)
{
	if (main->ps.ac < 2)
		ft_err_display(ERR_NOARG, main);
	else if (main->ps.ac > 2)
		ft_err_display(ERR_TOOMANYARG, main);
	else if (ft_pars_check_type_file(main->ps.av[1], CUBEXT))
		ft_err_display(ERR_BADEXTENSION, main);
	main->ps.map_path = ft_strdup(main->ps.av[1]);
	main->ps.map_fd = ft_pars_openfile(main->ps.map_path);
	if (main->ps.map_fd < 3)
		ft_free_all_and_exit_err(main, errno);
	else
		ft_set_parameters_with_file(main);
	ft_pars_norm_map(main);
	ft_pars_check_wall(main);
	ft_pars_check_player_pos(main);
	ft_init_mlx_img(main);
	return (EXIT_SUCCESS);
}

void	ft_pars_check_player_pos(t_main *main)
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	while (main->gm.map[i])
	{
		while (main->gm.map[i][y])
		{
			if (main->gm.map[i][y] == main->ps.charplayer)
			{
				if (main->gm.map[i][y - 1] == EMPTY \
				|| main->gm.map[i][y + 1] == EMPTY \
				|| main->gm.map[i - 1][y] == EMPTY \
				|| main->gm.map[i + 1][y] == EMPTY)
					ft_err_display_and_exit(ERR_MAP_WALLNOCLOSE, main);
				main->gm.playstart.x = y;
				main->gm.playstart.y = i;
				main->gm.map[i][y] = '0';
			}
			y++;
		}
		y = 0;
		i++;
	}
}
