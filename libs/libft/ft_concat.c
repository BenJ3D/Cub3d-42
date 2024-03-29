/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 02:27:47 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/21 00:42:55 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief src is free after use
 * 
 * @param src 
 * @param c 
 * @return char* 
 */
char	*ft_concat_char(char *src, char c)
{
	char	*tmpline;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!src)
		src = ft_strdup("");
	tmpline = ft_calloc((ft_strlen(src) + 2), sizeof(char));
	while (src[i])
		tmpline[y++] = src[i++];
	tmpline[y++] = c;
	tmpline[y] = '\0';
	free(src);
	return (tmpline);
}

/**
 * @brief Concat str = joint two str !!and free src!!
 * 
 * @param src 
 * @param str 
 * @return char* 
 */
char	*ft_concat_str(char *src, char *str)
{
	char	*tmpline;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!src)
		src = ft_strdup("");
	else if (!str)
		src = ft_strdup("");
	tmpline = ft_calloc((ft_strlen(src) + ft_strlen(str) + 1), sizeof(char));
	while (src[i])
		tmpline[y++] = src[i++];
	while (*str)
		tmpline[y++] = *str++;
	free(src);
	tmpline[y] = '\0';
	return (tmpline);
}
