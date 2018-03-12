/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:13:17 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/12 18:28:04 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_val1_julia(t_values *val, double zoom)
{
	val->fract2.x1 = -1.6;
	val->fract2.x2 = 1.6;
	val->fract2.y1 = -1.2;
	val->fract2.y2 = 1.2;
	val->fract2.i_max = 150.0;
	val->fract2.x = -1.0;
	val->fract2.img_x = (val->fract2.x2 - val->fract2.x1) * zoom;
	val->fract2.img_y = (val->fract2.y2 - val->fract2.y1) * zoom;
}

static void	ft_init_val2_julia(t_values *val, double zoom)
{
	val->fract2.i = -1.0;
	val->fract2.z_r = (val->fract2.x / zoom) + val->fract2.x1;
	val->fract2.z_i = (val->fract2.y / zoom) + val->fract2.y1;
}

void		ft_julia(t_values *val, double var_x, double var_y, double zoom)
{
	(void)var_x;
	(void)var_y;
	ft_init_val1_julia(val, zoom);
	while (++(val->fract2.x) < val->fract2.img_x)
	{
		val->fract2.y = -1.0;
		while (++(val->fract2.y) < val->fract2.img_y)
		{
			ft_init_val2_julia(val, zoom);
			while (((val->fract2.z_r * val->fract2.z_r)
				+ (val->fract2.z_i * val->fract2.z_i)) < 4.0
					&& (++(val->fract2.i) < (val->fract2.i_max)))
			{
				val->fract2.tp = val->fract2.z_r;
				val->fract2.z_r = (val->fract2.z_r * val->fract2.z_r)
					- (val->fract2.z_i * val->fract2.z_i) + val->fract2.c_r;
				val->fract2.z_i = (2.0 * val->fract2.z_i * val->fract2.tp)
					+ val->fract2.c_i;
			}
			if (val->fract2.i == val->fract2.i_max)
				ft_fill_px(val, (val->fract2.x), (val->fract2.y), 0);
			else
				ft_fill_px(val, (val->fract2.x), (val->fract2.y), (val->fract2.i
					* 255.0) * val->fract2.i_max);
		}
	}
}
