/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:00:24 by sklepper          #+#    #+#             */
/*   Updated: 2018/12/20 18:21:31 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include "libft.h"
#include "libui.h"

int		init_sdl(t_sdl *sdl, int width, int height)
{
	ft_bzero(sdl, sizeof(t_sdl));
	sdl->width_vp = width;
	sdl->height_vp = height;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		error_sdl(sdl);
	if (SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN,
			&sdl->win, &sdl->renderer) != 0)
		error_sdl(sdl);
	while (SDL_PollEvent(&sdl->event))
		;
	return (0);
}
