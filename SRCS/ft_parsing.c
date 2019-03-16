/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:14:06 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/16 23:09:08 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*void		ft_map_alloc(t_env *env, char *str)
{
	char	*line;
	int		fd;
	int		fsize;
	int		i;

	i = -1;
	if ((fd = open(str, O_RDONLY)) == -1)
		ft_error_exit("Wolf3d: Unable to open file", env);
	while (get_next_line(fd, &line) == 1)
	{
		if (i == -1)
			fsize = ctword(line);
		else if (ctword(line) != fsize)
			ft_error_exit("Wolf3d: Map don't be a rectangle", env);
		if (fsize == 1)
			ft_error_exit("Wolf3d: Map don't be a rectangle", env);
		ft_strdel(&line);
		if (fsize > 100)
			ft_error_exit("Map d'hont be too big", env);
		i++;
	}
	env->mapsize.x = fsize;
	env->mapsize.y = i + 1;
	if (!(env->map = (int **)ft_memalloc(sizeof(int *) * (env->mapsize.y))))
		ft_error_exit("Wolf3d: Unable to malloc the map", env);
	close(fd);
}

void		ft_map_elems(t_env *env, int x, int y, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		env->map[y][x] = ft_atoi(line + i);
		if (env->map[y][x] == 2)
		{
			env->player.pos.x = y;
			env->player.pos.y = x;
		}
		if (line[i + 1])
			i += 2;
		else
			i++;
		x++;
	}
}

void		ft_map_filler(t_env *env, char *str)
{
	char	*line;
	int		fd;
	int		y;
	int		x;

	y = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		ft_error_exit("Wolf3d: Unable to open file", env);
	while (get_next_line(fd, &line) == 1)
	{
		x = 0;
		if (!(env->map[y] = (int *)ft_memalloc(sizeof(int) * (env->mapsize.x))))
			ft_error_exit("Wolf3d: Unable to malloc the map", env);
		ft_map_elems(env, x, y, line);
		ft_strdel(&line);
		y++;
	}
	close(fd);
}

void		ft_parsing(t_env *env, char *str)
{
	ft_map_alloc(env, str);
	ft_map_filler(env, str);
}*/

int			ft_check_firstline(char *line, t_env *env)
{
	if (!(env->mapsize.x = ft_atoi(line)))
		return (0);
	line += ft_numberlen(env->mapsize.x);
	if (*line != ' ')
		return (0);
	line++;
	if (!(env->mapsize.y = ft_atoi(line)))
		return (0);
	line += ft_numberlen(env->mapsize.y);	// 
	if (*line)								// check si qqchose après le 2eme nb
		return (0);							// pas obligé mais cool
	return (1);
}

int			ft_check_line(char *line, t_env *env)
{
	int		i;

	i = 0;
	if (!(ft_atoi(line[0])))
		return (0);
	while (line[i])
	{
		if (!((ft_isdigit(line[i]) && (line[i + 1] == ' ' || line[i + 1] == 0))
			|| (line[i] == ' ' && ft_isdigit(line[i + 1])))
			return (0);
		i++;
	}
	if (i != env->mapsize.x)
		return (0);
	return (1);
}

int			ft_stock_line(char *line, int y, t_env *env)
{
	int		i;

	i = 0;
	if (!(env->map[y] = (int *)ft_memalloc(sizeof(int) * (env->mapsize.x))))
		ft_error_exit("Wolf3d: Unable to malloc the map", env);
	while (line[i])
	{
		env->map[y][x] = ft_atoi(line + i);
		if (env->map[y][x] == 2)
		{
			env->player.pos.x = y;
			env->player.pos.y = x;
		}
		if (line[i + 1])
			i += 2;
		else
			i++;
		x++;
	}
	return (1);
} 

void		ft_parsing(t_env *env, char *str)
{
	int			fd;
	int			spawn;
	int			nb_line;
	char		*line;

	if ((fd = open(str, O_RDONLY)) == -1)
		ft_error_exit("Wolf3d: Unable to open the file", env);

	// checker le cas du /dev/zero (ne contient pas de \n)

	if (get_next_line(fd, &line) == 1)
		ft_check_firstline(line, env);

	if (get_next_line(fd, &line) == 1)
		if (!(ft_check_firstline(line, env)))
			ft_error_exit("Wolf3d: Format of the first line invalid", env);

	if (!(env->map = (int **)ft_memalloc(sizeof(int *) * (env->mapsize.y))))
		ft_error_exit("Wolf3d: Unable to malloc the map", env);

	while (nb_line < env->mapsize.y && get_next_line(fd, &line) == 1)
	{
		if (!(ft_check_line(line, env))
			// verifier la longueur, nombre / wspace
			ft_error_exit("Wolf3d: Invalid map format", env);
		if (!(ft_stock_line(line, nb_line, env)))
			ft_error_exit("Wolf3d: Unable to malloc the map", env);
		ft_strdel(&line);
		nb_line++;
	}

	if (nb_line != env->mapsize.y)
		ft_error_exit("Wolf3d: Invalid map format", env);

	if (spawn != 1) 
		ft_error_exit("Wolf3d: More than one spawn in the map", env);

	close(fd);
}
