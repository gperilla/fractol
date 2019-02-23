/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <gperilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 01:22:36 by gperilla          #+#    #+#             */
/*   Updated: 2018/03/30 15:09:21 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_env(t_env *env)
{
	srand(time(NULL));
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WINX, WINY, "fractol");
	env->winop = mlx_new_window(env->mlx, 450, 370, "commandes");
	env->img = mlx_new_image(env->mlx, WINX, WINY);
	env->pix = mlx_get_data_addr(env->img, &env->bpp, &env->s_l, &env->endian);
	env->fract = 'm';
	env->maxiter = 23;
	env->movx = 0;
	env->movy = 0;
	env->zoom = 1.0;
	env->palette = 1;
	env->cx = 0.0;
	env->cy = 0.0;
	env->njul = 2;
	env->rdmclr = 0;
	env->riter = 2;
	env->rzoom = 1.0;
	env->rmovx = 0;
	env->rmovy = 0;
	env->music = 0;
	env->modif = 0;
	set_colors(env);
	draw_options(env);
}

void	reinit_env(t_env *env)
{
	env->maxiter = 23;
	env->movx = 0;
	env->movy = 0;
	env->zoom = 1.0;
	env->cx = 0.0;
	env->cy = 0.0;
	env->modif = 0;
	env->njul = 2;
	env->riter = 2;
	env->rzoom = 1.0;
	env->rmovx = 0;
	env->rmovy = 0;
	set_colors(env);
}

void	init_fract(char **argv, t_env *env)
{
	if (ft_strequ("mandelbrot", argv[1])
		|| ft_strequ("m", argv[1]))
	{
		mandelbrot(env);
		env->fract = 'm';
	}
	else if (ft_strequ("julia", argv[1])
		|| ft_strequ("j", argv[1]))
	{
		julia(env);
		env->fract = 'j';
	}
	else if (ft_strequ("carpet", argv[1])
		|| ft_strequ("c", argv[1]))
	{
		sierpinski_carpet(env);
		env->fract = 's';
	}
	else
		print_usage();
}

void	set_colors2(t_env *env)
{
	if (env->palette == 1)
	{
		env->colors[0] = BEIGE;
		env->colors[1] = CYAN;
		env->colors[2] = YELLOW;
		env->colors[3] = VIOLET;
		env->colors[4] = LIME_GREEN;
		env->colors[5] = BLACK;
	}
	else if (env->palette == 2)
	{
		env->colors[0] = rand() % 0xFFFFFF;
		env->colors[1] = rand() % 0xFFFFFF;
		env->colors[2] = rand() % 0xFFFFFF;
		env->colors[3] = rand() % 0xFFFFFF;
		env->colors[4] = rand() % 0xFFFFFF;
		env->colors[5] = rand() % 0xFFFFFF;
	}
}

void	set_colors(t_env *env)
{
	if (env->rdmclr)
	{
		env->colors[0] = env->colors[1];
		env->colors[1] = env->colors[2];
		env->colors[2] = env->colors[3];
		env->colors[3] = env->colors[4];
		env->colors[4] = env->colors[5];
		env->colors[5] = rand() % 0xFFFFFF;
	}
	else if (env->palette == 0)
	{
		env->colors[0] = 0xFFFFFF;
		env->colors[1] = 0xBBBBBB;
		env->colors[2] = 0x999999;
		env->colors[3] = 0x666666;
		env->colors[4] = 0x333333;
		env->colors[5] = BLACK;
	}
	else
		set_colors2(env);
}
