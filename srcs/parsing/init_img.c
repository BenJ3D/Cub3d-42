/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/22 04:23:02 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_data	ft_init_mlx_img(char *buf, t_main *main)
{
	t_data	img;
	char	path[MAXPATH];
	int		i;

	i = 0;
	ft_bzero(path, sizeof(char) * MAXPATH);
	while (ft_isspace(*buf))
		buf++;
	while (!ft_isspace(buf[i]))
			i++;
	while (ft_isspace(buf[i]))
		i++;
	if (!ft_isspace(buf[i]) && buf[i] != '\0')
		ft_err_display(ERR_PARAM_INVALID, main);
	i = 0;
	while (!ft_isspace(buf[i]) && i <= MAXPATH)
	{
		path[i] = buf[i];
		i++;
	}
	ft_pars_openfile(path);
	return (img);
}