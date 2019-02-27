/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loopedthings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 10:18:59 by asamir-k          #+#    #+#             */
/*   Updated: 2019/02/27 16:59:31 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/wolf3d.h"
#include <time.h>

void	ft_reframe(t_env *env)
{
	SDL_Texture		*texture;
	SDL_Rect		rect;

	rect = (SDL_Rect){0, 0, 60, 30};
	SDL_RenderClear(env->sdl.renderer);
//	ft_display_player(env);
//	ft_set_player_dir(env);
	texture = SDL_CreateTextureFromSurface(env->sdl.renderer, env->surface);
	SDL_RenderCopy(env->sdl.renderer, texture, NULL, NULL);
	ft_set_string(rect, ft_itoa(env->player.dir_d), ft_hex_to_rgb(WHITE), env);
//	fpscount(env);
	SDL_DestroyTexture(texture);
	SDL_RenderPresent(env->sdl.renderer);
}

void	ft_looped(int *quit, t_env *env)
{
	ft_reframe(env);
	while (!*quit)
	{
		if (SDL_PollEvent(&(env->sdl.event)) == 1)
		{
			SDL_GetRelativeMouseState(&(env->mouse_x), &(env->mouse_y));
	//		env->last = clock();
			events(quit, env);// hook
			ft_raycasting(env);
			crosshair(env);
			ft_reframe(env);
		}
	}
}
