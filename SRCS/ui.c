/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 23:42:09 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/10 23:49:42 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

SDL_Color		ft_hex_to_rgb(int hexa)
{
	SDL_Color color;

	color.r = hexa >> 24;
	color.g = hexa >> 16;
	color.b = hexa >> 8;
	color.a = hexa;
	return (color);
}

void	ft_value_display()
{
	SDL_Rect		rect;
	rect = (SDL_Rect){0, 0, 60, 30};
	ft_set_string(rect, ft_itoa(env->player.dir_d), ft_hex_to_rgb(WHITE), env);
}

int		ft_ui()
{
	ft_value_display();
	ft_value_design();
}
