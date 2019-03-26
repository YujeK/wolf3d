/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 10:22:21 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/25 13:27:40 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_calc_move(int relative_dir_d, t_env *env)
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

int		ft_movement(Uint8 *state, t_env *env)
{
	int		change;

	change = 0;
	if (state[SDL_SCANCODE_W])
		change = ft_calc_move(FORWARD, env);
	if (state[SDL_SCANCODE_S])
		change = ft_calc_move(BACKWARD, env);
	if (state[SDL_SCANCODE_D])
		change = ft_calc_move(LEFT, env);
	if (state[SDL_SCANCODE_A])
		change = ft_calc_move(RIGHT, env);
	return (change);
}

int		ft_shoot_event(t_env *env)
{
	int		change;

	change = 0;
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)
	&& env->weapon_state == 0 && env->inv_state == 0)
	{
		env->weapon_state = 1;
		env->player.ammo += (env->player.ammo > 0) ? -1 : 100;
		change = 1;
	}
	else if (env->weapon_state == 1)
	{
		env->weapon_state = 0;
		env->weapon = env->tex.widow_0;
		change = 1;
	}
	return (change);
}

int		ft_rotation_event(t_env *env)
{
	int change;

	change = 0;
	if (env->mouse_x && env->inv_state == 0)
	{
		env->player.dir_d -= env->mouse_x * MOUSE_SENS / 100;
		if (env->player.dir_d > 360)
			env->player.dir_d -= 360;
		else if (env->player.dir_d < 0)
			env->player.dir_d = 360 - env->player.dir_d;
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
	if (env->sdl.event.type == SDL_QUIT || state[SDL_SCANCODE_ESCAPE])
		ft_exit(env);
	(ft_rotation_event(env)) ? change = 1 : 0;
	(ft_movement(state, env)) ? change = 1 : 0;
	(ft_shoot_event(env)) ? change = 1 : 0;
	(env->weapon_state == 1) ? change = 1 : 0;
	(ft_inventory_event(env)) ? change = 1 : 0;
	(ft_inventory(env)) ? change = 1 : 0;
	(ft_click_inventory(env)) ? change = 1 : 0;
	return (change);
}
