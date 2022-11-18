/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 02:44:28 by mal-guna          #+#    #+#             */
/*   Updated: 2022/11/18 01:50:22 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

enum e_errtype
{
	ERR_BASIC,
	ERR_NOARG,
	ERR_TOOMANYARG,
	ERR_WALL,
	ERR_MISSPLAYER,
	ERR_OTHER
};

typedef struct s_pars
{
	int		ac;
	char	**av;
}			t_pars;

typedef struct s_data
{
	t_pars	ps;
}			t_data;

#endif
