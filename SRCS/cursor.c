/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 05:17:45 by asamir-k          #+#    #+#             */
/*   Updated: 2018/12/09 12:13:44 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/wolf3d.h"

void	cursor(t_env *env)
{
	mlx_pixel_put(env->mlx, env->win, XDIM / 2 - 4, YDIM / 2, WHITE);
	mlx_pixel_put(env->mlx, env->win, XDIM / 2 - 3, YDIM / 2, WHITE);
	mlx_pixel_put(env->mlx, env->win, XDIM / 2 - 2, YDIM / 2, WHITE);
	mlx_pixel_put(env->mlx, env->win, XDIM / 2 - 1, YDIM / 2, WHITE);
	mlx_pixel_put(env->mlx, env->win, XDIM / 2, YDIM / 2, WHITE);
	mlx_pixel_put(env->mlx, env->win, XDIM / 2 + 1, YDIM / 2, WHITE);
	mlx_pixel_put(env->mlx, env->win, XDIM / 2 + 2, YDIM / 2, WHITE);
	mlx_pixel_put(env->mlx, env->win, XDIM / 2 + 3, YDIM / 2, WHITE);
	mlx_pixel_put(env->mlx, env->win, XDIM / 2 + 4, YDIM / 2, WHITE);
	mlx_pixel_put(env->mlx, env->win, XDIM / 2, YDIM / 2 - 4, WHITE);
	mlx_pixel_put(env->mlx, env->win, XDIM / 2, YDIM / 2 - 3, WHITE);
	mlx_pixel_put(env->mlx, env->win, XDIM / 2, YDIM / 2 - 2, WHITE);
	mlx_pixel_put(env->mlx, env->win, XDIM / 2, YDIM / 2 - 1, WHITE);
	mlx_pixel_put(env->mlx, env->win, XDIM / 2, YDIM / 2 + 1, WHITE);
	mlx_pixel_put(env->mlx, env->win, XDIM / 2, YDIM / 2 + 2, WHITE);
	mlx_pixel_put(env->mlx, env->win, XDIM / 2, YDIM / 2 + 3, WHITE);
	mlx_pixel_put(env->mlx, env->win, XDIM / 2, YDIM / 2 + 4, WHITE);
}
