/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 03:24:03 by nihuynh           #+#    #+#             */
/*   Updated: 2018/12/04 03:34:52 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void	color_mult(t_color *color, t_color *mult)
{
	color->r *= (float)mult->r / 255;
	color->g *= (float)mult->g / 255;
	color->b *= (float)mult->b / 255;
}
