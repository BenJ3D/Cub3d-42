/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_parameters_header.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/25 23:29:31 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_pars_headerfile_no_so(char *buf, int i, t_main *main);
int	ft_pars_headerfile_ea_we(char *buf, int i, t_main *main);
int	ft_pars_headerfile_c_f(char *buf, int i, t_main *main);

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
	while (ft_isspace(buf[i]))
		i++;
	if (!buf[i])
		return ;
	if (ft_pars_headerfile_no_so(buf, i, main) == EXIT_SUCCESS)
		return ;
	else if (ft_pars_headerfile_ea_we(buf, i, main) == EXIT_SUCCESS)
		return ;
	else if (ft_pars_headerfile_c_f(buf, i, main) == EXIT_SUCCESS)
		return ;
	else if (ft_strncmp(buf + i, LEGITCHAR, 1) == 0)
		ft_err_display(ERR_PARAM_MISSING, main);
	else
		ft_err_display(ERR_PARAM_UNKNOWN, main);
}

int	ft_pars_headerfile_ea_we(char *buf, int i, t_main *main)
{
	if (ft_strncmp(buf + i, PARAM_EA, ft_strlen(PARAM_EA)) == 0)
	{
		if (!ft_isspace(buf[i + ft_strlen(PARAM_EA)]))
			ft_err_display_and_exit(ERR_PARAM_INVALID, main);
		ft_getpath_texture(buf + (i + ft_strlen(PARAM_EA)), \
											main->ps.txtpath.path_ea, main);
		main->ps.param_count++;
		return (EXIT_SUCCESS);
	}
	else if (ft_strncmp(buf + i, PARAM_WE, ft_strlen(PARAM_WE)) == 0)
	{
		ft_getpath_texture(buf + (i + ft_strlen(PARAM_WE)), \
											main->ps.txtpath.path_we, main);
		main->ps.param_count++;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	ft_pars_headerfile_no_so(char *buf, int i, t_main *main)
{
	if (ft_strncmp(buf + i, PARAM_NO, ft_strlen(PARAM_NO)) == 0)
	{
		ft_getpath_texture(buf + (i + ft_strlen(PARAM_NO)), \
											main->ps.txtpath.path_no, main);
		main->ps.param_count++;
		return (EXIT_SUCCESS);
	}
	else if (ft_strncmp(buf + i, PARAM_SO, ft_strlen(PARAM_SO)) == 0)
	{
		ft_getpath_texture(buf + (i + ft_strlen(PARAM_SO)), \
											main->ps.txtpath.path_so, main);
		main->ps.param_count++;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	ft_pars_headerfile_c_f(char *buf, int i, t_main *main)
{
	if (ft_strncmp(buf + i, PARAM_C, ft_strlen(PARAM_C)) == 0)
	{
		if (!ft_isspace(buf[i + 1]))
			ft_err_display_and_exit(ERR_PARAM_INVALID, main);
		else if (main->ps.c_isalreadyset == 1)
			ft_err_display_and_exit(ERR_PARAM_DUPLICATED, main);
		main->gm.c_rgb = ft_get_rgb_value(buf + (i + 1), main);
		ft_pars_check_range_rgb(main->gm.c_rgb, main);
		main->ps.c_isalreadyset = 1;
		main->ps.param_count++;
		return (EXIT_SUCCESS);
	}
	else if (ft_strncmp(buf + i, PARAM_F, ft_strlen(PARAM_F)) == 0)
	{
		if (!ft_isspace(buf[i + 1]))
			ft_err_display_and_exit(ERR_PARAM_INVALID, main);
		else if (main->ps.f_isalreadyset == 1)
			ft_err_display_and_exit(ERR_PARAM_DUPLICATED, main);
		main->gm.f_rgb = ft_get_rgb_value(buf + (i + 1), main);
		ft_pars_check_range_rgb(main->gm.f_rgb, main);
		main->ps.f_isalreadyset = 1;
		main->ps.param_count++;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
