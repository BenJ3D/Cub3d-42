/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:11:48 by abucia            #+#    #+#             */
/*   Updated: 2022/11/26 08:11:48 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

float	rad_to_deg(float i_rad)
{
	return (180 * i_rad / MY_PI);
}

float	deg_to_rad(float i_deg)
{
	return (180 * i_deg / MY_PI);
}