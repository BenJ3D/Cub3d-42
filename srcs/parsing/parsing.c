/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2023/02/06 21:55:54 by bducrocq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_start_parsing(t_main *main)
{
	if (main->ps.ac < 2)
		ft_err_display_and_exit(ERR_NOARG, main);
	else if (main->ps.ac > 2)
		ft_err_display_and_exit(ERR_TOOMANYARG, main);
	else if (ft_pars_check_type_file(main->ps.av[1], CUBEXT))
		ft_err_display_and_exit(ERR_BADEXTENSION, main);
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

void	calc_n_and_s(t_main *game, double PI)
{
	float	old_delta_x;
	float	old_plane_x;

	game->plane_x = 0;
	game->plane_y = FOV_HORIZONTAL;
	old_delta_x = game->gm.start_rot.x;
	old_plane_x = 0;
	game->gm.start_rot.x = game->gm.start_rot.x * cos(PI) - \
	game->gm.start_rot.y * sin(PI);
	game->gm.start_rot.y = old_delta_x * sin(PI) + \
	game->gm.start_rot.y * cos(PI);
	game->plane_x = game->plane_x * cos(PI) - \
	game->plane_y * sin(PI);
	game->plane_y = old_plane_x * sin(PI) + \
	game->plane_y * cos(PI);
}

static void	ft_set_player_pos_angle(t_main *main, int i, int y)
{
	main->gm.start_rot.y = 0.0;
	if (main->ps.charplayer == 'S')
	{
		main->gm.start_rot.x = 1.0;
		calc_n_and_s(main, M_PI_2);
	}
	if (main->ps.charplayer == 'N')
	{
		main->gm.start_rot.x = 1.0;
		calc_n_and_s(main, -M_PI_2);
	}
	if (main->ps.charplayer == 'W')
	{
		main->gm.start_rot.x = 1.0;
		calc_n_and_s(main, M_PI);
	}
	if (main->ps.charplayer == 'E')
		main->gm.start_rot.x = 1.0;
	main->gm.playstart.x = y;
	main->gm.playstart.y = i;
	main->gm.map[i][y] = '0';
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
				ft_set_player_pos_angle(main, i, y);
			}
			y++;
		}
		y = 0;
		i++;
	}
}
