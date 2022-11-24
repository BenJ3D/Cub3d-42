/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_parameters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/24 02:30:32 by bducrocq         ###   ########.fr       */
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

t_vector	ft_get_rgb_value(char *buf, t_main *main)
{
	int			i;
	int			step;
	char		*tmp;
	t_vector	vec;
	
	i = 0;
	step = 0;
	tmp = NULL;
	ft_bzero(&vec, sizeof(t_vector));
	while(step < 3)
	{
		tmp = ft_get_next_word_custom_i(buf, &i, main);
		if (ft_str_has_only_digit(tmp))
		{
			free(tmp);
			ft_err_display_and_exit(ERR_PARAM_INVALID, main);
		}
		if (ft_str_has_only_digit(tmp) || ft_strlen(tmp) > 3)
		{
			free(tmp);
			ft_err_display_and_exit(ERR_PARAM_TO_HIGH, main);
		}
		if (step == 0)
			vec.x = ft_atoi(tmp);
		else if (step == 1)
			vec.y = ft_atoi(tmp);
		else if (step == 2)
			vec.z = ft_atoi(tmp);
		step++;
		free(tmp);
		tmp = NULL;
		tmp = ft_get_next_word_custom_i(buf, &i, main);
		if (step < 3 && ft_strncmp(tmp, ",", 2))
		{
			free(tmp);
			tmp = NULL;
			ft_err_display_and_exit(ERR_PARAM_INVALID, main);
		}
		else if (step >= 3 && tmp[0] != '\0')
		{
			free(tmp);
			tmp = NULL;
			ft_err_display_and_exit(ERR_PARAM_INVALID, main);
		}
		free (tmp);
	}
	if ((vec.x > 255 || vec.x < 0) || (vec.y > 255 || vec.y < 0) \
												|| (vec.z > 255 || vec.z < 0))
		ft_err_display(ERR_PARAM_TO_HIGH, main);
	return (vec);
}

void	ft_action_for_texture_param(int paramtype)
{
	
}

/**
 * @brief check header file for find parameters line per line //TODO: norme ;(
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
		if (!ft_isspace(buf[i + ft_strlen(PARAM_EA)]))
			ft_err_display_and_exit(ERR_PARAM_INVALID, main);
		ft_getpath_texture(buf + (i + ft_strlen(PARAM_EA)), \
											main->ps.txtpath.pathEA, main);
		main->ps.param_count++;
	}
	else if (ft_strncmp(buf + i, PARAM_WE, ft_strlen(PARAM_WE)) == 0)
	{
		ft_getpath_texture(buf + (i + ft_strlen(PARAM_WE)), \
											main->ps.txtpath.pathWE, main);
		main->ps.param_count++;

	}
	else if (ft_strncmp(buf + i, PARAM_NO, ft_strlen(PARAM_NO)) == 0)
	{
		ft_getpath_texture(buf + (i + ft_strlen(PARAM_NO)), \
											main->ps.txtpath.pathNO, main);
		main->ps.param_count++;

	}
	else if (ft_strncmp(buf + i, PARAM_SO, ft_strlen(PARAM_SO)) == 0)
	{
		ft_getpath_texture(buf + (i + ft_strlen(PARAM_SO)), \
											main->ps.txtpath.pathSO, main);
		main->ps.param_count++;

	}
	else if (ft_strncmp(buf + i, PARAM_C, ft_strlen(PARAM_C)) == 0)
	{
		if (!ft_isspace(buf[i + 1]))
			ft_err_display_and_exit(ERR_PARAM_INVALID, main);
		else if (main->ps.c_isalreadyset == 1)
			ft_err_display_and_exit(ERR_PARAM_DUPLICATED, main);
		main->gm.c_rgb = ft_get_rgb_value(buf + (i + 1), main);
		main->ps.c_isalreadyset = 1;
		main->ps.param_count++;
	}
	else if (ft_strncmp(buf + i, PARAM_F, ft_strlen(PARAM_F)) == 0)
	{
		if (!ft_isspace(buf[i + 1]))
			ft_err_display_and_exit(ERR_PARAM_INVALID, main);
		else if (main->ps.f_isalreadyset == 1)
			ft_err_display_and_exit(ERR_PARAM_DUPLICATED, main);
		main->gm.f_rgb = ft_get_rgb_value(buf + (i + 1), main);
		main->ps.f_isalreadyset = 1;
		main->ps.param_count++;
	}
	else if (ft_strncmp(buf + i, LEGITCHAR, 1) == 0)
		ft_err_display(ERR_PARAM_MISSING, main);
	else
		ft_err_display(ERR_PARAM_UNKNOWN, main);
}

		// main->gm.imgEA = ft_init_mlx_img(buf + i + ft_strlen(PARAM_EA), main);
