/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <gperilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:02:16 by gperilla          #+#    #+#             */
/*   Updated: 2018/03/30 15:08:42 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	ft_printf("usage: ./fractol [m/j/c]\n");
	exit(0);
}

void	draw_options(t_env *env)
{
	mlx_clear_window(env->mlx, env->winop);
	mlx_string_put(env->mlx, env->winop, 10, 30 - 20, WHITE, "esc: quit");
	mlx_string_put(env->mlx, env->winop, 10, 60 - 20, WHITE, "arrows: move");
	mlx_string_put(env->mlx, env->winop, 10, 90 - 20, WHITE,
		"+ - scroll: zoom");
	mlx_string_put(env->mlx, env->winop, 10, 120 - 20, WHITE,
		"* /: nb of iterations");
	mlx_string_put(env->mlx, env->winop, 10, 150 - 20, WHITE,
		"shift: while on julia switch bonus fractals");
	mlx_string_put(env->mlx, env->winop, 10, 180 - 20, WHITE,
		"space: change mandelbrot>julia>sierpinky");
	mlx_string_put(env->mlx, env->winop, 10, 210 - 20, WHITE,
		"n: switch to multiple julia");
	mlx_string_put(env->mlx, env->winop, 10, 240 - 20, WHITE,
		"8 2: change nb of multjulia branches");
	mlx_string_put(env->mlx, env->winop, 10, 270 - 20, WHITE,
		"page up/down: change colors");
	mlx_string_put(env->mlx, env->winop, 10, 300 - 20, env->colors[4],
		"r: /!\\ epilepsy /!\\");
	mlx_string_put(env->mlx, env->winop, 10, 330 - 20, WHITE, "m: music \\o/");
	mlx_string_put(env->mlx, env->winop, 10, 360 - 20, WHITE, "0: reset");
}

void	draw_fract(t_env *env)
{
	draw_options(env);
	if (env->fract == 'm')
		mandelbrot(env);
	else if (env->fract == 'j' || env->fract == 'k' || env->fract == 'l'
		|| env->fract == 'n' || env->fract == ';')
		julia(env);
	else if (env->fract == 's')
		sierpinski_carpet(env);
}

int		i_quit(int key, t_env *env)
{
	if (key == 53)
		this_is_the_end(env);
	else if (key == 46)
		et_je_coupe_le_son(key, env);
	else if (key == 116 || key == 121 || key == 15)
	{
		paint_me_like(key, env);
		draw_fract(env);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_env env;

	if (argc != 2)
		print_usage();
	if (WINX <= 0 || WINY <= 0)
		exit(0);
	init_env(&env);
	init_fract(argv, &env);
	mlx_mouse_hook(env.win, my_mouse_hook, &env);
	mlx_key_hook(env.win, my_key_hook, &env);
	mlx_key_hook(env.winop, i_quit, &env);
	mlx_loop_hook(env.mlx, my_loop_hook, &env);
	mlx_hook(env.win, 6, (1L << 6), my_hook_events, &env);
	mlx_loop(env.mlx);
	return (0);
}
