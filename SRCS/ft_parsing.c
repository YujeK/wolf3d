/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:14:06 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/09 20:05:31 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*void    ft_print_map(t_env *env)
{
	int i;
	int j;
	i = 0;
	printf("mapx : %d\nmapy : %d\n", env->map_height, env->map_width); // to delete
	// print de la map recu en arg
	ft_putstr("vanilla map file : \n");
	while (i < env->map_height)
	{
		j = 0;
		while (j < env->map_width)
		{
			printf("%d", env->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	// print de la position du joueur
	printf("player x : %f\n", env->player.pos.x); // to delete
	printf("player y : %f\n", env->player.pos.y); // to delete
}*/

int		ft_readverif(char *str, t_env *env)
{
	int	fd;

	if ((fd = open(str, O_RDONLY)) == -1)
		ft_error_exit("Wolf3d: Unable to open file", env);
	return (fd);
}

void    ft_map_alloc(t_env *env, char *str)
{
	char    *line;
	int     fd;
	int     fsize;
	int     i;

	i = -1;
	fd = ft_readverif(str, env);
	while (get_next_line(fd, &line) == 1)
	{
		if (i == -1)
			fsize = ctword(line);
		else if (ctword(line) != fsize)
			ft_error_exit("Wolf3d: Map don't be a rectangle", env);
		ft_strdel(&line);
		i++;
	}
	env->map_width = fsize;
	env->map_height = i + 1;
	if (!(env->map = (int **)ft_memalloc(sizeof(int *) * (env->map_height))))
		ft_error_exit("Wolf3d: Unable to malloc the map", env);
	close(fd);
}

void    ft_map_filler(t_env *env, char *str)
{
    char *line;
    int     fd;
    int     y;
    int     x;
	int		i;

    y = 0;
    fd = ft_readverif(str, env);
    while (get_next_line(fd, &line) == 1)
    {
        x = 0;
		i = 0;
        if (!(env->map[y] = (int *)ft_memalloc(sizeof(int) * (env->map_width))))
            ft_error_exit("Wolf3d: Unable to malloc the map", env);
        while (line[i])
        {
            env->map[y][x] = ft_atoi(line + i);
            if (env->map[y][x] == 2)
            {
                env->player.pos.x = x + 0.5;
                env->player.pos.y = y + 0.5;
            }
			if (line[i + 1])
				i += 2;
			else
				i++;
            x++;
        }
        ft_strdel(&line);
        y++;
    }
    close(fd);
}

void	ft_parsing(t_env *env, char *str)
{
	ft_map_alloc(env, str);
	ft_map_filler(env, str);
	//ft_print_map(env); // to delete
}
