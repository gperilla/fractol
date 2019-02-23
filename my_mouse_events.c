/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mouse_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <gperilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:20:53 by gperilla          #+#    #+#             */
/*   Updated: 2018/03/28 16:51:45 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		my_mouse_hook(int button, int x, int y, t_env *env)
{
	if (button == 1)
		env->modif = ++env->modif % 2;
	if (button == 2)
		reinit_env(env);
	if (button == 5)
	{
		env->rzoom -= .2;
		env->zoom *= 1.25;
		env->movx = (env->movx - (x - WINX / 2) * .25) / 1.25;
		env->movy = (env->movy - (y - WINY / 2) * .25) / 1.25;
		--env->maxiter;
	}
	else if (button == 4)
	{
		env->rzoom += .2;
		env->zoom /= 1.25;
		env->movx = env->movx * 1.25 + (x - WINX / 2) * .25;
		env->movy = env->movy * 1.25 + (y - WINY / 2) * .25;
		++env->maxiter;
	}
	draw_fract(env);
	return (0);
}

int		my_loop_hook(t_env *env)
{
	if (env->rdmclr)
	{
		set_colors(env);
		draw_fract(env);
	}
	return (0);
}

int		my_hook_events(int x, int y, t_env *env)
{
	if (env->modif)
	{
		env->cx = -1 + 2.0 * x / WINX;
		env->cy = -1 + 2.0 * y / WINY;
	}
	if (env->rdmclr)
		set_colors(env);
	draw_fract(env);
	return (0);
}
