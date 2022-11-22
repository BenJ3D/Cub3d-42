/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/22 04:33:33 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_pars_check_if_legal_char(char c)
{
	char	legal[] = LEGITCHAR;
	int		i;

	i = 0;
	while(legal[i])
	{
		if (c != legal[i])
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
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
		errline = ft_strjoin("open : ", path);
		perror(errline);
		free (errline);
		return (-1);
	}
	return (0);
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