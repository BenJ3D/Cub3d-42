/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_parameters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/21 04:03:58 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cub3d.h"

// int	ft_get_rgb_value(t_data	*db, char *buf, int	i)
// {
// 	char	tmp[3];
// 	int		max;
// 	int		y;
	
// 	max = 0;
// 	y = 0;
// 	ft_bzero(tmp, sizeof(char));
// 	while (ft_isspace(buf[i]))
// 		i++;
// 	if (!ft_isdigit(buf[i]))
// 		ft_err_display(ERR_PARAM_INVALID);
// 	while (buf[i])
// 	{
// 		while (buf[i] && ft_isdigit(buf[i]))
// 		{
// 			tmp[y++] = buf[i++];
// 			max++;
// 		}
// 		while (max <= 3)
// 		{
// 			tmp[y++] = '\0';
// 			max++;
// 		}
// 	}
// 	return (0);
// }


//   C       417,2,25     

t_vector	ft_get_rgb_value(const char *buf, int i)
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
		ft_err_display(ERR_PARAM_INVALID);
	while(buf[i])
	{
		if ((!ft_isdigit(buf[i])) && !ft_isspace(buf[i]) && buf[i] != ',')
			ft_err_display(ERR_PARAM_INVALID);
		if (ft_isdigit(buf[i]))
		{
			tmp = ft_concat_char(tmp, buf[i]);
			if (!ft_isdigit(buf[i + 1]))
			{
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
				ft_err_display(ERR_PARAM_INVALID);

		}
		else if (buf[i] && step >= 3)
		{
			if (!ft_isspace(buf[i]))
				ft_err_display(ERR_PARAM_INVALID);
		}
		if (buf [i])
			i++;
	}
	return (vec);
}


int	ft_pars_set_param_east(t_data *db)
{
	
	return (0);
}


/**
 * @brief check header file for find parameters line per line
 * 
 * @param buff 
 */
void	ft_pars_headerfile(const char *buf, t_data *db)
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
		puts("go param EA\n");
	else if (ft_strncmp(buf + i, PARAM_WE, ft_strlen(PARAM_WE)) == 0)
		puts("go param WE\n");
	else if (ft_strncmp(buf + i, PARAM_NO, ft_strlen(PARAM_NO)) == 0)
		puts("go param NO\n");
	else if (ft_strncmp(buf + i, PARAM_SO, ft_strlen(PARAM_SO)) == 0)
		puts("go param SO\n");
	else if (ft_strncmp(buf + i, PARAM_C, ft_strlen(PARAM_C)) == 0)
		db->gm.ceiling = ft_get_rgb_value(buf, i + 1);
	else if (ft_strncmp(buf + i, PARAM_F, ft_strlen(PARAM_F)) == 0)
		db->gm.floor = ft_get_rgb_value(buf, i + 1);
	else
		ft_err_display(ERR_PARAM_UNKNOWN);
}