/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosshair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:03:06 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/09 19:53:47 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void    crosshair(t_env *env)
{
    t_point pt1;
    t_point pt2;

    pt1.x = XDIM / 2 - 1;
    pt1.y = YDIM / 2 - 7;
    pt2.x = XDIM / 2 - 1;
    pt2.y = YDIM / 2 + 8;
    dl(env, pt1, pt2, BLACK);
    pt1.x = XDIM / 2 - 8;
    pt1.y = YDIM / 2;
    pt2.x = XDIM / 2 + 7;
    pt2.y = YDIM / 2;
    dl(env, pt1, pt2, BLACK);

}

void    fpscount(t_env *env)
{
	SDL_Rect		rect;
    int             fps;

	fps = 1000 / (clock() / 10000 - env->last / 10000);
	rect = (SDL_Rect){0, 740, 60, 30};
	ft_set_string(rect, ft_itoa((int)fps), ft_hex_to_rgb(WHITE), env);
}
