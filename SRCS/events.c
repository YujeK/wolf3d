/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 10:22:21 by asamir-k          #+#    #+#             */
/*   Updated: 2019/02/25 18:53:31 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/wolf3d.h"
#include "../INCLUDES/keymaps.h"

int		give_blue(int x, int y, void *arg)
{
	(void)x;
	(void)y;
	(void)arg;
	return (BLUE);
}
int		give_green(int x, int y, void *arg)
{
	(void)x;
	(void)y;
	(void)arg;
	return (GREEN);
}

void	quit_events(int *quit, t_env * env)
{
	if (env->sdl.event.type == SDL_QUIT)
		*quit = 1;
	else if (env->sdl.event.type == SDL_KEYDOWN)
		{
			if(env->sdl.event.key.keysym.sym == SDLK_ESCAPE)
				*quit = 1;
	}
}

void	player_events(t_env *env)
{
	t_point	step;
	t_point pos;

	if(env->sdl.event.type == SDL_KEYDOWN)
	{
		/*if (env->sdl.event.key.keysym.sym == SDLK_d)
			env->player.pos.x += 0.05;
		else if (env->sdl.event.key.keysym.sym == SDLK_LEFT)
			env->player.pos.x -= 0.05;*/
		if (env->sdl.event.key.keysym.sym == SDLK_UP)
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
		}
		else if (env->sdl.event.key.keysym.sym == SDLK_DOWN)
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
		}
		else if (env->sdl.event.key.keysym.sym == SDLK_RIGHT)
			env->player.dir_d = (env->player.dir_d < 360) ? env->player.dir_d + 2 : 1;
		else if (env->sdl.event.key.keysym.sym == SDLK_LEFT)
			env->player.dir_d = (env->player.dir_d > 1) ? env->player.dir_d - 2 : 360;
	}
}
void	display_events(t_env * env)
{
	if(env->sdl.event.type == SDL_KEYUP)
	{
		if (env->sdl.event.key.keysym.sym == SDLK_b)
			render_sdl(&env->sdl, &give_blue, NULL);
		else if (env->sdl.event.key.keysym.sym == SDLK_g)
			render_sdl(&env->sdl, &give_green, NULL);
	}
}

void	kb_events(int *quit, t_env *env)
{
	display_events(env);
	player_events(env);
	quit_events(quit, env);
}

void	events(int *quit, t_env * env)
{
	kb_events(quit, env);
}
