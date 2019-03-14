/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 10:22:21 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/14 19:08:22 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		keyboard(Uint8 *state, t_env *env)
{
	t_point		step;
	t_point		pos;
	int			change;

	change = 0;
	if (env->sdl.event.type == SDL_QUIT || state[SDL_SCANCODE_ESCAPE])
		ft_exit(env);
	if (state[SDL_SCANCODE_W])
	{
		step.x = -cos(env->player.dir_d * M_PI / 180) * 0.1;
		step.y = -sin(env->player.dir_d * M_PI / 180) * 0.1;
		env->player.pos.x += step.x;
		env->player.pos.y += step.y;
		pos.x = env->player.pos.x * env->bloc_size;
		pos.y = env->player.pos.y * env->bloc_size;
		if (ft_is_in_wall(env, pos))
		{
			env->player.pos.x -= step.x;
			env->player.pos.y -= step.y;
		}
		change = 1;
	}
	if (state[SDL_SCANCODE_S])
	{
		step.x = -cos(env->player.dir_d * M_PI / 180) * 0.1;
		step.y = -sin(env->player.dir_d * M_PI / 180) * 0.1;
		env->player.pos.x -= step.x;
		env->player.pos.y -= step.y;
		pos.x = env->player.pos.x * env->bloc_size;
		pos.y = env->player.pos.y * env->bloc_size;
		if (ft_is_in_wall(env, pos))
		{
			env->player.pos.x += step.x;
			env->player.pos.y += step.y;
		}
		change = 1;
	}
	if (state[SDL_SCANCODE_A])
	{
		step.x = -cos((env->player.dir_d + 90) * M_PI / 180) * 0.1;
		step.y = -sin((env->player.dir_d + 90) * M_PI / 180) * 0.1;
		env->player.pos.x += step.x;
		env->player.pos.y += step.y;
		pos.x = env->player.pos.x * env->bloc_size;
		pos.y = env->player.pos.y * env->bloc_size;
		if (ft_is_in_wall(env, pos))
		{
			env->player.pos.x -= step.x;
			env->player.pos.y -= step.y;
		}
		change = 1;
	}
	if (state[SDL_SCANCODE_D])
	{
		step.x = -cos((env->player.dir_d - 90) * M_PI / 180) * 0.1;
		step.y = -sin((env->player.dir_d - 90) * M_PI / 180) * 0.1;
		env->player.pos.x += step.x;
		env->player.pos.y += step.y;
		pos.x = env->player.pos.x * env->bloc_size;
		pos.y = env->player.pos.y * env->bloc_size;
		if (ft_is_in_wall(env, pos))
		{
			env->player.pos.x -= step.x;
			env->player.pos.y -= step.y;
		}
		change = 1;
	}
	return (change);
}

int		mouse_event(t_env *env)
{
	int change;

	if (env->mouse_x)
	{
		env->player.dir_d -= env->mouse_x / 6;
		if (env->player.dir_d > 360)
			env->player.dir_d -= 360;
		else if (env->player.dir_d < 0)
			env->player.dir_d = 360 - env->player.dir_d;
		change = 1;
	}
	if (env->sdl.event.type == SDL_MOUSEBUTTONDOWN)
	{
		//if (no sound playing)
			if ((Mix_Playing(0)) == 0)
				Mix_PlayChannel(0, env->widow_rifle, 0); // protect
		env->weapon_state = (env->weapon_state) ? 0 : 1;
		env->player.ammo += (env->player.ammo > 0) ? -1 : 100;
		change = 1;
	}
	if (env->sdl.event.type == SDL_MOUSEBUTTONUP)
	{
		Mix_HaltChannel(0);
		env->weapon_state = 0;
		change = 1;
	}
	return (change);
}


int		events(t_env *env)
{
	int			change;
	Uint8		*state;

	change = 0;
	state = (Uint8 *)SDL_GetKeyboardState(0);
	SDL_GetRelativeMouseState(&(env->mouse_x), &(env->mouse_y));
	SDL_PollEvent(&(env->sdl.event));
	(keyboard(state, env) ? change = 1 : 0);
	(mouse_event(env) ? change = 1 : 0);
	if (env->sdl.event.type == SDL_KEYDOWN)
	{
		if (env->sdl.event.key.keysym.sym == SDLK_p)
			if (env->bloc_size < 540)
				env->bloc_size += 30;
		if (env->sdl.event.key.keysym.sym == SDLK_o)
			if (env->bloc_size > 10)
				env->bloc_size -= 30;
		if (env->sdl.event.key.keysym.sym == SDLK_l)
		{
			env->tex.which_tex = 1;
			ft_loadtexture(env);
		}
		if (env->sdl.event.key.keysym.sym == SDLK_k)
		{
			env->tex.which_tex = 0;
			ft_loadtexture(env);
		}
	}
	return (change);
}
