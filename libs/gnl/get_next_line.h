/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:56:31 by bducrocq          #+#    #+#             */
/*   Updated: 2022/04/10 23:02:51 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char		*get_next_line(int fd);
void		ft_strjoin_gnl(char **dst, char *src1, char *src2, size_t buf_end);
int			ft_buf_process(char *bufp);
int			ft_strichr_nl(char *str);
char		*ft_strdup_gnl(const char *s1);
size_t		ft_strlen_gnl(const char *str);

#endif