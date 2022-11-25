/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/25 23:28:25 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_mlx_img(t_main *main)
{
	if (ft_pars_openfile(main->ps.txtpath.path_ea) < 0)
		ft_err_display_and_exit(ERR_TXTMISSING_EA, main);
	if (ft_pars_openfile(main->ps.txtpath.path_we) < 0)
		ft_err_display_and_exit(ERR_TXTMISSING_WE, main);
	if (ft_pars_openfile(main->ps.txtpath.path_so) < 0)
		ft_err_display_and_exit(ERR_TXTMISSING_SO, main);
	if (ft_pars_openfile(main->ps.txtpath.path_no) < 0)
		ft_err_display_and_exit(ERR_TXTMISSING_NO, main);
}
