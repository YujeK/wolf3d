/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:35:24 by badhont           #+#    #+#             */
/*   Updated: 2019/03/09 16:58:48 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/wolf3d.h"

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
double		ft_pythagore(double posx, double posy)
{
	return (sqrt(posx * posx + posy * posy)); //retourne l'hypothenuse
}

int     ft_is_in_wall(t_env *env, t_point pos)
{
	if (env->map[(int)pos.x / BLOC_SIZE][(int)pos.y / BLOC_SIZE] == 1) //est dans le mur
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
	while (env->pos.x > 0 && env->pos.x < env->map_width * BLOC_SIZE && env->pos.y > 0 && env->pos.y < env->map_height * BLOC_SIZE) //tant que est dans la map incrementer
	{
		env->pos.x += step.x;
		if (ft_is_in_wall(env, env->pos)) //si on arrive dans le mur
		{
			env->ray_pos.x = env->pos.x;
			env->side = 1;
			ft_get_cardinal(env);
			alpha = fabs((env->player.dir_d - direction) * (M_PI / 180));
			return (ft_pythagore(env->pos.x - origin.x, env->pos.y - origin.y) * cos(alpha));
		}

		env->pos.y += step.y;
		if (ft_is_in_wall(env, env->pos)) //si on arrive dans le mur
		{
			env->ray_pos.y = env->pos.y;
			env->side = 2;
			ft_get_cardinal(env);
			alpha = fabs((env->player.dir_d - direction) * (M_PI / 180));
			return (ft_pythagore(env->pos.x - origin.x, env->pos.y - origin.y) * cos(alpha));
		}
	}
	// out of map
	return (0);
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
			ft_setpixel(env->surface, XDIM - 1 - x, y, BLUE);
		else if (y >= p1 && y < p2)
			ft_setpixel(env->surface, XDIM - 1 - x, y, ft_texturing(env, y, p1, p2));
		else
			ft_setpixel(env->surface, XDIM - 1 - x, y, GREEN);
		y++;
	}
}

Uint32	ft_texturing(t_env *env, int y,  int p1, int p2)
{
	double 	wallhitx;
	Uint32	color;
	int		tex_x;
	int		tex_y;

	tex_y = (y - p1) * env->tex.north->h / (p2 - p1);
	if (env->side == 2)
	{
		wallhitx = (int)env->pos.x % BLOC_SIZE; //env->tex.north->w;
		tex_x = (wallhitx * env->tex.north->w) / ((BLOC_SIZE / env->distance) * 10);
	}
	else
	{
		wallhitx = (int)env->pos.y % BLOC_SIZE;
		tex_x = (wallhitx * env->tex.north->w) / ((BLOC_SIZE / env->distance) * 10);
	}
	color = ft_getpixel(ft_selectcolor(env), tex_x, tex_y);
	return (color);
}

void    ft_raycasting(t_env *env)
{
	int     i;
	double  wall_height;

	i = 0;
	while (i < XDIM)
	{
		env->direction = (env->player.dir_d - FOV / 2) + i
		* ((double)FOV / (double)XDIM); // angle du ray

		//lancer un rayon et recuperer sa longueur
		env->distance = ft_cast_ray(env, env->direction);
		wall_height = (BLOC_SIZE / env->distance) * 1000; // reset le coef au besoin

		ft_put_column(env, wall_height, i);
		i++;
	}
}
