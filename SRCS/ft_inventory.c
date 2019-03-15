/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inventory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 01:39:25 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/15 03:45:59 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_inventory(t_env *env)
{
	SDL_Rect	rect;
	SDL_Surface	*inventory;

		inventory = (env->inv_state == 1) ? env->tex.bag : env->tex.lil_bag;
		if (env->inv_state == 0)
		{
			rect = (SDL_Rect){0, 850, 150, 150};
			SDL_BlitScaled(inventory, 0, env->surface, &rect);
			rect = (SDL_Rect){50, 870, 15, 20};
			ft_set_string(rect, "Inventory", ft_hex_to_rgb(GREEN), env);
		}
		else
		{
			rect = (SDL_Rect){0, 200, 700, 400};
			SDL_BlitScaled(inventory, 0, env->surface, &rect);
		}
}
