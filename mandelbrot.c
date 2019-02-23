/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <gperilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:06:24 by gperilla          #+#    #+#             */
/*   Updated: 2018/03/28 11:49:12 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandel(t_env *env)
{
	env->mand.rd = -1.5 * env->zoom;
	env->mand.re = 0.5 * env->zoom;
	env->mand.id = -1.0 * env->zoom;
	env->mand.ie = 1.0 * env->zoom;
	mlx_destroy_image(env->mlx, env->img);
	env->pix = mlx_get_data_addr(env->img, &env->bpp, &env->s_l, &env->endian);
	env->img = mlx_new_image(env->mlx, WINX, WINY);
}

void	precalcul_mandel(t_env *env)
{
	env->mand.x0 = env->mand.rd + ((env->mand.px + env->movx) / WINX)
	* (env->mand.re - env->mand.rd);
	env->mand.y0 = env->mand.id + ((env->mand.py + env->movy) / WINY)
	* (env->mand.ie - env->mand.id);
	env->mand.x = 0.0;
	env->mand.y = 0.0;
	env->mand.xs = 0.0;
	env->mand.ys = 0.0;
}

void	calcul_brot(t_env *env)
{
	env->mand.y = env->mand.x * env->mand.y;
	env->mand.y += env->mand.y;
	env->mand.y += env->mand.y0;
	env->mand.x = env->mand.xs - env->mand.ys + env->mand.x0;
	env->mand.xs = env->mand.x * env->mand.x + env->cx;
	env->mand.ys = env->mand.y * env->mand.y + env->cy;
}

void	mandelbrot(t_env *env)
{
	int i;

	init_mandel(env);
	env->mand.py = -1.0;
	while (++env->mand.py < WINY)
	{
		env->mand.px = -1.0;
		while (++env->mand.px < WINX)
		{
			precalcul_mandel(env);
			i = 0;
			while (env->mand.xs + env->mand.ys < 4 && ++i < env->maxiter)
				calcul_brot(env);
			if (i == env->maxiter)
				my_putpixel(env, env->mand.px, env->mand.py, env->colors[5]);
			else
				my_putpixel(env, (int)env->mand.px, (int)env->mand.py,
					env->colors[i % 5]);
		}
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
