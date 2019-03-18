/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 10:18:59 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/18 20:21:21 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_reframe(t_env *env)
{
	t_thrd			thrd[NB_THRD];
	SDL_Texture		*texture;
	SDL_Rect		rect;
	int				i;

	SDL_RenderClear(env->sdl.renderer);
	i = 0;
	while (i < NB_THRD)
	{
		thrd[i].env = env;
		thrd[i].start = i;
		pthread_create(&(thrd[i].th), NULL, ft_raycasting, (void *)&(thrd[i]));
		i++;
	}
	i = 0;
	while (i < NB_THRD)
	{
		pthread_join(thrd[i].th, NULL);
		i++;
	}
	//ft_minimap(env);
	//ft_set_player_dir(env);
	ft_crosshair(env);
	ft_ui(env);
	texture = SDL_CreateTextureFromSurface(env->sdl.renderer, env->surface);
	SDL_RenderCopy(env->sdl.renderer, texture, 0, 0);
	rect = (SDL_Rect){0, 0, 60, 30};
	SDL_DestroyTexture(texture);
	SDL_RenderPresent(env->sdl.renderer);
}

void	ft_wolf_loop(t_env *env)
{
	ft_reframe(env);
	while (1)
	{
		SDL_GetRelativeMouseState(&(env->mouse_x), &(env->mouse_y));
		SDL_PollEvent(&(env->sdl.event));
		if (events(env))
			ft_reframe(env);
	}
}
