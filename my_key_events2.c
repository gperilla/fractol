/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_key_events2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <gperilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:34:43 by gperilla          #+#    #+#             */
/*   Updated: 2018/03/27 08:57:03 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	this_is_the_end(t_env *env)
{
	if (env->music)
		if (fork() == 0)
		{
			system("killall afplay");
			exit(0);
		}
	exit(0);
}

void	zoom_in(int key, t_env *env)
{
	if (key == 78)
	{
		env->zoom *= 1.25;
		env->movx /= 1.25;
		env->movy /= 1.25;
		--env->maxiter;
	}
	else if (key == 69)
	{
		env->zoom /= 1.25;
		env->movx *= 1.25;
		env->movy *= 1.25;
		++env->maxiter;
	}
}

void	zoom_iter(int key, t_env *env)
{
	zoom_in(key, env);
	if (key == 67)
	{
		++env->maxiter;
		++env->riter;
	}
	else if (key == 75)
	{
		env->maxiter = ft_max(0, --env->maxiter);
		env->riter = ft_max(0, --env->riter);
	}
	else if (key == 91)
		++env->njul;
	else if (key == 84)
		--env->njul;
}
