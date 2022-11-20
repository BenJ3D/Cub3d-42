/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:48:59 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/20 01:43:40 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_data	db;

	ft_bzero(&db, sizeof(t_data));
	db.ps.ac = ac;
	db.ps.av = av;
	if (ft_start_parsing(&db) == EXIT_SUCCESS)
		printf("Let's go exec\n");
	return (0);
}
