/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:48:59 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/28 01:13:29 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_exec(t_main *main)
{
	exec_main(main);
	mlx_loop_hook(main->mlx, render_next_frame, main);
	mlx_hook(main->mlx_win, 2, 0, key_press, main);
	mlx_loop(main->mlx);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_main	main;

	ft_bzero(&main, sizeof(t_main));
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
