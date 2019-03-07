/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 10:22:21 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/08 00:01:00 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/wolf3d.h"

int		events(t_env *env)
{
	t_point	step;
	t_point pos;
	int		change;

	change = 0;
	if (env->sdl.event.type == SDL_QUIT
		|| env->sdl.event.key.keysym.sym == SDLK_ESCAPE)
		ft_exit(env);

	else if (env->sdl.event.type == SDL_KEYDOWN)
	{
		/*if (env->sdl.event.key.keysym.sym == SDLK_d)
			env->player.pos.x += 0.05;
		else if (env->sdl.event.key.keysym.sym == SDLK_LEFT)
			env->player.pos.x -= 0.05;*/
		if (env->sdl.event.key.keysym.sym == SDLK_w)
		{
			step.x = -cos(env->player.dir_d * M_PI / 180) * 0.1;
 			step.y = -sin(env->player.dir_d * M_PI / 180) * 0.1;
			env->player.pos.x += step.x;
			env->player.pos.y += step.y;
			pos.x = env->player.pos.x * BLOC_SIZE;
			pos.y = env->player.pos.y * BLOC_SIZE;
			if (ft_is_in_wall(env, pos))
			{
				env->player.pos.x -= step.x;
				env->player.pos.y -= step.y;
			}
			change = 1;
		}
		else if (env->sdl.event.key.keysym.sym == SDLK_s)
		{
			step.x = -cos(env->player.dir_d * M_PI / 180) * 0.1;
 			step.y = -sin(env->player.dir_d * M_PI / 180) * 0.1;
			env->player.pos.x -= step.x;
			env->player.pos.y -= step.y;
			pos.x = env->player.pos.x * BLOC_SIZE;
			pos.y = env->player.pos.y * BLOC_SIZE;
			if (ft_is_in_wall(env, pos))
			{
				env->player.pos.x += step.x;
				env->player.pos.y += step.y;
			}
			change = 1;
		}
		else if (env->sdl.event.key.keysym.sym == SDLK_a)
		{
			env->player.dir_d = (env->player.dir_d < 360) ? env->player.dir_d + 2 : 1;
			change = 1;
		}
		else if (env->sdl.event.key.keysym.sym == SDLK_d)
		{
			env->player.dir_d = (env->player.dir_d > 1) ? env->player.dir_d - 2 : 360;
			change = 1;
		}
		/*if(env->sdl.event.key.keysym.sym == SDLK_o)
			SDL_SetRelativeMouseMode(FALSE);
		if (env->sdl.event.key.keysym.sym == SDLK_p)
			SDL_SetRelativeMouseMode(TRUE);*/
	}

	if (env->sdl.event.type == SDL_MOUSEMOTION)
	{
		env->player.dir_d -= env->mouse_x / 6;
		if (env->player.dir_d > 360)
			env->player.dir_d -= 360;
		else if (env->player.dir_d < 0)
			env->player.dir_d = 360 - env->player.dir_d;
		change = 1;
	}

	return (change);
}
