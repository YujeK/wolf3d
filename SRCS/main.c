/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 09:55:41 by asamir-k          #+#    #+#             */
/*   Updated: 2019/01/14 17:40:06 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/wolf3d.h"
# include "../INCLUDES/uilib/includes/libui.h"

void	init_game(t_env *env)
{
	env->quit = 0;
	ft_bzero(&(env->player), sizeof(t_player));
}

int		give_red(int x, int y, void *arg)
{
	(void)x;
	(void)y;
	(void)arg;
	return (RED);
}

int		main(int ac, char **av)
{
	t_env	env;
	(void)av;
	if (ac == 2)
	{
		init_sdl(&env.sdl, XDIM, YDIM);
		init_game(&env);
		ft_map_catch(&env, av[1]);
		render_sdl(&env.sdl, &give_red, NULL);
		loop_sdl(&env.quit, &env.sdl, &events);
		exit_sdl(&env.sdl);
	}
	ft_putstr("Hi ^-^ !!! One argument(only) after binary authorised to make it work. Have a good time using me, byebye !\n                *pff humans are so retarded wtf ...*\n");
	exit(0);
}
