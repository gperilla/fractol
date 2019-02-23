/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_key_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <gperilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:22:39 by gperilla          #+#    #+#             */
/*   Updated: 2018/03/28 11:50:58 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_it(int key, t_env *env)
{
	if (key == 126)
	{
		env->movy -= 25;
		env->rmovy -= 10;
	}
	else if (key == 125)
	{
		env->movy += 25;
		env->rmovy += 10;
	}
	else if (key == 124)
	{
		env->movx += 25;
		env->rmovx += 10;
	}
	else if (key == 123)
	{
		env->movx -= 25;
		env->rmovx -= 10;
	}
}

void	paint_me_like(int key, t_env *env)
{
	if (key == 116)
	{
		env->palette = ++env->palette % 3;
		set_colors(env);
	}
	else if (key == 121)
	{
		--env->palette;
		if (env->palette < 0)
			env->palette = 2;
		set_colors(env);
	}
	else if (key == 15)
		env->rdmclr = ++env->rdmclr % 2;
}

void	select_your_fract(int key, t_env *env)
{
	if (key == 49)
	{
		if (env->fract == 'm')
			env->fract = 'j';
		else if (env->fract == 'j' || env->fract == 'k' || env->fract == 'l'
			|| env->fract == ';')
			env->fract = 's';
		else if (env->fract == 's' || env->fract == 'n')
			env->fract = 'm';
	}
	else if (key == 258)
	{
		if (env->fract == 'j')
			env->fract = 'k';
		else if (env->fract == 'k')
			env->fract = 'l';
		else if (env->fract == 'l')
			env->fract = ';';
		else if (env->fract == ';')
			env->fract = 'j';
	}
	else if (key == 45)
		env->fract = 'n';
}

void	et_je_coupe_le_son(int key, t_env *env)
{
	if (key == 46)
	{
		if (!env->music)
		{
			env->music = 1;
			if (fork() == 0)
			{
				system("afplay -v .5 music.mp3");
				exit(0);
			}
		}
		else if (env->music)
		{
			env->music = 0;
			if (fork() == 0)
			{
				system("killall afplay");
				exit(0);
			}
		}
	}
}

int		my_key_hook(int key, t_env *env)
{
	if (key == 53)
		this_is_the_end(env);
	else if (key >= 123 && key <= 126)
		move_it(key, env);
	else if (key == 78 || key == 69 || key == 67 ||
		key == 75 || key == 91 || key == 84)
		zoom_iter(key, env);
	else if (key == 116 || key == 121 || key == 15)
		paint_me_like(key, env);
	else if (key == 49 || key == 45 || key == 258)
		select_your_fract(key, env);
	else if (key == 46)
		et_je_coupe_le_son(key, env);
	else if (key == 82)
		reinit_env(env);
	if (env->rdmclr)
		set_colors(env);
	draw_fract(env);
	return (0);
}
