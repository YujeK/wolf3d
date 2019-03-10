/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crosshair.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:03:06 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/10 18:33:59 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_crosshair(t_env *env)
{
	t_point pt1;
	t_point pt2;

	pt1.x = XDIM / 2 - 1;
	pt1.y = YDIM / 2 - 7;
	pt2.x = XDIM / 2 - 1;
	pt2.y = YDIM / 2 + 8;
	dl(env, pt1, pt2, PINK);
	pt1.x = XDIM / 2 - 8;
	pt1.y = YDIM / 2;
	pt2.x = XDIM / 2 + 7;
	pt2.y = YDIM / 2;
	dl(env, pt1, pt2, PINK);
}
