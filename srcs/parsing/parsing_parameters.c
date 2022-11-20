/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_parameters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/20 04:29:51 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief check header file for find parameters line per line
 * 
 * @param buff 
 */
void	ft_pars_headerfile(const char *buf)
{
	int		i;
	int		type;
	char	*tmp;
	
	i = 0;
	while(ft_isspace(buf[i]))
		i++;
	if (!buf[i])
		return (EXIT_SUCCESS);
	if (ft_strncmp(buf + i, PARAM_EA, ft_strlen(PARAM_EA)) == 0)
		puts("go param EA\n");
	else if (ft_strncmp(buf + i, PARAM_WE, ft_strlen(PARAM_WE)) == 0)
		puts("go param WE\n");
	else if (ft_strncmp(buf + i, PARAM_NO, ft_strlen(PARAM_NO)) == 0)
		puts("go param NO\n");
	else if (ft_strncmp(buf + i, PARAM_SO, ft_strlen(PARAM_SO)) == 0)
		puts("go param SO\n");
	else if (ft_strncmp(buf + i, PARAM_C, ft_strlen(PARAM_C)) == 0)
		puts("go param C\n");
	else if (ft_strncmp(buf + i, PARAM_F, ft_strlen(PARAM_F)) == 0)
		puts("go param F\n");
	else
		ft_err_display(ERR_PARAM_UNKNOWN);
}