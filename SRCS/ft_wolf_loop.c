/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 10:18:59 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/10 18:10:31 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_reframe(t_env *env)
{
	SDL_Texture		*texture;
	SDL_Rect		rect;

	SDL_RenderClear(env->sdl.renderer);
	ft_raycasting(env);
	//ft_minimap(env);
	//ft_set_player_dir(env);
	ft_crosshair(env);
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
		SDL_FlushEvent(SDL_KEYDOWN | SDL_MOUSEMOTION);
	}
}
