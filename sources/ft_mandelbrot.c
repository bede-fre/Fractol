/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:13:17 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/14 15:20:33 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_val2_mandelbrot(t_values *val)
{
	val->fract.c_r = (val->fract.x / val->draw.zoom) + val->fract.x1;
	val->fract.c_i = (val->fract.y / val->draw.zoom) + val->fract.y1;
	val->fract.i = -1.0;
	val->fract.z_r = 0.0;
	val->fract.z_i = 0.0;
}

void		ft_mandelbrot(t_values *val)
{
	val->fract.x = -1.0;
	while (++(val->fract.x) < val->draw.w_win)
	{
		val->fract.y = -1.0;
		while (++(val->fract.y) < val->draw.l_win)
		{
			ft_init_val2_mandelbrot(val);
			while (((val->fract.z_r * val->fract.z_r)
				+ (val->fract.z_i * val->fract.z_i)) < 4.0
					&& (++(val->fract.i) < (val->fract.i_max)))
			{
				val->fract.tp = val->fract.z_r;
				val->fract.z_r = (val->fract.z_r * val->fract.z_r)
					- (val->fract.z_i * val->fract.z_i) + val->fract.c_r;
				val->fract.z_i = (2.0 * val->fract.z_i * val->fract.tp)
					+ val->fract.c_i;
			}
			if (val->fract.i == val->fract.i_max)
				ft_fill_px(val, (val->fract.x), (val->fract.y), 0);
			else
				ft_fill_px(val, (val->fract.x), (val->fract.y),
					ft_color(val));
		}
	}
}
