/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scalar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 03:28:16 by nihuynh           #+#    #+#             */
/*   Updated: 2019/01/10 17:33:39 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "libft.h"

void	color_scalar(t_color *color, float k)
{
	color->r = (uint8_t)ft_clamp(color->r * k, 0, 255);
	color->g = (uint8_t)ft_clamp(color->g * k, 0, 255);
	color->b = (uint8_t)ft_clamp(color->b * k, 0, 255);
}
