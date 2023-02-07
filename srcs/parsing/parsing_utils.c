/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2023/02/05 12:56:47 by bducrocq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_pars_check_has_chars(char c, char *legalchars, t_main *main)
{
	int		i;

	if (!legalchars)
	{
		perror("malloc");
		ft_err_display_and_exit(errno, main);
	}
	if (!c)
		return (EXIT_FAILURE);
	i = 0;
	while (legalchars[i])
	{
		if (c == legalchars[i] || ft_isspace_no_nl(c))
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

/**
 * @brief is valid file, return fd
 * else perror and return -1
 * 
 * @param main 
 * @return int fd
 */
int	ft_pars_openfile(const char *path)
{
	int		fd;
	char	*errline;

	fd = open(path, O_RDONLY);
	if (fd < 3)
	{
		errline = ft_strjoin("Error\nopen : ", path);
		perror(errline);
		free (errline);
		return (-1);
	}
	return (fd);
}

/**
 * @brief return 0 if path extension is == typefile
 * 
 * @param str 
 * @param filetype enter ".type"
 * @return int 
 */
int	ft_pars_check_type_file(const char *path, const char *filetype)
{
	int	i;
	int	y;

	i = ft_strlen(path) - 1;
	y = ft_strlen(filetype) - 1;
	while (ft_isspace(path[i]) != 0)
		i--;
	while (y >= 0)
	{
		if (filetype[y] != path[i])
			return (1);
		i--;
		y--;
	}
	return (0);
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
	t_vector	vec;

	ft_bzero(&vec, sizeof(t_vector));
	while (vec.s < 3)
	{
		vec.tmp = ft_get_next_word_custom_i(buf, &vec.i, main);
		if (ft_str_has_only_digit(vec.tmp))
			ft_err_rgb(ERR_PARAM_INVALID, vec.tmp, main);
		if (ft_str_has_only_digit(vec.tmp) || ft_strlen(vec.tmp) > 4)
			ft_err_rgb(ERR_PARAM_TO_HIGH, vec.tmp, main);
		if (vec.s == 0)
			vec.x = ft_atoi(vec.tmp);
		else if (vec.s == 1)
			vec.y = ft_atoi(vec.tmp);
		else if (vec.s == 2)
			vec.z = ft_atoi(vec.tmp);
		vec.s++;
		free(vec.tmp);
		vec.tmp = ft_get_next_word_custom_i(buf, &vec.i, main);
		if ((vec.s < 3 && ft_strncmp(vec.tmp, ",", 2)) \
									|| (vec.s >= 3 && vec.tmp[0] != '\0'))
			ft_err_rgb(ERR_PARAM_INVALID, vec.tmp, main);
		free (vec.tmp);
	}
	return (vec);
}
