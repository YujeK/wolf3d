/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 10:18:59 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/09 19:55:50 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/wolf3d.h"

void	ft_reframe(t_env *env)
{
	SDL_Texture		*texture;
	SDL_Rect		rect;

	SDL_RenderClear(env->sdl.renderer);
	texture = SDL_CreateTextureFromSurface(env->sdl.renderer, env->surface);
	SDL_RenderCopy(env->sdl.renderer, texture, 0, 0);
	rect = (SDL_Rect){0, 0, 60, 30};
	ft_set_string(rect, ft_itoa(env->player.dir_d), ft_hex_to_rgb(WHITE), env);
	SDL_DestroyTexture(texture);
	SDL_RenderPresent(env->sdl.renderer);
}

void	ft_wolf_loop(t_env *env)
{
	// make frame
	ft_raycasting(env);
	ft_minimap(env);
	ft_set_player_dir(env);
	crosshair(env);
	ft_reframe(env);
	while (1)
	{
		SDL_GetRelativeMouseState(&(env->mouse_x), &(env->mouse_y));
		SDL_PollEvent(&(env->sdl.event));
		if (events(env))
		{
			// calcul des pixels a afficher
			ft_raycasting(env);
			ft_minimap(env);
			ft_set_player_dir(env);
			crosshair(env);
			// make frame
			ft_reframe(env);

		}
	}
}
