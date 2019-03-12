/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:35:24 by badhont           #+#    #+#             */
/*   Updated: 2019/03/12 13:03:17 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

SDL_Surface		*ft_selectex(t_env *env)
{
	if (env->ray.side == 2)
	{
		if ((env->ray.direction >= 0 && env->ray.direction <= 180)
		|| env->ray.direction >= 360)
			return (env->tex.north);
		else
			return (env->tex.east);
	}
	if (env->ray.direction >= 90 && env->ray.direction <= 270)
		return (env->tex.south);
	return (env->tex.west);
}

Uint32			ft_texturing(t_env *env, int y, int p1, int p2)
{
	SDL_Surface	*surface;
	Uint32		color;
	int			w_tex;
	int			h_tex;
	int			x_tex;
	int			y_tex;
	int			ywall;

	ywall = y - p1;
	surface = ft_selectex(env);
	w_tex = surface->w;
	h_tex = surface->h;
	if (env->ray.side == 2)
		x_tex = ((int)env->ray.pos.x % env->bloc_size) * w_tex / env->bloc_size;
	else
		x_tex = ((int)env->ray.pos.y % env->bloc_size) * w_tex / env->bloc_size;
	y_tex = ywall * h_tex / (p2 - p1);
	color = ft_getpixel(surface, x_tex, y_tex, env);
	return (color);
}

void			ft_put_column(t_env *env, double wall_height, int x)
{
	int		p1;
	int		p2;
	int		y;

	y = 0;
	p1 = YDIM / 2 - wall_height / 2;
	p2 = YDIM - p1;
	while (y < YDIM)
	{
		if (y < p1)
			ft_setpixel(env->surface, XDIM - 1 - x, y, BLACK);
		else if (y >= p1 && y < p2)
			ft_setpixel(env->surface, XDIM - 1 - x, y, ft_texturing(env, y, p1, p2));
		if (y >= p2)
			ft_setpixel(env->surface, XDIM - 1 - x, y, 0x2F4F4FFF);
		y++;
	}
}

double			ft_pythagore(double posx, double posy)
{
	return (sqrt(posx * posx + posy * posy)); //retourne l'hypothenuse
}

int				ft_is_in_wall(t_env *env, t_point pos)
{
	if (pos.x < 0 || pos.x > env->map_width * env->bloc_size || pos.y < 0 || pos.y > env->map_height * env->bloc_size)
		return (1);
	if (env->map[(int)pos.x / env->bloc_size][(int)pos.y / env->bloc_size] == 1)
		return (1);
	return (0);
}

double			ft_cast_ray(t_env *env, double direction)
{
	t_point	step;
	t_point origin;
	double	alpha;

	step.x = -cos(direction * M_PI / 180) * 0.05;
	step.y = -sin(direction * M_PI / 180) * 0.05;
	env->ray.pos.x = env->player.pos.x * env->bloc_size;
	env->ray.pos.y = env->player.pos.y * env->bloc_size;
	origin = (t_point){env->ray.pos.x, env->ray.pos.y};
	while (env->ray.pos.x > 0 && env->ray.pos.x < env->map_width * env->bloc_size
	&& env->ray.pos.y > 0 && env->ray.pos.y < env->map_height * env->bloc_size)
	{
		env->ray.pos.x += step.x;
		if (ft_is_in_wall(env, env->ray.pos))
		{
			env->ray_pos.x = env->ray.pos.x;
			env->ray.side = 1;
			alpha = fabs((env->player.dir_d - direction) * (M_PI / 180));
			return (ft_pythagore(env->ray.pos.x - origin.x,
			env->ray.pos.y - origin.y) * cos(alpha));
		}
		env->ray.pos.y += step.y;
		if (ft_is_in_wall(env, env->ray.pos))
		{
			env->ray_pos.y = env->ray.pos.y;
			env->ray.side = 2;
			alpha = fabs((env->player.dir_d - direction) * (M_PI / 180));
			return (ft_pythagore(env->ray.pos.x - origin.x,
			env->ray.pos.y - origin.y) * cos(alpha));
		}
	}
	// out of map
	return (0);
}

void			ft_raycasting(t_env *env)
{
	double	wall_height;
	int		i;

	i = 0;
	while (i < XDIM)
	{
		env->ray.direction = (env->player.dir_d - FOV / 2)
		+ i * ((double)FOV / (double)XDIM);
		env->ray.distance = ft_cast_ray(env, env->ray.direction);
		wall_height = (env->bloc_size / env->ray.distance) * 700;
		ft_put_column(env, wall_height, i);
		i++;
	}
}
