/* ************************************************************************** */
/*			                                                                  */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:38:26 by asamir-k          #+#    #+#             */
/*   Updated: 2019/03/09 21:24:28 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_image.h>
# include <math.h>

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
# define BLOC_SIZE 40
# define FOV 60

typedef	struct	s_sdl		t_sdl;
typedef	struct	s_point		t_point;
typedef	struct	s_rect		t_rect;
typedef	struct	s_player	t_player;
typedef	struct	s_line		t_line;
typedef	struct	s_ray		t_ray;
typedef	struct	s_tex		t_tex;
typedef	struct	s_env		t_env;

struct						s_sdl
{
	SDL_Event		event;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
};

struct					s_point
{
	double				x;
	double				y;
};

struct						s_rect
{
	double		x;
	double		y;
	double		width;
	double		height;
};

struct						s_player
{
	t_point			pos;   // position du joueur
	double			dir_d; // direction en degres
	double			dir_r; // direction en radians
};

struct						s_line
{
	int				x;
	int				y;
	int				d;
	int				dx;
	int				dy;
	int				s1;
	int				s2;
};

struct						s_ray
{
	double			direction;	// dir_d d'un rayon
	int				cardinal;	// N / S / E / W
	double			distance;	// dist d'un rayon
	int				side;		// side impact mur
	t_point			pos;		// position bout du rayon
};

struct						s_tex
{
	SDL_Surface		*north;
	SDL_Surface		*west;
	SDL_Surface		*south;
	SDL_Surface		*east;
};

struct						s_env
{
	t_sdl			sdl;		// object sdl
	t_tex			tex;		// images
	SDL_Surface		*surface;	// surface principale
	TTF_Font		*font;		// police d'ecriture
	int				**map;		// map
	int				map_width;	// largeur map
	int				map_height;	// hauteur map
	t_player		player;		// data joueur
	int				mouse_x;	// data souris
	int				mouse_y;	// data souris
	t_ray			ray;		// data rayon courant
	Uint32			last;		// last timestamp for fps
	int				coef_minimap;	// coef minimap
	t_point			ray_pos;		// ??? 
};

/*
**	Init / Parsing
*/

void			ft_parsing(t_env *env, char *str);

/*
**	Wolf3d
*/

void			ft_wolf_loop(t_env *env);
void			ft_raycasting(t_env *env);
void			ft_set_player_dir(t_env *env);
void			ft_minimap(t_env *env);

/*
**	Events
*/

int				events(t_env *env);

/*
**	Utils
*/

int				ft_is_in_wall(t_env *env, t_point pos);

/*
**	Graphics
*/

SDL_Surface      *ft_new_surface(int height, int width, t_env *env);
void			ft_loadtexture(t_env *env);
Uint32			ft_getpixel(SDL_Surface *surface, int x, int y, t_env *env);
void			ft_setpixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
void			dl(t_env *env, t_point pt1, t_point pt2, int color);
void			ft_set_string(SDL_Rect rect, char *text, SDL_Color color, t_env *env);
SDL_Color		ft_hex_to_rgb(int hexa);

/*
**	Exit
*/

void			ft_error_exit(char *str, t_env *env);
void			ft_exit(t_env *env);

#endif
