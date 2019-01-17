/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loopedthings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 10:18:59 by asamir-k          #+#    #+#             */
/*   Updated: 2019/01/17 19:37:15 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/wolf3d.h"

void	ft_looped(int *quit, t_env *env)
{
    ft_display_player(env);
    SDL_RenderPresent(env->sdl.renderer);
	while (!*quit)
	{
		if (SDL_PollEvent(&(env->sdl.event)) == 1)
		{
			events(quit, env);
            ft_display_player(env);
            SDL_RenderPresent(env->sdl.renderer);
		}
	}
}
