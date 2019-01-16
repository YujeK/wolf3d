/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 03:32:43 by nihuynh           #+#    #+#             */
/*   Updated: 2019/01/16 18:46:47 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_H
# define LIBUI_H

# include <SDL.h>
# include "color.h"
# define THR_C 20

typedef struct		s_pxl
{
	int				x;
	int				y;
}					t_pxl;

typedef struct s_data_thr	t_data_thr;



typedef struct		s_sdl
{
	int				isrender;
	int				width_vp;
	int				height_vp;
	int				thr_len;
	t_data_thr		*data_thr;
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Event		event;
}					t_sdl;

struct				s_data_thr
{
	int				*data;
	int				idx;
	t_sdl			*sdl;
	int				(*do_pxl) (int, int, void*);
	void			*prg_data;
};

typedef void	(*t_looped)(int *quit, t_sdl *sdl);

# define SIVOID		static inline void
# define SIFLOAT	static inline float

/*
** Color :
*/

void				color_mult(t_color *color, t_color *mult);
void				color_scalar(t_color *color, float k);
void				color_add(t_color *color, t_color *add);
void				color_sub(t_color *color, t_color *sub);
void				color_max(t_color *col1, t_color *col2);
int					colortoi(t_color *color);
/*
** SDL :
*/

void				putcolor_sdl(t_sdl *sdl, int color, int x, int y);
void				putpixel_sdl(t_sdl *sdl, t_color col, int x, int y);
void				error_sdl(t_sdl *sdl);
int					init_sdl(t_sdl *sdl, int width, int length);
void				exit_sdl(t_sdl *sdl);
void				render_sdl(t_sdl *sdl, int (*f) (int, int, void*), void *d);
void				loop_sdl(int *quit, t_sdl *sdl, t_looped looped);

void				init_mthr_sdl(t_sdl *sdl, int (*do_pxl)(int, int, void*),
									void *data);
void				render_mthr_sdl(t_sdl *sdl);
#endif
