/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <gperilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:05:01 by gperilla          #+#    #+#             */
/*   Updated: 2018/03/28 16:30:01 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <time.h>
# include <pthread.h>
# include "mlx.h"
# include "libft.h"
# include "colors.h"

# ifndef WINX
#  define WINX 750
# endif
# ifndef WINY
#  define WINY 750
# endif

typedef struct	s_julia
{
	double	px;
	double	py;
	double	zx;
	double	zy;
	double	xtemp;
	double	ytemp;
	double	rd;
	double	re;
	double	id;
	double	ie;
	int		dx;
	int		dy;
}				t_julia;

typedef struct	s_mandl
{
	double	px;
	double	py;
	double	x;
	double	y;
	double	xs;
	double	ys;
	double	x0;
	double	y0;
	double	rd;
	double	re;
	double	id;
	double	ie;
	int		dx;
	int		dy;
}				t_mandl;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*winop;
	void	*img;
	char	*pix;
	int		bpp;
	int		s_l;
	int		endian;
	int		maxiter;
	int		movx;
	int		movy;
	int		njul;
	int		colors[6];
	int		palette;
	int		rdmclr;
	char	fract;
	double	cx;
	double	cy;
	int		modif;
	double	zoom;
	int		riter;
	double	rzoom;
	int		rmovx;
	int		rmovy;
	int		music;
	t_julia	jul;
	t_mandl	mand;
	int		px;
	int		py;
}				t_env;

typedef struct	s_pt
{
	int	x;
	int	y;
}				t_pt;

void			my_putpixel(t_env *env, int x, int y, int color);

void			print_usage(void);

void			draw_options(t_env *env);

void			paint_me_like(int key, t_env *env);

void			init_fract(char **argv, t_env *env);

void			init_env(t_env *env);

void			reinit_env(t_env *env);

void			set_colors(t_env *env);

void			mandelbrot(t_env *env);

void			asciibrot(int n);

void			calc_and_draw_julia(t_env *env);

void			julia(t_env *env);

void			juli1(t_env *env);

void			juli2(t_env *env);

void			sierpinski_carpet(t_env *env);

void			s_recurv(t_env *env, t_pt start, t_pt end, int i);

void			njulia(t_env *env);

void			draw_fract(t_env *env);

void			this_is_the_end(t_env *env);

void			et_je_coupe_le_son(int key, t_env *env);

int				my_hook_events(int x, int y, t_env *env);

int				my_loop_hook(t_env *env);

int				my_key_hook(int key, t_env *env);

int				my_mouse_hook(int button, int x, int y, t_env *env);

void			zoom_iter(int key, t_env *env);

#endif
