/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displayplayer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:07:38 by asamir-k          #+#    #+#             */
/*   Updated: 2019/01/17 18:46:36 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/wolf3d.h"
void    fillrect(t_env *env, int posx, int posy, int color)
{

    int     rectx;
    int     recty;
    int     x;
    int     y;

    recty = YDIM / env->map_height * (posy + 1);
    rectx = XDIM / env->map_width * (posx + 1);
    y = YDIM / env->map_height * posy;
    while(y < recty)
    {
        x = XDIM / env->map_width * posx;
        while(x < rectx)
        {
            putcolor_sdl(&env->sdl, color, x, y);
            x++;
        }
    y++;
    }
}

void    ft_display_player(t_env *env)
{

    int x;
    int y;

    y = 0;
    while(y < env->map_height)
    {
        x = 0;
        while(x < env->map_width)
        {
            if (env->map[y][x] == 0)
                    fillrect(env, x, y, WHITE);
            if (env->map[y][x] == 2)
                    fillrect(env, x, y, GREEN);
            if (env->map[y][x] == 1)
                    fillrect(env, x, y, RED);
            x++;
        }
        y++;
    }
}
