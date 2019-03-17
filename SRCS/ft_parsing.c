/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:14:06 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/17 03:07:38 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_check_first_line(char *line, t_env *env)
{
	int		i;

	i = 0;
	if (!(env->mapsize.x = ft_atoi(line)))
		ft_error_exit("Wolf3d: Map: First line: Must begin by a number", env);
	i += ft_numberlen(env->mapsize.x);
	if (line[i] != ' ')
		ft_error_exit("Wolf3d: Map: First line: One space required", env);
	i++;
	env->mapsize.y = ft_atoi(line + i);
	i += ft_numberlen(env->mapsize.y);
	if (line[i])
		ft_error_exit("Wolf3d: Map: First line: Two numbers required", env);
}

void		ft_check_map_line(char *line, t_env *env)
{
	int		i;

	i = 0;
	if (!(ft_isdigit(line[0])))
		ft_error_exit("Wolf3d: Map: First char isn't a digit", env);
	while (line[i])
	{
		if (!((ft_isdigit(line[i]) && (line[i + 1] == ' ' || line[i + 1] == 0))
			|| (line[i] == ' ' && ft_isdigit(line[i + 1]))))
			ft_error_exit("Wolf3d: Map: Bad map format", env);
		i++;
	}
	i = (i == 1) ? 1 : (i + 1) / 2;
	if (i != env->mapsize.x)
		ft_error_exit("Wolf3d: Map: i != mapsize.x", env);
}

int			ft_stock_line(char *line, int y, t_env *env)
{
	int		i;
	int		x;
	int		spawn;

	i = 0;
	x = 0;
	spawn = 0;
	if (!(env->map[y] = (int *)ft_memalloc(sizeof(int) * (env->mapsize.x))))
		ft_error_exit("Wolf3d: Unable to malloc the map", env);
	while (line[i])
	{
		env->map[y][x] = ft_atoi(line + i);
		if (env->map[y][x] == 2)
		{
			env->player.pos.x = y;
			env->player.pos.y = x;
			spawn++;
		}
		i = (line[i + 1]) ? i + 2 : i + 1;
		x++;
	}
	return (spawn);
} 


void		ft_parsing(t_env *env, char *str)
{
	int			fd;
	int			spawn;
	int			nb_line;
	char		*line;

	
	spawn = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		ft_error_exit("Wolf3d: Unable to open the file", env);
	// checker le cas du /dev/zero (ne contient pas de \n)
	if (get_next_line(fd, &line) == 1)
		ft_check_first_line(line, env);

	if (!(env->map = (int **)ft_memalloc(sizeof(int *) * (env->mapsize.y))))
		ft_error_exit("Wolf3d: Unable to malloc the map", env);

	nb_line = 0;
	while (get_next_line(fd, &line) == 1)
	{
		ft_check_map_line(line, env);
		spawn += ft_stock_line(line, nb_line, env);
		ft_strdel(&line);
		nb_line++;
	}

	if (nb_line != env->mapsize.y)
		ft_error_exit("Wolf3d: Invalid map format", env);

	if (spawn != 1) 
		ft_error_exit("Wolf3d: Map: One spawn point required", env);

	close(fd);
}
