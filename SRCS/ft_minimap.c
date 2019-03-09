/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:07:38 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/09 23:12:17 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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

	a.x = env->player.pos.y * env->bloc_size * env->coef_minimap;
	a.y = env->player.pos.x * env->bloc_size * env->coef_minimap;
	b.x = (env->player.pos.y + step.y) * env->bloc_size * env->coef_minimap;
	b.y = (env->player.pos.x + step.x) * env->bloc_size * env->coef_minimap;
	dl(env, a, b, PINK);
}

void	ft_set_player_dir(t_env *env)
{
	ft_dl_angle(env, 2, (env->player.dir_d - 30));
	ft_dl_angle(env, 2, (env->player.dir_d));
	ft_dl_angle(env, 2, (env->player.dir_d + 30));
}

void	ft_minimap(t_env *env)
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
			rect = (SDL_Rect){x * env->bloc_size * env->coef_minimap, y * env->bloc_size * env->coef_minimap,
			env->bloc_size * env->coef_minimap, env->bloc_size * env->coef_minimap};
			if (env->map[y][x] == 0 || env->map[y][x] == 2)
				fillrect(env, rect, WHITE);
			if (env->map[y][x] == 1)
				fillrect(env, rect, GREY);
			x++;
		}
		y++;
	}
}
