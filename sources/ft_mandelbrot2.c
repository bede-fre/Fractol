/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:13:17 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/20 10:37:41 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_val_mandelbrot2(t_values *val)
{
	val->fct2.c_r = (val->fct2.x / val->draw.zoom2) + val->fct2.x1;
	val->fct2.c_i = (val->fct2.y / val->draw.zoom2) + val->fct2.y1;
	val->fct2.i = -1.0;
	val->fct2.z_r = 0.0;
	val->fct2.z_i = 0.0;
}

void		ft_mandelbrot2(t_values *val)
{
	val->fct2.x = -1.0;
	while (++(val->fct2.x) < val->draw.w_win)
	{
		val->fct2.y = -1.0;
		while (++(val->fct2.y) < val->draw.l_win)
		{
			ft_init_val_mandelbrot2(val);
			while (((val->fct2.z_r * val->fct2.z_r)
				+ (val->fct2.z_i * val->fct2.z_i)) < 4.0
					&& (++(val->fct2.i) < (val->fct2.i_max)))
			{
				val->fct2.tp = val->fct2.z_r;
				val->fct2.z_r = (val->fct2.z_r * val->fct2.z_r)
					- (val->fct2.z_i * val->fct2.z_i) + val->fct2.c_r;
				val->fct2.z_i = (2.0 * val->fct2.z_i * val->fct2.tp)
					+ val->fct2.c_i;
			}
			if (val->fct2.i == val->fct2.i_max)
				ft_fill_px2(val, (val->fct2.x), (val->fct2.y), (val->set2 == 6)
					? 0xFFFFFF : 0);
			else
				ft_fill_px2(val, (val->fct2.x), (val->fct2.y), (val->set2 == 7)
					? ft_smooth_gradient2(val) : ft_color2(val));
		}
	}
}
