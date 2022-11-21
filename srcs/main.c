/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:48:59 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/21 04:35:10 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_data	db;
//   C       417,2,25    
///////////////// TEST  ////////////////////
	char test[] = "    C 	25,45,42	 ";
	char test2[] = " F 4,50,6";
	
	printf("Testing with buf :\n%s\n%s\n\n", test, test2);
	ft_bzero(&db, sizeof(t_data));
	ft_pars_headerfile(test, &db);
	ft_pars_headerfile(test2, &db);
	printf ("Result :\nCeiling vector R=%i,G=%i,B=%i\n", \
	db.gm.ceiling.x, db.gm.ceiling.y, db.gm.ceiling.z);
	printf ("Floor   vector R=%i,G=%i,B=%i\n", \
	db.gm.floor.x, db.gm.floor.y, db.gm.floor.z);
		
	printf("\n\n----------- SUCCESS -------------\n");
	printf("----- Fin du test unitaire ------\n");
	printf("---------------------------------\n\n");
///////////////// END  ////////////////////

	ft_bzero(&db, sizeof(t_data));
	db.ps.ac = ac;
	db.ps.av = av;
	if (ft_start_parsing(&db) == EXIT_SUCCESS)
		printf("Parsing it's OK\nLet's go exec !\n");
	return (0);
}
