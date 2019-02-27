/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displayplayer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:07:38 by asamir-k          #+#    #+#             */
/*   Updated: 2019/02/26 14:50:05 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/wolf3d.h"

void	fillrect(t_env *env, SDL_Rect rect, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < rect.h)
	{
		x = 0;
		while (x < rect.w)
		{
			if (rect.x + x < 0 || rect.x + x > XDIM
			|| rect.y + y < 0 || rect.y + y > YDIM)
				break ;
			ft_setpixel(env->surface, rect.x + x, rect.y + y, color);
			x++;
		}
		y++;
	}
}

void	ft_dl_angle(t_env *env, double dist, double angle_d)
{
	t_point	step;
	t_point	a;
	t_point	b;

	step.x = -cos(angle_d * M_PI / 180) * dist;
 	step.y = -sin(angle_d * M_PI / 180) * dist;

	a.x = env->player.pos.x * BLOC_SIZE * env->coef_minimap;
	a.y = env->player.pos.y * BLOC_SIZE * env->coef_minimap;
	b.x = (env->player.pos.x + step.x) * BLOC_SIZE * env->coef_minimap;
	b.y = (env->player.pos.y + step.y) * BLOC_SIZE * env->coef_minimap;
	dl(env, a, b, RED);
}

void	ft_set_player_dir(t_env *env)
{
	ft_dl_angle(env, 2, env->player.dir_d);
	ft_dl_angle(env, 2, env->player.dir_d - 30);
	ft_dl_angle(env, 2, env->player.dir_d + 30);
}

void	ft_display_player(t_env *env)
{
	SDL_Rect	rect;
	int			x;
	int			y;

	y = 0;
	while (y < env->map_height)
	{
		x = 0;
		while (x < env->map_width)
		{
			rect = (SDL_Rect){x * BLOC_SIZE * env->coef_minimap, y * BLOC_SIZE * env->coef_minimap,
			BLOC_SIZE * env->coef_minimap, BLOC_SIZE * env->coef_minimap};
			if (env->map[y][x] == 0)
				fillrect(env, rect, WHITE);
			if (env->map[y][x] == 2)
				fillrect(env, rect, GREEN);
			if (env->map[y][x] == 1)
				fillrect(env, rect, BROWN);
			x++;
		}
		y++;
	}
}
