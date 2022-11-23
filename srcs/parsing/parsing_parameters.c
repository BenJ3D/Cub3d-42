/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_parameters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/23 17:06:53 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_get_next_word(char *buf, int *i2, t_main *main)
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
		tmp = ft_get_next_word(buf, &i, main);
		printf("tmp = %s\n", tmp);
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
		tmp = ft_get_next_word(buf, &i, main);
		if (step < 3 && ft_strncmp(tmp, ",", 2))
		{
			free(tmp);
			ft_err_display_and_exit(ERR_PARAM_INVALID, main);
		}
		else if (step >= 3 && tmp[0] != '\0')
		{
			free(tmp);
			ft_err_display_and_exit(ERR_PARAM_INVALID, main);
		}
	}
	if ((vec.x > 255 || vec.x < 0) || (vec.y > 255 || vec.y < 0) \
												|| (vec.z > 255 || vec.z < 0))
		ft_err_display(ERR_PARAM_TO_HIGH, main);
	return (vec);
}

// t_vector	ft_get_rgb_value(const char *buf, int i, t_main *main)
// {
// 	char		*tmp;
// 	int			step;
// 	t_vector	vec;
	
// 	step = 0;
// 	tmp = NULL;
// 	ft_bzero(&vec, sizeof(t_vector));
// 	while (ft_isspace(buf[i]))
// 		i++;
// 	if (!ft_isdigit(buf[i]))
// 		ft_err_display(ERR_PARAM_INVALID, main);
// 	while(buf[i])
// 	{
// 		while (ft_isspace(buf[i]))
// 			i++;
// 		if ((!ft_isdigit(buf[i])) && buf[i] != ',')
// 			ft_err_display(ERR_PARAM_INVALID, main);
// 		if (ft_isdigit(buf[i]))
// 		{
// 			tmp = ft_concat_char(tmp, buf[i]);
// 			if (!ft_isdigit(buf[i + 1]))
// 			{
// 				if (ft_strlen(tmp) > 3)
// 					ft_err_display(ERR_PARAM_TO_HIGH, main);
// 				if (step == 0)
// 					vec.x = ft_atoi(tmp);
// 				else if (step == 1)
// 					vec.y = ft_atoi(tmp);
// 				else if (step == 2)
// 					vec.z = ft_atoi(tmp);
// 				step++;
// 				free (tmp);
// 				tmp = NULL;
// 				i++;
// 				while (ft_isspace(buf[i]))
// 					i++;
// 				if (buf[i] != ',')
// 					ft_err_display(ERR_PARAM_INVALID, main);
// 			}
// 		}
// 		if (step > 0 && step < 3)
// 		{
// 			if (ft_isdigit(buf[i]) || buf[i] != ',')
// 				ft_err_display(ERR_PARAM_INVALID, main);
// 		}
// 		else if (buf[i] && step >= 3)
// 		{
// 			if (!ft_isspace(buf[i]))
// 				ft_err_display(ERR_PARAM_INVALID, main);
// 		}
// 		if (buf [i])
// 			i++;
// 	}
// 	if (vec.x > 255 || vec.y > 255 || vec.z > 255)
// 		ft_err_display(ERR_PARAM_TO_HIGH, main);
// 	return (vec);
// }



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
	
		// main->gm.imgEA = ft_init_mlx_img(buf + i + ft_strlen(PARAM_EA), main);
		main->ps.param_count++;
	}
	else if (ft_strncmp(buf + i, PARAM_WE, ft_strlen(PARAM_WE)) == 0)
	{
		puts("go param WE\n");
		main->ps.param_count++;

	}
	else if (ft_strncmp(buf + i, PARAM_NO, ft_strlen(PARAM_NO)) == 0)
	{
		puts("go param NO\n");
		main->ps.param_count++;

	}
	else if (ft_strncmp(buf + i, PARAM_SO, ft_strlen(PARAM_SO)) == 0)
	{
		puts("go param SO\n");
		main->ps.param_count++;

	}
	else if (ft_strncmp(buf + i, PARAM_C, ft_strlen(PARAM_C)) == 0)
	{
		if (!ft_isspace(buf[i + 1]))
			ft_err_display_and_exit(ERR_PARAM_INVALID, main);
		main->gm.c_rgb = ft_get_rgb_value(buf + (i + 1), main);
		main->ps.param_count++;
	}
	else if (ft_strncmp(buf + i, PARAM_F, ft_strlen(PARAM_F)) == 0)
	{
		main->gm.f_rgb = ft_get_rgb_value(buf + (i + 1), main);
		main->ps.param_count++;
	}
	else if (ft_strncmp(buf + i, LEGITCHAR, 1) == 0)
		ft_err_display(ERR_PARAM_MISSING, main);
	else
		ft_err_display(ERR_PARAM_UNKNOWN, main);
}

		// main->gm.imgEA = ft_init_mlx_img(buf + i + ft_strlen(PARAM_EA), main);
