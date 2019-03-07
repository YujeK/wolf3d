/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:38:26 by asamir-k          #+#    #+#             */
/*   Updated: 2019/02/28 18:54:25 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft/libft.h"
# include "uilib/includes/libui.h"
# include <SDL_ttf.h>
# include <SDL_image.h>
#include <math.h>

# define YDIM 800
# define XDIM 800
# define PI 3.14160
# define TEX_W 64
# define TEX_H 64

# define PINK 0xFFE62BFD
# define BLUE 0xFFFD1200
# define RED 0xFFFD0000
# define CYAN 0xFF00F3FD
# define YELLOW 0xFFFDF800
# define GREEN 0xFF00FD05
# define BROWN 0xFF29468C
# define ORANGE 0xFFF87C00
# define WHITE 0xFFFFFFFF
# define BLACK 0xFF000000
# define PURPLE 0xFF7400AC
# define GREY 0xFF9A9A9A
# define BLOC_SIZE 10
# define FOV 60


typedef struct		s_point
{
	double				x;
	double				y;
}					t_point;

typedef struct		s_rect
{
	double		x;
	double		y;
	double		width;
	double		height;
}					t_rect;

typedef struct		s_player
{
	t_point		pos;   // position du joueur
	double		dir_d; // direction en degres
	double		dir_r; // direction en radians
}					t_player;

typedef struct		s_line
{
	int				x;
	int				y;
	int				d;
	int				dx;
	int				dy;
	int				s1;
	int				s2;
}					t_line;

typedef struct		s_env
{
	double			distance;
	int				side;
	SDL_Rect		rect;
	t_player		player;
	t_sdl			sdl;
	int				**map;
	int				map_width;
	int				map_height;
	int				coef_minimap; // taille de la minimap
	int				quit;
	int				posx;
	int				posy;
	t_point			pos;
	SDL_Surface		*surface;
	TTF_Font		*font;
	int				cardinal;
	double			direction;
	int				mouse_x;
	int				mouse_y;
	Uint32			last;
	SDL_Surface			*north_tex;
	SDL_Surface			*west_tex;
	SDL_Surface			*south_tex;
	SDL_Surface			*east_tex;
	int				wallhitx;
	t_point			ray_pos;
}					t_env;

int		ft_is_in_wall(t_env *env, t_point pos);
void	ft_setpixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
void	ft_set_player_dir(t_env *env);
void	dl(t_env *env, t_point pt1, t_point pt2, int color);
void    ft_print_map(t_env *env);
void    ft_display_player(t_env *env);
int		ft_readverif(char *str);
void	ft_map_catch(t_env *env, char *str);
void    ft_mapalloc(t_env *env, char *str);
void    ft_mapfiller(t_env *env, char *str);
void	ft_looped(int *quit, t_env *env);
void    events(int *quit, t_env *env);
void    ft_raycasting(t_env *env);
void	ft_set_string(SDL_Rect rect, char *text, SDL_Color color, t_env *env);
SDL_Color		ft_hex_to_rgb(int hexa);
void    crosshair(t_env *env);
void    fpscount(t_env *env);
void	ft_loadtexture(t_env *env);
Uint32	ft_getpixel(SDL_Surface *surface, int x, int y);
Uint32	ft_texturing(t_env *env, int i, int p1, int p2);
void    ft_put_column(t_env *env, double wall_height, int x);
void	ft_brosenham(t_env *env, t_line *line, int color, int swap);
#endif
