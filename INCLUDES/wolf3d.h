/* ************************************************************************** */
/*			                                                                  */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:38:26 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/09 18:01:16 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft/libft.h"
# include <SDL_ttf.h>
# include <SDL_image.h>
#include <math.h>

# define YDIM 800
# define XDIM 800
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

typedef struct		s_sdl
{
	SDL_Event		event;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
}					t_sdl;

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

typedef	struct		s_tex
{
	SDL_Surface		*north;
	SDL_Surface		*west;
	SDL_Surface		*south;
	SDL_Surface		*east;
}					t_tex;


typedef struct		s_env
{
	t_sdl			sdl;
	t_tex			tex;
	SDL_Surface		*surface;
	TTF_Font		*font;
	int				**map;
	int				map_width;
	int				map_height;
	t_player		player;
	int				mouse_x;
	int				mouse_y;

	double			direction;	// dir_d d'un rayon
	double			distance;	// dist d'un rayon
	int				side;		// side impact mur
	t_point			pos;		// position bout du rayon

	SDL_Rect		rect;
	int				coef_minimap; // taille de la minimap
	int				posx;
	int				posy;
	int				cardinal;
	Uint32			last;
	int				wallhitx;
	t_point			ray_pos;
}					t_env;

SDL_Surface      *ft_new_surface(int height, int width, t_env *env);
void			ft_error_exit(char *str, t_env *env);
void			ft_exit(t_env *env);
int				events(t_env *env);
void			ft_wolf_loop(t_env *env);
void			ft_parsing(t_env *env, char *str);


int				ft_is_in_wall(t_env *env, t_point pos);
void			ft_setpixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
void			ft_set_player_dir(t_env *env);
void			dl(t_env *env, t_point pt1, t_point pt2, int color);
void			ft_print_map(t_env *env);
void			ft_minimap(t_env *env);
int				ft_readverif(char *str, t_env *env);
void			ft_map_alloc(t_env *env, char *str);
void			ft_map_filler(t_env *env, char *str);
void			ft_raycasting(t_env *env);
void			ft_set_string(SDL_Rect rect, char *text, SDL_Color color, t_env *env);
SDL_Color		ft_hex_to_rgb(int hexa);
void			crosshair(t_env *env);
void			fpscount(t_env *env);
void			ft_loadtexture(t_env *env);
Uint32			ft_getpixel(SDL_Surface *surface, int x, int y, t_env *env);
void			ft_put_column(t_env *env, double wall_height, int x);
void			ft_brosenham(t_env *env, t_line *line, int color, int swap);
#endif
