/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 09:55:41 by asamir-k          #+#    #+#             */
/*   Updated: 2019/02/27 11:16:40 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/wolf3d.h"
#include "../INCLUDES/uilib/includes/libui.h"

void	init_game(t_env *env)
{
	env->quit = 0;
	env->player.dir_d = 90;
	env->coef_minimap = 6;
	env->cardinal = 0;
	if (TTF_Init() < 0)
		exit(EXIT_FAILURE);
	if (!(env->font = TTF_OpenFont("RESSOURCES/BEBAS.ttf", 100)))
		exit(EXIT_FAILURE);
		ft_loadtexture(env);
}

int		give_red(int x, int y, void *arg)
{
	(void)x;
	(void)y;
	(void)arg;
	return (RED);
}

SDL_Surface      *ft_new_surface(int height, int width)
{
	SDL_Surface     *surface;
	Uint32          color[4];

	color[0] = 0x000000ff;
	color[1] = 0x0000ff00;
	color[2] = 0x00ff0000;
	color[3] = 0xff000000;
	if (!(surface = SDL_CreateRGBSurface(
	0, width, height, 32, color[0], color[1], color[2], color[3])))
		ft_error(__func__,__LINE__);
	return (surface);
}

int		main(int ac, char **av)
{
	t_env	env;
	if (ac == 2)
	{
		init_sdl(&env.sdl, XDIM, YDIM);
		init_game(&env);
		env.surface = ft_new_surface(XDIM, YDIM); // to protect
		ft_map_catch(&env, av[1]);
		ft_looped(&env.quit, &env);
		exit_sdl(&env.sdl);
	}
	ft_putstr("Hi ^-^ !!! One argument(only) after binary authorised to make it work. Have a good time using me, byebye !\n                *pff humans are so retarded wtf ...*\n");
}
