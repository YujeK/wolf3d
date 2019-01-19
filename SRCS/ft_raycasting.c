/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:35:24 by badhont           #+#    #+#             */
/*   Updated: 2019/01/19 17:53:25 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/wolf3d.h"

double    ft_pythagore(double posx, double posy)
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
    double  alpha;

	step.x = -cos(direction * M_PI / 180) * 1;
 	step.y = -sin(direction * M_PI / 180) * 1;
    pos.x = env->player.pos.x * BLOC_SIZE;
    pos.y = env->player.pos.y * BLOC_SIZE;
    origin = (t_point){pos.x, pos.y};
    while (pos.x > 0 && pos.x < env->map_width * BLOC_SIZE && pos.y > 0 && pos.y < env->map_height * BLOC_SIZE) //tant que est dans la map incrementer
    {
        if (ft_is_in_wall(env, pos)) //si on arrive dans le mur
        {
            alpha = fabs((env->player.dir_d - direction) * (M_PI / 180));
            return (ft_pythagore(pos.x - origin.x, pos.y - origin.y) * cos(alpha));
        }
        pos.x += step.x;
        pos.y += step.y;
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
        /*if (i < p1)
            ft_setpixel(env->surface, index, i, BLUE);
        else */if (i > p1 && i < p2)
            ft_setpixel(env->surface, index, i, RED);
        else
            ft_setpixel(env->surface, index, i, BLACK);
        i++;
    }
}

void    ft_raycasting(t_env *env)
{
    int     i;
    double  direction;
    double  distance;
    double  wall_height;

    i = 0;
    while (i < XDIM)
    {
        direction = (env->player.dir_d - FOV / 2) + i * ((double)FOV / (double)XDIM); // angle du ray
        //lancer un rayon et recuperer sa longueur
        distance = ft_cast_ray(env, direction);
        wall_height = (BLOC_SIZE / distance) * 1000; // reset le coef au besoin
        ft_put_column(env, wall_height, i);
        i++;
    }
}