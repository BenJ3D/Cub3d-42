/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:48:59 by bducrocq          #+#    #+#             */
/*   Updated: 2022/12/10 15:45:51 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_exec(t_main *game)
{
	exec_main(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, &key_press, game);
	mlx_hook(game->mlx_win, 17, 0L, &stop_mlx, game);
	mlx_hook(game->mlx_win, 3, 1L << 1, &key_release, game);
	mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_main	main;

	ft_bzero(&main, sizeof(t_main));
	main.plane_x = 0;
	main.plane_y = FOV_HORIZONTAL;
	main.gm.cell_size = 64;
	main.ps.ac = ac;
	main.ps.av = av;
	main.mlx = mlx_init();
	if (!main.mlx)
		ft_err_display_and_exit(ERR_MLX_FAILINIT, &main);
	if (ft_start_parsing(&main) == EXIT_SUCCESS)
		ft_exec(&main);
	ft_free_all_and_exit(&main);
	return (0);
}
