/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 03:26:10 by nihuynh           #+#    #+#             */
/*   Updated: 2019/01/10 17:35:39 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "libft.h"

void	color_add(t_color *color, t_color *add)
{
	color->r = (uint8_t)ft_clamp(color->r + add->r, 0, 255);
	color->g = (uint8_t)ft_clamp(color->g + add->g, 0, 255);
	color->b = (uint8_t)ft_clamp(color->b + add->b, 0, 255);
}
