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

void	ft_make_xmp_to_img_reflet(t_main *main)
{
	main->gm.img_reflet[0].img = mlx_xpm_file_to_image(main->mlx, \
	FRAME_ANIM0, &main->gm.img_reflet[0].width, &main->gm.img_reflet[0].height);
	main->gm.img_reflet[1].img = mlx_xpm_file_to_image(main->mlx, \
	FRAME_ANIM1, &main->gm.img_reflet[1].width, &main->gm.img_reflet[1].height);
	main->gm.img_reflet[2].img = mlx_xpm_file_to_image(main->mlx, \
	FRAME_ANIM2, &main->gm.img_reflet[2].width, &main->gm.img_reflet[2].height);
	main->gm.img_reflet[3].img = mlx_xpm_file_to_image(main->mlx, \
	FRAME_ANIM3, &main->gm.img_reflet[3].width, &main->gm.img_reflet[3].height);
	main->gm.img_reflet[4].img = mlx_xpm_file_to_image(main->mlx, \
	FRAME_ANIM4, &main->gm.img_reflet[4].width, &main->gm.img_reflet[4].height);
	main->gm.img_reflet[5].img = mlx_xpm_file_to_image(main->mlx, \
	FRAME_ANIM5, &main->gm.img_reflet[5].width, &main->gm.img_reflet[5].height);
	if (!main->gm.img_ea.img || !main->gm.img_we.img || !main->gm.img_so.img \
	|| !main->gm.img_no.img || !main->gm.img_reflet[0].img \
	|| !main->gm.img_reflet[1].img || !main->gm.img_reflet[2].img \
	|| !main->gm.img_reflet[3].img || !main->gm.img_reflet[4].img \
	|| !main->gm.img_reflet[5].img)
		ft_err_display_and_exit(ERR_MLX_FAILINIT, main);
	ft_get_addr_img_reflet(main);
}

void	ft_get_addr_img_reflet(t_main *main)
{
	main->gm.img_reflet[0].addr = \
	mlx_get_data_addr(main->gm.img_reflet[0].img, &main->gm.img_reflet[0].bpp, \
	&main->gm.img_reflet[0].line_length, &main->gm.img_reflet[0].end);
	main->gm.img_reflet[1].addr = \
	mlx_get_data_addr(main->gm.img_reflet[1].img, &main->gm.img_reflet[1].bpp, \
	&main->gm.img_reflet[1].line_length, &main->gm.img_reflet[1].end);
	main->gm.img_reflet[2].addr = \
	mlx_get_data_addr(main->gm.img_reflet[2].img, &main->gm.img_reflet[2].bpp, \
	&main->gm.img_reflet[2].line_length, &main->gm.img_reflet[2].end);
	main->gm.img_reflet[3].addr = \
	mlx_get_data_addr(main->gm.img_reflet[3].img, &main->gm.img_reflet[3].bpp, \
	&main->gm.img_reflet[3].line_length, &main->gm.img_reflet[3].end);
	main->gm.img_reflet[4].addr = \
	mlx_get_data_addr(main->gm.img_reflet[4].img, &main->gm.img_reflet[4].bpp, \
	&main->gm.img_reflet[4].line_length, &main->gm.img_reflet[4].end);
	main->gm.img_reflet[5].addr = \
	mlx_get_data_addr(main->gm.img_reflet[5].img, &main->gm.img_reflet[5].bpp, \
	&main->gm.img_reflet[5].line_length, &main->gm.img_reflet[5].end);
}
