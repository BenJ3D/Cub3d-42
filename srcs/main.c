/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:48:59 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/27 16:58:47 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*																		*\
	/!\ sous linux /!\	dans includes/ :									
	decommenter struct_parsing.h:18 et commenter struct_parsing.h:17		
\*																		*/
int	ft_exec(t_main *main)
{
	char	*line;

	line = ft_strjoin_max("%sParsing it's OK%s\nLet's go exec !\n \
%stab map est dans main.gm.map (le joueur y est effacer)\n \
et la map est rempli/entourer de char '-' (define avec %sEMPTYCHAR%s)\n \
position joueur dans %smain.gm.playstart.x & main.gm.playstart.y%s", \
COLOR_GREEN, COLOR_RED, COLOR_PURPLE, COLOR_BLUE,
			COLOR_PURPLE, COLOR_GREEN, COLOR_NONE);
	ft_putstr_fd(line, 2);
	free (line);
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
