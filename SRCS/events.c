/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 10:22:21 by asamir-k          #+#    #+#             */
/*   Updated: 2019/01/14 17:05:16 by asamir-k         ###   ########.fr       */
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

void	quit_events(int *quit, t_sdl *sdl)
{
	if (sdl->event.type == SDL_QUIT)
		*quit = 1;
	else if (sdl->event.type == SDL_KEYDOWN)
		{
			if(sdl->event.key.keysym.sym == SDLK_ESCAPE)
				*quit = 1;
	}
}

void	display_events(t_sdl *sdl)
{
	if(sdl->event.type == SDL_KEYUP)
	{
		if (sdl->event.key.keysym.sym == SDLK_b)
			render_sdl(sdl, &give_blue, NULL);
		else if (sdl->event.key.keysym.sym == SDLK_g)
			render_sdl(sdl, &give_green, NULL);
	}
}

void	kb_events(int *quit, t_sdl *sdl)
{
	display_events(sdl);
	quit_events(quit, sdl);
}

void	events(int *quit, t_sdl *sdl)
{
	kb_events(quit, sdl);
}
