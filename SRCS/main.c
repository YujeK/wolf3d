/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 09:55:41 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/07 22:48:20 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/wolf3d.h"

void	init_sdl(t_env *env)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_error_exit("Wolf3d: Unable to initialize SDL2", env);
	if (TTF_Init() < 0)
		ft_error_exit("Wolf3d: Unable to initialize SDL TTF", env);
	if (!(env->sdl.window = SDL_CreateWindow("Wolf3d",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, XDIM, YDIM, 0)))
		ft_error_exit("Wolf3d: Unable to make window", env);
	SDL_RaiseWindow(env->sdl.window);
	if (!(env->sdl.renderer = SDL_CreateRenderer(env->sdl.window, -1,
		SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_SOFTWARE)))
		ft_error_exit("Wolf3d: Unable to make renderer", env);
}

void	init_game(t_env *env)
{
	ft_bzero(env, sizeof(t_env));
	env->surface = ft_new_surface(XDIM, YDIM, env);
	if (!(env->font = TTF_OpenFont("RESSOURCES/BEBAS.ttf", 100)))
		ft_error_exit("Wolf3d: Unable to get font", env);
	ft_loadtexture(env);

	// standby
	env->quit = 0;
	env->player.dir_d = 0;
	env->coef_minimap = 2;
	env->cardinal = 1;
}



int		main(int ac, char **av)
{
	t_env	env;
	if (ac == 2)
	{
		// initialisation
		init_sdl(&env); // c'est bon
		init_game(&env);

		// parsing
		ft_map_catch(&env, av[1]); // proteger le contenu

		// gameloop
		ft_looped(&env.quit, &env);
	}
	ft_putstr("Hi ^-^ !!! One argument(only) after binary authorised to make it work.");
	ft_putendl("Have a good time using me, byebye !\n*pff humans are so retarded wtf ...*");
	return (0);
}
