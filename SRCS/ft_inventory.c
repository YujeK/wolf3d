/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inventory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 01:39:25 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/15 01:43:56 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inventory_init(t_env *env)
{
	rect = (SDL_Rect){XDIM / 3.5, 50, 1000, 1000};
	SDL_BlitScaled(inventory, 0, env->surface, &rect);
}

void		ft_inventory(t_env *env)
{

}
