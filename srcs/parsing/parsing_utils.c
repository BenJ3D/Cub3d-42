/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/12/07 13:24:25 by bducrocq         ###   ########.fr       */
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
	while(legalchars[i])
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