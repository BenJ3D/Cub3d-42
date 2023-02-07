/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/28 03:09:49 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free_tab_char(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free (tab);
}

void	ft_destroy_all_img(t_main *main)
{
	if (main->gm.img_ea.img)
		mlx_destroy_image(main->mlx, main->gm.img_ea.img);
	if (main->gm.img_we.img)
		mlx_destroy_image(main->mlx, main->gm.img_we.img);
	if (main->gm.img_so.img)
		mlx_destroy_image(main->mlx, main->gm.img_so.img);
	if (main->gm.img_no.img)
		mlx_destroy_image(main->mlx, main->gm.img_no.img);
}

void	ft_free_all(t_main *main)
{
	free(main->ps.map_path);
	ft_free_tab_char(main->gm.map);
	free(main->ps.map.maptmp);
	ft_destroy_all_img(main);
	//destroy img mlx / mlx
}

/**
 * @brief free and exit(0)
 * 
 * @param main 
 */
void	ft_free_all_and_exit(t_main *main)
{
	ft_free_all(main);
	exit(0);
}

/**
 * @brief free and exit(error)
 * 
 * @param main 
 * @param error 
 */
void	ft_free_all_and_exit_err(t_main *main, int error)
{
	ft_free_all(main);
	exit(error);
}
