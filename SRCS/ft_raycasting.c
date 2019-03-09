/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:35:24 by badhont           #+#    #+#             */
/*   Updated: 2019/03/09 19:56:52 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

Uint32 GetPixel32(SDL_Surface* image,int i,int j)
{
	if (i<0 || i>image->w-1 || j<0 || j>image->h-1)
		return 0;
	return ((Uint32*)(image->pixels))[j*(image->pitch/4)+i];   // lecture directe des pixels
}

SDL_Surface*     ft_selectcolor(t_env *env)
{
	if (env->cardinal == 1)
		return (env->tex.north);
	if (env->cardinal == 2)
		return (env->tex.east);
	if (env->cardinal == 3)
		return (env->tex.south);
	if (env->cardinal == 4)
		return (env->tex.west);
	return (0);
}

void		ft_get_cardinal(t_env *env)
{
	if (env->direction <= 180)
	{
		if (env->direction <= 90 && env->side == 1)
			env->cardinal = 2;
		if (env->direction > 90 && env->side == 1)
			env->cardinal = 4;
		if (env->side == 2)
			env->cardinal = 3;
	}
	else if (env->direction > 180)
	{
		if (env->direction <= 270 && env->side == 1)
			env->cardinal = 4;
		if (env->direction > 270 && env->side == 1)
			env->cardinal = 2;
		if (env->side == 2)
			env->cardinal = 1;
	}
}

Uint32	ft_texturing(t_env *env, int x, int y, int p1, int p2)
{
	SDL_Surface	*surface;	// texture
	Uint32		color;
	int			w_tex;		// largeur texture
	int			h_tex;		// hauteur texture
	int			x_tex;
	int			y_tex;
	int			ywall;

	(void)x;
	(void)p2;
	ywall = y - p1;

	surface = ft_selectcolor(env);
	w_tex = surface->w;
	h_tex = surface->h;

	// calcul colonne
	if (env->side == 2) // vertical hit
		x_tex = ((int)env->pos.x % BLOC_SIZE) * w_tex / BLOC_SIZE;
	else // horizontal hit
		x_tex = ((int)env->pos.y % BLOC_SIZE) * w_tex / BLOC_SIZE;

	y_tex = ywall * h_tex / (p2 - p1);

	color = ft_getpixel(surface, x_tex, y_tex, env);
	return (color);
}

void    ft_put_column(t_env *env, double wall_height, int x)
{
	int     p1;
	int     p2;
	int y;

	y = 0;
	p1 = YDIM / 2 - wall_height / 2;
	p2 = YDIM - p1;
	while (y < YDIM)
	{
		if (y < p1)
			ft_setpixel(env->surface, x, y, BLUE);
		else if (y >= p1 && y < p2)
			ft_setpixel(env->surface, x, y, ft_texturing(env, x, y, p1, p2));
		else
			ft_setpixel(env->surface, x, y, GREEN);
		y++;
	}
}

double		ft_pythagore(double posx, double posy)
{
	return (sqrt(posx * posx + posy * posy)); //retourne l'hypothenuse
}

int     ft_is_in_wall(t_env *env, t_point pos)
{
	if (env->map[(int)pos.x / BLOC_SIZE][(int)pos.y / BLOC_SIZE] == 1)
		return (1);
	return (0);
}

double  ft_cast_ray(t_env *env, double direction)
{
	t_point	step;
	t_point origin;
	double  alpha;

	step.x = -cos(direction * M_PI / 180) * 0.05;
 	step.y = -sin(direction * M_PI / 180) * 0.05;
	env->pos.x = env->player.pos.x * BLOC_SIZE;
	env->pos.y = env->player.pos.y * BLOC_SIZE;
	origin = (t_point){env->pos.x, env->pos.y};
	while (env->pos.x > 0 && env->pos.x < env->map_width * BLOC_SIZE
	&& env->pos.y > 0 && env->pos.y < env->map_height * BLOC_SIZE)
	{
		env->pos.x += step.x;
		if (ft_is_in_wall(env, env->pos)) //si on arrive dans le mur
		{
			env->ray_pos.x = env->pos.x;
			env->side = 1;
			ft_get_cardinal(env);
			alpha = fabs((env->player.dir_d - direction) * (M_PI / 180));
			return (ft_pythagore(env->pos.x - origin.x,
			env->pos.y - origin.y) * cos(alpha));
		}
		env->pos.y += step.y;
		if (ft_is_in_wall(env, env->pos)) //si on arrive dans le mur
		{
			env->ray_pos.y = env->pos.y;
			env->side = 2;
			ft_get_cardinal(env);
			alpha = fabs((env->player.dir_d - direction) * (M_PI / 180));
			return (ft_pythagore(env->pos.x - origin.x,
			env->pos.y - origin.y) * cos(alpha));
		}
	}
	// out of map
	return (0);
}

void    ft_raycasting(t_env *env)
{
	double  wall_height;
	int     i;

	i = 0;
	while (i < XDIM)
	{
		// calcul direction du rayon
		env->direction = (env->player.dir_d - FOV / 2)
		+ i * ((double)FOV / (double)XDIM);

		//lancer un rayon et recuperer sa longueur
		env->distance = ft_cast_ray(env, env->direction);

		// calcul wallheight
		wall_height = (BLOC_SIZE / env->distance) * 1000;

		// set pixels
		ft_put_column(env, wall_height, i);

		i++;
	}
}
