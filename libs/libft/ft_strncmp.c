/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:03:07 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/20 03:46:45 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char			*str1;
	char			*str2;
	size_t			i;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (n == 0)
		return (0);
	while ((str1[i] == str2[i]) && (str1[i] || str2[i]) && i < n - 1)
	{
		i++;
	}
	int ret = (unsigned char)str1[i] - (unsigned char)str2[i];
	printf("dbg strncmp %s / %s= %i\n", s1, s2, ret);
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
