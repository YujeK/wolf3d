/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:36:41 by asamir-k          #+#    #+#             */
/*   Updated: 2019/02/27 11:15:49 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/wolf3d.h"

void			ft_loadtexture(t_env *env)
{
	env->north_tex = IMG_Load("RESSOURCES/pics/wood.png");
	env->east_tex = IMG_Load("RESSOURCES/pics/bluestone.png");
	env->west_tex = IMG_Load("RESSOURCES/pics/purplestone.png");
	env->south_tex = IMG_Load("RESSOURCES/pics/greystone.png");
}

SDL_Color		ft_hex_to_rgb(int hexa)
{
	SDL_Color color;

	color.r = hexa >> 24;
	color.g = hexa >> 16;
	color.b = hexa >> 8;
	color.a = hexa;
	return (color);
}

void		ft_setpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
	int			bpp;
	Uint8		*p;

	bpp = surface->format->BytesPerPixel;
	p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	(bpp == 1) ? *p = pixel : 0;
	(bpp == 2) ? *(Uint16 *)p = pixel : 0;
	(bpp == 4) ? *(Uint32 *)p = pixel : 0;
	if (bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
		{
			p[0] = (pixel >> 16) & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = pixel & 0xff;
		}
		else
		{
			p[0] = pixel & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = (pixel >> 16) & 0xff;
		}
	}
}

void			ft_set_string(SDL_Rect rect, char *text, SDL_Color color, t_env *env)
{
	SDL_Surface			*surface;
	SDL_Texture			*texture;

	surface = TTF_RenderText_Blended(env->font, text, color);
	rect.w = (rect.h * surface->w) / surface->h;
	texture = SDL_CreateTextureFromSurface(env->sdl.renderer, surface);
	SDL_RenderCopy(env->sdl.renderer, texture, NULL, &(rect));
	SDL_DestroyTexture(texture);
}
