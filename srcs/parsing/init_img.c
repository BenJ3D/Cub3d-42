/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2023/02/05 12:33:13 by bducrocq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_make_xmp_to_img(t_main *main)
{
	main->gm.img_ea.img = mlx_xpm_file_to_image(main->mlx, \
	main->ps.txtpath.path_ea, &main->gm.img_ea.width, &main->gm.img_ea.height);
	main->gm.img_we.img = mlx_xpm_file_to_image(main->mlx, \
	main->ps.txtpath.path_we, &main->gm.img_we.width, &main->gm.img_we.height);
	main->gm.img_so.img = mlx_xpm_file_to_image(main->mlx, \
	main->ps.txtpath.path_so, &main->gm.img_so.width, &main->gm.img_so.height);
	main->gm.img_no.img = mlx_xpm_file_to_image(main->mlx, \
	main->ps.txtpath.path_no, &main->gm.img_no.width, &main->gm.img_no.height);
	main->gm.img_ea.addr = mlx_get_data_addr(main->gm.img_ea.img, \
	&main->gm.img_ea.bpp, &main->gm.img_ea.line_length, &main->gm.img_ea.end);
	main->gm.img_we.addr = mlx_get_data_addr(main->gm.img_we.img, \
	&main->gm.img_we.bpp, &main->gm.img_we.line_length, &main->gm.img_we.end);
	main->gm.img_no.addr = mlx_get_data_addr(main->gm.img_no.img, \
	&main->gm.img_no.bpp, &main->gm.img_no.line_length, &main->gm.img_no.end);
	main->gm.img_so.addr = mlx_get_data_addr(main->gm.img_so.img, \
	&main->gm.img_so.bpp, &main->gm.img_so.line_length, &main->gm.img_so.end);
	main->gm.img_ea.bpp /= 8;
	main->gm.img_we.bpp /= 8;
	main->gm.img_so.bpp /= 8;
	main->gm.img_no.bpp /= 8;
}

void	ft_init_mlx_img(t_main *main)
{
	if (ft_pars_check_type_file(main->ps.txtpath.path_ea, IMGEXT))
		ft_err_display_and_exit(ERR_IMGBADEXTENSION, main);
	if (ft_pars_openfile(main->ps.txtpath.path_ea) < 0)
		ft_err_display_and_exit(ERR_TXTMISSING_EA, main);
	if (ft_pars_check_type_file(main->ps.txtpath.path_we, IMGEXT))
		ft_err_display_and_exit(ERR_IMGBADEXTENSION, main);
	if (ft_pars_openfile(main->ps.txtpath.path_we) < 0)
		ft_err_display_and_exit(ERR_TXTMISSING_WE, main);
	if (ft_pars_check_type_file(main->ps.txtpath.path_so, IMGEXT))
		ft_err_display_and_exit(ERR_IMGBADEXTENSION, main);
	if (ft_pars_openfile(main->ps.txtpath.path_so) < 0)
		ft_err_display_and_exit(ERR_TXTMISSING_SO, main);
	if (ft_pars_check_type_file(main->ps.txtpath.path_no, IMGEXT))
		ft_err_display_and_exit(ERR_IMGBADEXTENSION, main);
	if (ft_pars_openfile(main->ps.txtpath.path_no) < 0)
		ft_err_display_and_exit(ERR_TXTMISSING_NO, main);
	ft_make_xmp_to_img(main);
}
