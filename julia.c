/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <gperilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:57:45 by gperilla          #+#    #+#             */
/*   Updated: 2018/03/28 11:48:44 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	njulia(t_env *env)
{
	env->jul.xtemp = pow(env->jul.zx * env->jul.zx + env->jul.zy * env->jul.zy,
	(env->njul / 2)) * cos(env->njul * atan2(env->jul.zy, env->jul.zx));
	env->jul.zy = pow(env->jul.zx * env->jul.zx + env->jul.zy * env->jul.zy,
	env->njul / 2) * sin(env->njul * atan2(env->jul.zy, env->jul.zx)) + env->cy;
	env->jul.zx = env->jul.xtemp + env->cx;
}

void	juli1(t_env *env)
{
	env->jul.xtemp = env->jul.zx * env->jul.zx - env->jul.zy
	* env->jul.zy - env->cx;
	env->jul.zy = env->jul.zy * env->jul.zx * -3 - env->cy;
	env->jul.zx = env->jul.xtemp;
}

void	juli2(t_env *env)
{
	env->jul.xtemp = env->jul.zx * env->jul.zx - env->jul.zy
	* env->jul.zy - env->cx;
	env->jul.zy = env->jul.zy * env->jul.zx - env->cy;
	env->jul.zx = env->jul.xtemp;
}

void	init_julia(t_env *env)
{
	env->jul.rd = -1.5 * env->zoom;
	env->jul.re = 1.5 * env->zoom;
	env->jul.id = -1.5 * env->zoom;
	env->jul.ie = 1.5 * env->zoom;
	mlx_destroy_image(env->mlx, env->img);
	env->pix = mlx_get_data_addr(env->img, &env->bpp, &env->s_l, &env->endian);
	env->img = mlx_new_image(env->mlx, WINX, WINY);
}

void	julia(t_env *env)
{
	init_julia(env);
	env->jul.py = -1.0;
	while (++env->jul.py < WINY)
	{
		env->jul.px = -1.0;
		while (++env->jul.px < WINX)
			calc_and_draw_julia(env);
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
