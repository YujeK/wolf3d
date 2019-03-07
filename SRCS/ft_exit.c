/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 21:42:55 by badhont           #+#    #+#             */
/*   Updated: 2019/03/07 22:42:11 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/wolf3d.h"

void	ft_error_exit(char *str, t_env *env)
{
    (void)env;
	ft_putendl_fd(str, 2);
    TTF_Quit();
    SDL_Quit();
	exit(EXIT_FAILURE);
}

void    ft_exit(t_env *env)
{
    (void)env;
    TTF_Quit();
    SDL_Quit();
    exit(EXIT_SUCCESS);
}