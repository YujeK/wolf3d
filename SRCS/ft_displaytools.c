/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaytools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:03:06 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/25 14:42:16 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double			ft_pythagore(double posx, double posy)
{
	return (sqrt(posx * posx + posy * posy));
}

int				rbw(int x)
{
	int			color;
	int			whichcolor;
	int			thiscolor;
	static int	rainbow[7] = {RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PURPLE};

	color = 0;
	whichcolor = (XDIM) / 7;
	thiscolor = 0;
	while (color < 6)
	{
		thiscolor = thiscolor + whichcolor;
		if (x <= thiscolor)
			return (rainbow[color]);
		color++;
	}
	return (rainbow[color]);
}

void			ft_crosshair(t_env *env)
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
