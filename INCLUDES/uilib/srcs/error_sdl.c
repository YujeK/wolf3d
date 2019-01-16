/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_sdl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:10:41 by sklepper          #+#    #+#             */
/*   Updated: 2019/01/10 17:27:29 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include "libui.h"
#include "libft.h"

void	error_sdl(t_sdl *sdl)
{
	ft_putstr("Erreur SDL_Init : ");
	ft_putstr(SDL_GetError());
	if (sdl->renderer != NULL)
		SDL_DestroyRenderer(sdl->renderer);
	if (sdl->win != NULL)
		SDL_DestroyWindow(sdl->win);
	SDL_Quit();
	exit(-1);
}
