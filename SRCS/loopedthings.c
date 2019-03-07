/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loopedthings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 10:18:59 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/07 22:53:05 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/wolf3d.h"

void	ft_reframe(t_env *env)
{
	SDL_Texture		*texture;
	SDL_Rect		rect;

	rect = (SDL_Rect){0, 0, 60, 30};
	SDL_RenderClear(env->sdl.renderer);
	texture = SDL_CreateTextureFromSurface(env->sdl.renderer, env->surface);
	SDL_RenderCopy(env->sdl.renderer, texture, NULL, NULL);
	ft_set_string(rect, ft_itoa(env->player.dir_d), ft_hex_to_rgb(WHITE), env);
	SDL_DestroyTexture(texture);
	SDL_RenderPresent(env->sdl.renderer);
}

void	ft_looped(int *quit, t_env *env)
{
	// make frame
	ft_reframe(env);
	while (1)
	{
		if (SDL_PollEvent(&(env->sdl.event)) == 1)
		{
			SDL_GetRelativeMouseState(&(env->mouse_x), &(env->mouse_y));

			// gestion d'evenement
			events(quit, env);// hook

			// calcul des pixels a afficher
			ft_raycasting(env);
			ft_display_player(env);
			ft_set_player_dir(env);
			
			// make frame
			ft_reframe(env);

		}
	}
}
