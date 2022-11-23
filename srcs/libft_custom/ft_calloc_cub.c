/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:00:07 by bducrocq          #+#    #+#             */
/*   Updated: 2022/11/23 14:16:46 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief custom ft_calloc for cub, perror + ft_free_all_and_exit_err if malloc
 * fail
 * @param count 
 * @param size 
 * @param main 
 * @return void* 
 */
void	*ft_calloc_cub(size_t count, size_t size, t_main *main)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
	{
		perror("malloc");
		ft_free_all_and_exit_err(main, errno);
	}
	ft_bzero(ptr, size * count);
	return (ptr);
}
