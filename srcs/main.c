/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:48:59 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/20 04:30:34 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_data	db;

	if (av[1])
		ft_pars_headerfile(av[1]);

	ft_bzero(&db, sizeof(t_data));
	db.ps.ac = ac;
	db.ps.av = av;
	if (ft_start_parsing(&db) == EXIT_SUCCESS)
		printf("Let's go exec\n");
	return (0);
}
