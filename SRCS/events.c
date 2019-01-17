/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 10:22:21 by asamir-k          #+#    #+#             */
/*   Updated: 2019/01/17 20:01:04 by asamir-k         ###   ########.fr       */
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
	if(env->sdl.event.type == SDL_KEYUP)
	{
		if (env->sdl.event.key.keysym.sym == SDLK_d)
		{
			ft_swap(&env->map[env->player.position.y][env->player.position.x] , &env->map[env->player.position.y][env->player.position.x + 1]);
			env->player.position.x++;
			ft_print_map(env);
		}
		if (env->sdl.event.key.keysym.sym == SDLK_a)
		{
			ft_swap(&env->map[env->player.position.y][env->player.position.x] , &env->map[env->player.position.y][env->player.position.x - 1]);
			env->player.position.x--;
			ft_print_map(env);
		}
		if (env->sdl.event.key.keysym.sym == SDLK_s)
		{
			ft_swap(&env->map[env->player.position.y][env->player.position.x] , &env->map[env->player.position.y + 1][env->player.position.x]);
			env->player.position.y++;
			ft_print_map(env);
		}
		if (env->sdl.event.key.keysym.sym == SDLK_w)
		{
			ft_swap(&env->map[env->player.position.y][env->player.position.x] , &env->map[env->player.position.y - 1][env->player.position.x]);
			env->player.position.y--;
			ft_print_map(env);
		}
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
