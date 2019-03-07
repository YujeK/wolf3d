/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_surface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 22:15:19 by badhont           #+#    #+#             */
/*   Updated: 2019/03/07 22:41:28 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/wolf3d.h"

SDL_Surface      *ft_new_surface(int height, int width, t_env *env)
{
	SDL_Surface     *surface;
	Uint32          color[4];

	color[0] = 0x000000ff;
	color[1] = 0x0000ff00;
	color[2] = 0x00ff0000;
	color[3] = 0xff000000;
	if (!(surface = SDL_CreateRGBSurface(
	0, width, height, 32, color[0], color[1], color[2], color[3])))
		ft_error_exit("Wolf3d: Can't create SDL_Surface.", env);
	return (surface);
}