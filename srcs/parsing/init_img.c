/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/25 23:03:48 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_mlx_img(t_main *main)
{
	if (ft_pars_openfile(main->ps.txtpath.pathEA) < 0)
		ft_err_display_and_exit(ERR_TXTMISSING_EA, main);
	if (ft_pars_openfile(main->ps.txtpath.pathWE) < 0)
		ft_err_display_and_exit(ERR_TXTMISSING_WE, main);
	if (ft_pars_openfile(main->ps.txtpath.pathSO) < 0)
		ft_err_display_and_exit(ERR_TXTMISSING_SO, main);
	if (ft_pars_openfile(main->ps.txtpath.pathNO) < 0)
		ft_err_display_and_exit(ERR_TXTMISSING_NO, main);
// 	main->mlx = mlx_init();
// 	main->gm.imgEA.img = mlx_xpm_file_to_image(main->mlx,› )
}