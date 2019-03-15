/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 10:22:21 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/15 20:42:27 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_movement(int relative_dir_d, t_env *env)
{
	t_point		step;
	t_point		pos;

	step.x = -cos((env->player.dir_d + relative_dir_d) * M_PI / 180) * 0.1;
	step.y = -sin((env->player.dir_d + relative_dir_d) * M_PI / 180) * 0.1;
	env->player.pos.x += step.x;
	env->player.pos.y += step.y;
	pos.x = env->player.pos.x * env->bloc_size;
	pos.y = env->player.pos.y * env->bloc_size;
	if (ft_is_in_wall(env, pos))
	{
		env->player.pos.x -= step.x;
		env->player.pos.y -= step.y;
	}
	return (1);
}

int		ft_text_and_res(t_env *env, int change, Uint8 *state)
{
	if (state[SDL_SCANCODE_I])
	{
		if(env->inv_state == 1)
			env->inv_state = 0;
		else
			env->inv_state = 1;
		change = 1;
	}
	if (state[SDL_SCANCODE_O])
		if (env->bloc_size > 10)
			env->bloc_size -= 30;
	if (state[SDL_SCANCODE_L])
	{
		env->tex.which_tex = 1;
		ft_loadtexture(env);
		change = 1;
	}
	if (state[SDL_SCANCODE_K])
	{
		env->tex.which_tex = 0;
		ft_loadtexture(env);
		change = 1;
	}
	return (change);
}


int		ft_keyboard(Uint8 *state, t_env *env)
{
	int		change;

	change = 0;
	if (env->sdl.event.type == SDL_QUIT || state[SDL_SCANCODE_ESCAPE])
		ft_exit(env);
	if (state[SDL_SCANCODE_W])
		change = ft_movement(FORWARD, env);
	if (state[SDL_SCANCODE_S])
		change = ft_movement(BACKWARD, env);
	if (state[SDL_SCANCODE_D])
		change = ft_movement(LEFT, env);
	if (state[SDL_SCANCODE_A])
		change = ft_movement(RIGHT, env);
	(ft_text_and_res(env, change, state) ? change = 1 : 0);
	return (change);
}

int		ft_mouse_event(t_env *env, int change)
{
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
		if ((Mix_Playing(0)) == 0)
			Mix_PlayChannel(0, env->widow_rifle, 0);
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
	(ft_keyboard(state, env) ? change = 1 : 0);
	(ft_mouse_event(env, change) ? change = 1 : 0);
	return (change);
}
