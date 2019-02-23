/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinsky.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <gperilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:51:05 by gperilla          #+#    #+#             */
/*   Updated: 2018/03/28 11:56:02 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	look_at_all_these_recurv(t_env *env, t_pt start, t_pt end, int i)
{
	int ti;

	ti = (end.x - start.x) / 3;
	s_recurv(env, (t_pt){start.x, start.y},
		(t_pt){start.x + ti, start.y + ti}, i + 1);
	s_recurv(env, (t_pt){start.x + ti, start.y},
		(t_pt){end.x - ti, start.y + ti}, i + 1);
	s_recurv(env, (t_pt){end.x - ti, start.y},
		(t_pt){end.x, start.y + ti}, i + 1);
	s_recurv(env, (t_pt){start.x, start.y + ti},
		(t_pt){start.x + ti, end.y - ti}, i + 1);
	s_recurv(env, (t_pt){end.x - ti, start.y + ti},
		(t_pt){end.x, end.y - ti}, i + 1);
	s_recurv(env, (t_pt){start.x, end.y - ti},
		(t_pt){start.x + ti, end.y}, i + 1);
	s_recurv(env, (t_pt){start.x + ti, end.y - ti},
		(t_pt){end.x - ti, end.y}, i + 1);
	s_recurv(env, (t_pt){end.x - ti, end.y - ti},
		(t_pt){end.x, end.y}, i + 1);
}

void	s_recurv(t_env *env, t_pt start, t_pt end, int i)
{
	int ti;

	ti = (end.x - start.x) / 3;
	env->py = start.y + ti + env->rmovy;
	while (++env->py < end.y - ti + env->rmovy)
	{
		env->px = start.x + ti + env->rmovx;
		while (++env->px < end.x - ti + env->rmovx)
			my_putpixel(env, env->px, env->py, env->colors[i % 5]);
	}
	if (i < env->riter)
	{
		look_at_all_these_recurv(env, start, end, i);
	}
}

void	sierpinski_carpet(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img);
	env->pix = mlx_get_data_addr(env->img, &env->bpp, &env->s_l, &env->endian);
	env->img = mlx_new_image(env->mlx, WINX, WINY);
	s_recurv(env, (t_pt){0 - 100 * (env->rzoom - 1),
		0 - 100 * (env->rzoom - 1)}, (t_pt){WINX + 100 * (env->rzoom - 1),
			WINY + 100 * (env->rzoom - 1)}, 1);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
