/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:14:06 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/24 10:45:23 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_readverif(char *str, t_env *env)
{
	int	fd;

	if ((fd = open(str, O_RDONLY)) == -1)
		ft_error_exit("Wolf3d: Unable to open file", env);
	return (fd);
}

void		ft_map_alloc(t_env *env, char *str)
{
	char	*line;
	int		fd;
	int		fsize;
	int		i;

	i = -1;
	fd = ft_readverif(str, env);
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
			ft_error_exit("Map don't be too big", env);
		i++;
	}
	env->map_width = fsize;
	env->map_height = i + 1;
	if (!(env->map = (int **)ft_memalloc(sizeof(int *) * (env->map_height))))
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
	fd = ft_readverif(str, env);
	while (get_next_line(fd, &line) == 1)
	{
		x = 0;
		if (!(env->map[y] = (int *)ft_memalloc(sizeof(int) * (env->map_width))))
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
}
