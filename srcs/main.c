/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:48:59 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/22 01:49:40 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_main	main;
	ft_bzero(&main, sizeof(t_main));
	main.ps.ac = ac;
	main.ps.av = av;
	main.mlx = mlx_init();
	if (ft_start_parsing(&main) == EXIT_SUCCESS)
		printf("Parsing it's OK\nLet's go exec !\n");
	return (0);
}
