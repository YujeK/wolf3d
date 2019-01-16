/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 02:39:43 by nihuynh           #+#    #+#             */
/*   Updated: 2019/01/16 18:48:15 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	loop_sdl(int *quit, t_sdl *sdl, t_looped ft_looped)
{
	while (!*quit)
	{
		if (SDL_PollEvent(&sdl->event) == 1)
		{
			ft_looped(quit, sdl);
		}
	}
}
