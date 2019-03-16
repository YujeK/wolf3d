/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inventory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 01:39:25 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/16 04:15:48 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
int			ft_is_in(t_env *env, int x1, int x2, int y1, int y2)
{
	int posx;
	int	posy;
	SDL_GetMouseState(&(env->realm_x), &(env->realm_y));
	posx = env->realm_x;
	posy = env->realm_y;
	if (posx > x1 && posx < x2 && posy > y1 && posy < y2)
			return (1);
	return (0);
}

int			ft_mouse_inventory(t_env *env, int change)
{
	if (env->sdl.event.type == SDL_MOUSEBUTTONDOWN && ft_is_in(env, 450, 600, 350, 450) == 1)
	{
		if (env->weapon_state == 0 || env->weapon_state == 1)
			env->weapon_state = 2;
		else
			env->weapon_state = 0;
		change = 1;
					ft_reframe(env);
	}
	if (env->sdl.event.type == SDL_MOUSEBUTTONDOWN && ft_is_in(env, 275, 425, 460, 550) == 1)
	{
		if (env->tex.which_tex == 1)
			env->tex.which_tex = 0;
		else
		env->tex.which_tex = 1;
		ft_loadtexture(env);
		change = 1;
	}
	if (env->sdl.event.type == SDL_MOUSEBUTTONDOWN && ft_is_in(env, 275, 425, 350, 450) == 1)
	{
		if(Mix_PlayingMusic() == 0)
			Mix_PlayMusic(env->plage, -1);
		if(Mix_PausedMusic() == 1)
			Mix_ResumeMusic();
		else
			Mix_PauseMusic();
		change = 1;
	}
	if (env->sdl.event.type == SDL_MOUSEBUTTONDOWN && ft_is_in(env, 275, 425, 245, 340) == 1)
	{
		env->tex.which_tex = 2;
		ft_loadtexture(env);
		change = 1;
	}
	return (change);
}

void		ft_inventory(t_env *env)
{
	SDL_Rect	rect;
	SDL_Surface	*inventory;

		inventory = (env->inv_state == 1) ? env->tex.bag : env->tex.lil_bag;
		if (env->inv_state == 0)
		{
			if (SDL_SetRelativeMouseMode(TRUE) < 0)
			ft_error_exit("Wolf3d: Unable to set relative mode", env);
			rect = (SDL_Rect){0, 850, 150, 150};
			SDL_BlitScaled(inventory, 0, env->surface, &rect);
			rect = (SDL_Rect){50, 870, 15, 20};
			ft_set_string(rect, "Inventory", ft_hex_to_rgb(GREEN), env);
		}
		else
		{
			if (SDL_SetRelativeMouseMode(FALSE) < 0)
		ft_error_exit("Wolf3d: Unable to set relative mode", env);
			rect = (SDL_Rect){0, 200, 700, 400};
			SDL_BlitScaled(inventory, 0, env->surface, &rect);
		}
}
