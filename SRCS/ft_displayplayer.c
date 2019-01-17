/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displayplayer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:07:38 by asamir-k          #+#    #+#             */
/*   Updated: 2019/01/17 23:50:58 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/wolf3d.h"
void    fillrect(t_env *env, double posx, double posy, int color)
{

	double     rectx;
	double     recty;
	double     x;
	double     y;

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

void	ft_set_player_dir(t_env *env)
{
	int		x;
	int		y;
	x = XDIM / env->map_width * (env->player.position.x) + env->posx;
	y = YDIM / env->map_height * (env->player.position.y) + env->posy;
	t_point	pt[2];
	pt[0].x = x + (XDIM / env->map_width / 2);
	pt[0].y = y + (YDIM / env->map_height / 2);
	pt[1].x = x + (XDIM / env->map_width / 2);
	pt[1].y = 0;
	dl(env,	pt[0], pt[1], RED);
	pt[0].x = x + (XDIM / env->map_width / 2);
	pt[0].y = y + (YDIM / env->map_height / 2);
	pt[1].x = x + (XDIM / env->map_width / 2)  - (sin(PI / 6) * (y));
	pt[1].y = 0;
	dl(env,	pt[0], pt[1], RED);
	pt[0].x = x + (XDIM / env->map_width / 2);
	pt[0].y = y + (YDIM / env->map_height / 2);
	pt[1].x = x + (XDIM / env->map_width / 2) + (sin(PI / 6) * (y));
	pt[1].y = 0;
	dl(env,	pt[0], pt[1], RED);
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
					fillrect(env, x, y, BROWN);
			x++;
		}
		y++;
	}
}
