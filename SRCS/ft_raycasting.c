/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:35:24 by badhont           #+#    #+#             */
/*   Updated: 2019/02/27 14:11:32 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/wolf3d.h"

int     ft_selectcolor(t_env *env)
{
	if (env->cardinal == 1)
		return (YELLOW);
	if (env->cardinal == 2)
		return (CYAN);
	if (env->cardinal == 3)
		return (PURPLE);
	if (env->cardinal == 4)
		return (GREY);
	return (WHITE);
}

void		ft_get_cardinal(t_env *env, int side)
{
	if (env->direction <= 180)
	{
		if (env->direction <= 90 && side == 1)
			env->cardinal = 2;
		if (env->direction > 90 && side == 1)
			env->cardinal = 4;
		if (side == 2)
			env->cardinal = 3;
	}
	else if (env->direction > 180)
	{
		if (env->direction <= 270 && side == 1)
			env->cardinal = 4;
		if (env->direction > 270 && side == 1)
			env->cardinal = 2;
		if (side == 2)
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
	t_point pos;
	t_point origin;
	int     side;
	double  alpha;

	step.x = -cos(direction * M_PI / 180) * 0.05;
 	step.y = -sin(direction * M_PI / 180) * 0.05;
	pos.x = env->player.pos.x * BLOC_SIZE;
	pos.y = env->player.pos.y * BLOC_SIZE;
	origin = (t_point){pos.x, pos.y};
	while (pos.x > 0 && pos.x < env->map_width * BLOC_SIZE && pos.y > 0 && pos.y < env->map_height * BLOC_SIZE) //tant que est dans la map incrementer
	{
		pos.x += step.x;
		side = 1;
			if (ft_is_in_wall(env, pos)) //si on arrive dans le mur
		{
			ft_get_cardinal(env, side);
			alpha = fabs((env->player.dir_d - direction) * (M_PI / 180));
			return (ft_pythagore(pos.x - origin.x, pos.y - origin.y) * cos(alpha));
		}
		pos.y += step.y;
		if (ft_is_in_wall(env, pos)) //si on arrive dans le mur
		{
			side = 2;
			ft_get_cardinal(env, side);
			alpha = fabs((env->player.dir_d - direction) * (M_PI / 180));
			return (ft_pythagore(pos.x - origin.x, pos.y - origin.y) * cos(alpha));
		}
	}
	// out of map
	return (0);
}

void    ft_put_column(t_env *env, double wall_height, int index)
{
	int     p1;
	int     p2;
	int i;

	i = 0;
	p1 = YDIM / 2 - wall_height / 2;
	p2 = YDIM - p1;
	while (i < YDIM)
	{
		if (i < p1)
			ft_setpixel(env->surface, XDIM - 1 - index, i, BLUE);
		else if (i >= p1 && i < p2)
			ft_setpixel(env->surface, XDIM - 1 - index, i, ft_selectcolor(env));
		else
			ft_setpixel(env->surface, XDIM - 1 - index, i, GREEN);
		i++;
	}
}

void    ft_raycasting(t_env *env)
{
	int     i;
	double  distance;
	double  wall_height;

	i = 0;
	while (i < XDIM)
	{
		env->direction = (env->player.dir_d - FOV / 2) + i * ((double)FOV / (double)XDIM); // angle du ray
		//lancer un rayon et recuperer sa longueur
		distance = ft_cast_ray(env, env->direction);
		wall_height = (BLOC_SIZE / distance) * 1000; // reset le coef au besoin
		ft_put_column(env, wall_height, i);
		i++;
	}
}


void		ft_texturing(t_env *env)
{
	if (side == 1)
		{
			wallhitx = pos.x % BLOC_SIZE;
			tex.x = wallhit.x * tex.width / BLOC_SIZE;
			whichpx = p1 * tex.h / p2;
		}
	if (side == 2)
		{
			wallhity = pos.y % BLOC_SIZE;
			tex.y = wallhit.y * tex.width / BLOC_SIZE;
			whichpx = p1 * tex.h / p2;
		}
}
