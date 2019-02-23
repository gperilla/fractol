/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   il_faut_norme_le_soldat_julia.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <gperilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:35:41 by gperilla          #+#    #+#             */
/*   Updated: 2018/03/28 11:48:06 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	juli3(t_env *env)
{
	env->jul.xtemp = env->jul.zx * env->jul.zx - env->jul.zy * env->jul.zy;
	env->jul.zy = 2 * env->jul.zx * env->jul.zy + sin(env->cy);
	env->jul.zx = env->jul.xtemp + cos(env->cx);
}

void	juli0(t_env *env)
{
	env->jul.xtemp = env->jul.zx * env->jul.zx - env->jul.zy * env->jul.zy;
	env->jul.zy = 2 * env->jul.zx * env->jul.zy + env->cy;
	env->jul.zx = env->jul.xtemp + env->cx;
}

void	calc_and_draw_julia(t_env *env)
{
	int i;

	i = 0;
	env->jul.zx = env->jul.rd + ((env->jul.px + env->movx) / WINX)
	* (env->jul.re - env->jul.rd);
	env->jul.zy = env->jul.id + ((env->jul.py + env->movy) / WINY)
	* (env->jul.ie - env->jul.id);
	while (env->jul.zx * env->jul.zx + env->jul.zy * env->jul.zy < 4
	&& ++i < env->maxiter)
	{
		if (env->fract == 'n')
			njulia(env);
		else if (env->fract == 'k')
			juli1(env);
		else if (env->fract == 'l')
			juli2(env);
		else if (env->fract == ';')
			juli3(env);
		else
			juli0(env);
	}
	if (i == env->maxiter)
		my_putpixel(env, env->jul.px, env->jul.py, env->colors[5]);
	else
		my_putpixel(env, env->jul.px, env->jul.py, env->colors[i % 5]);
}
