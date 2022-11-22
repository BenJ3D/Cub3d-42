/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_parameters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/22 03:45:15 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vector	ft_get_rgb_value(const char *buf, int i, t_main *main)
{
	char		*tmp;
	int			step;
	t_vector	vec;
	
	step = 0;
	tmp = NULL;
	ft_bzero(&vec, sizeof(t_vector));
	while (ft_isspace(buf[i]))
		i++;
	if (!ft_isdigit(buf[i]))
		ft_err_display(ERR_PARAM_INVALID, main);
	while(buf[i])
	{
		if ((!ft_isdigit(buf[i])) && !ft_isspace(buf[i]) && buf[i] != ',')
			ft_err_display(ERR_PARAM_INVALID, main);
		if (ft_isdigit(buf[i]))
		{
			tmp = ft_concat_char(tmp, buf[i]);
			if (!ft_isdigit(buf[i + 1]))
			{
				if (ft_strlen(tmp) > 3)
					ft_err_display(ERR_PARAM_TO_HIGH, main);
				if (step == 0)
					vec.x = ft_atoi(tmp);
				else if (step == 1)
					vec.y = ft_atoi(tmp);
				else if (step == 2)
					vec.z = ft_atoi(tmp);
				step++;
				free (tmp);
				tmp = NULL;
				i++;
			}
		}
		if (step > 0 && step < 3)
		{
			if (!ft_isdigit(buf[i]) && (buf[i] != ',' || !ft_isdigit(buf[i + 1])))
				ft_err_display(ERR_PARAM_INVALID, main);
		}
		else if (buf[i] && step >= 3)
		{
			if (!ft_isspace(buf[i]))
				ft_err_display(ERR_PARAM_INVALID, main);
		}
		if (buf [i])
			i++;
	}
	if (vec.x > 255 || vec.y > 255 || vec.z > 255)
		ft_err_display(ERR_PARAM_TO_HIGH, main);
	return (vec);
}



/**
 * @brief check header file for find parameters line per line
 * 
 * @param buff 
 */
void	ft_pars_headerfile(char *buf, t_main *main)
{
	int		i;
	int		type;
	char	*tmp;
	
	i = 0;
	while(ft_isspace(buf[i]))
		i++;
	if (!buf[i])
		return ;
	if (ft_strncmp(buf + i, PARAM_EA, ft_strlen(PARAM_EA)) == 0)
	{
		puts("go param EA\n");
		main->gm.imgEA = ft_init_mlx_img(buf + i + ft_strlen(PARAM_EA), main);
	}
	else if (ft_strncmp(buf + i, PARAM_WE, ft_strlen(PARAM_WE)) == 0)
		puts("go param WE\n");
	else if (ft_strncmp(buf + i, PARAM_NO, ft_strlen(PARAM_NO)) == 0)
		puts("go param NO\n");
	else if (ft_strncmp(buf + i, PARAM_SO, ft_strlen(PARAM_SO)) == 0)
		puts("go param SO\n");
	else if (ft_strncmp(buf + i, PARAM_C, ft_strlen(PARAM_C)) == 0)
		main->gm.c_rgb = ft_get_rgb_value(buf, i + 1, main);
	else if (ft_strncmp(buf + i, PARAM_F, ft_strlen(PARAM_F)) == 0)
		main->gm.f_rgb = ft_get_rgb_value(buf, i + 1, main);
	else if (ft_strncmp(buf + i, LEGITCHAR, 1) == 0)
		ft_err_display(ERR_PARAM_MISSING, main);
	else
		ft_err_display(ERR_PARAM_UNKNOWN, main);
}