/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_parameters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2023/02/05 14:38:48 by bducrocq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_get_next_word_custom_i(char *buf, int *i2, t_main *main)
{
	t_vector		v;

	ft_bzero(&v, sizeof(t_vector));
	v.i = *i2;
	while (buf[v.i] && ft_isspace(buf[v.i]))
		v.i++;
	if (buf[v.i] == ',')
	{
		*i2 = v.i + 1;
		return (ft_strdup(","));
	}
	v.y = v.i;
	while (buf[v.y] && !ft_isspace(buf[v.y]) && buf[v.y] != ',')
		v.y++;
	v.y = v.y - v.i;
	v.tmp = ft_calloc_cub(v.y + 1, sizeof(char), main);
	while (buf[v.i] && v.y-- > 0)
		v.tmp[v.x++] = buf[v.i++];
	v.tmp[v.x] = '\0';
	*i2 = v.i;
	return (v.tmp);
}

void	ft_getpath_texture(char *str, char dest[PATH_MAX], t_main *main)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (dest[0] != '\0')
		ft_err_display_and_exit(ERR_PARAM_DUPLICATED, main);
	while (ft_isspace(str[i]))
		i++;
	while (!ft_isspace(str[i]))
		dest[y++] = str[i++];
	while (str[i])
	{
		if (!ft_isspace(str[i]) && str[i] != '\0')
			ft_err_display_and_exit(ERR_PARAM_INVALID, main);
		i++;
	}
}

void	ft_pars_check_range_rgb(t_vector vec, t_main *main)
{
	if ((vec.x > 255 || vec.x < 0) || (vec.y > 255 || vec.y < 0) \
												|| (vec.z > 255 || vec.z < 0))
		ft_err_display_and_exit(ERR_PARAM_TO_HIGH, main);
}

void	ft_err_rgb(int errtype, char *tofree, t_main *main)
{
	free (tofree);
	ft_err_display_and_exit(errtype, main);
}
