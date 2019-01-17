/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:14:06 by asamir-k          #+#    #+#             */
/*   Updated: 2019/01/17 22:19:22 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/wolf3d.h"
# include "../INCLUDES/uilib/includes/libui.h"

int		ft_readverif(char *str)
{
	int	fd;

	if ((fd = open(str, O_RDONLY)) == -1)
		ft_error(__func__, __LINE__);
	return (fd);
}

void    ft_mapalloc(t_env *env, char *str)
{
    char    *line;
    int     fd;
    int     fsize;
    int     i;

    i = -1;
    fd = ft_readverif(str);
    while (get_next_line(fd, &line) == 1)
    {
        if (i == -1)
            fsize = ctword(line);
        else if (ctword(line) != fsize)
            ft_error(__func__, __LINE__);
        ft_strdel(&line);
        i++;
    }
    env->map_width = fsize;
    env->map_height = i + 1;
    printf("mapx : %d\nmapy : %d\n", env->map_height, env->map_width);
    if (!(env->map = (int **)ft_memalloc(sizeof(int *) * (env->map_height))))
        ft_error(__func__, __LINE__);
    close(fd);
}

void    ft_mapfiller(t_env *env, char *str)
{
    char *line;
    int     fd;
    int     y;
    int     x;
    int     i;

    fd = ft_readverif(str);
    y = 0;
    while (get_next_line(fd, &line) == 1)
    {
        x = 0;
        i = 0;
        if (!(env->map[y] = (int *)ft_memalloc(sizeof(int) * (env->map_width))))
            ft_error(__func__, __LINE__);
        while (line[i])
        {
            env->map[y][x] = ft_atoi(line + i);
            if (env->map[y][x] == 2)
            {
                env->player.position.x = x;
                env->player.position.y = y;
            }
            x++;
            i += 2;
        }
        ft_strdel(&line);
        y++;
    }
    close(fd);
}

void	ft_map_catch(t_env *env, char *str)
{
	int i;
	int j;
	ft_mapalloc(env, str);
	ft_mapfiller(env, str);
	i = 0;
    // print de la map recu en arg //
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
    printf("player x : %d\n", env->player.position.x);
    printf("player y : %d\n", env->player.position.y);
}

void    ft_print_map(t_env *env)
{
	int i;
	int j;
	i = 0;
    // print de la map recu en arg //
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
    printf("player x : %d\n", env->player.position.x);
    printf("player y : %d\n", env->player.position.y);
}
