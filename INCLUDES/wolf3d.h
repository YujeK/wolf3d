/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:38:26 by asamir-k          #+#    #+#             */
/*   Updated: 2019/01/16 18:27:03 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft/libft.h"
# include "uilib/includes/libui.h"

# define YDIM 1200
# define XDIM 1200
# define PI 3.14160

# define PINK 0xFD2BE6
# define BLUE 0x0012FD
# define RED 0xFD0000
# define CYAN 0x00F3FD
# define YELLOW 0xFDF800
# define GREEN 0x05FD00
# define BROWN 0x8C4629
# define ORANGE 0xF87C00
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define PURPLE 0x7400AC
# define GREY 0x9A9A9A

typedef struct		s_position
{
	double	x;
	double	y;
}					t_pos;

typedef struct		s_player
{
	t_pos		position;
	double		direction;
}					t_player;

typedef struct		s_env
{
	t_player		player;
	t_sdl			sdl;
	int				**map;
	int				map_width;
	int				map_height;
	int				s_l;
	int				endian;
	int				bpp;
	int				*img_str;
	void			*img;
	void			*mlx;
	void			*win;
	int				quit;
}					t_env;

int		ft_readverif(char *str);
void	ft_map_catch(t_env *env, char *str);
void    ft_mapalloc(t_env *env, char *str);
void    ft_mapfiller(t_env *env, char *str);
void	ft_looped(int *quit, t_sdl *sdl);
void    events(int *quit, t_sdl *sdl);
#endif
