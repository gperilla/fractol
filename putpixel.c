/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <gperilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:21:01 by gperilla          #+#    #+#             */
/*   Updated: 2018/03/19 14:24:51 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_putpixel(t_env *env, int x, int y, int color)
{
	int		pos;
	int8_t	mask;

	if ((x >= 0 && x < WINX) && (y >= 0 && y < WINY))
	{
		pos = (y * env->s_l + x * (env->bpp / 8));
		mask = color;
		env->pix[pos] = mask;
		color = color >> 8;
		mask = color;
		env->pix[pos + 1] = mask;
		color = color >> 8;
		mask = color;
		env->pix[pos + 2] = mask;
		color = color >> 8;
		mask = color;
		env->pix[pos + 3] = mask;
	}
}
