/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_parameters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2023/02/05 12:39:30 by bducrocq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_get_next_word_custom_i(char *buf, int *i2, t_main *main)
{
	char			*tmp;
	int				i;
	int				y;
	int				x;

	i = *i2;
	y = 0;
	x = 0;
	while (buf[i] && ft_isspace(buf[i]))
		i++;
	if (buf[i] == ',')
	{
		*i2 = i + 1;
		return (ft_strdup(","));
	}
	y = i;
	while (buf[y] && !ft_isspace(buf[y]) && buf[y] != ',')
		y++;
	y = y - i;
	tmp = ft_calloc_cub(y + 1, sizeof(char), main);
	while (buf[i] && y-- > 0)
		tmp[x++] = buf[i++];
	tmp[x] = '\0';
	*i2 = i;
	return (tmp);
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

/**
 * @brief return 1 if only digit
 * 
 * @param str 
 * @return int 
 */
static int	ft_str_has_only_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
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
