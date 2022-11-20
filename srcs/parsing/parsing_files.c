/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/20 01:02:22 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief is valid file, return fd
 * else perror and return -1
 * 
 * @param db 
 * @return int fd
 */
int	ft_pars_openfile(char *path)
{
	int		fd;
	char	*errline;
	
	fd = open(path, O_WRONLY);
	if (fd < 3)
	{
		errline = ft_strjoin("open : ", path);
		perror("open");
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
int	ft_pars_check_type_file(char *path, char *filetype) 	
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