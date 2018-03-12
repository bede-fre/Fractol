/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:13:17 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/12 11:11:24 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_val1_burning_ship(t_values *val, double zoom)
{
	val->fract.x1 = -2.0;
	val->fract.x2 = 2.6;
	val->fract.y1 = -1.7;
	val->fract.y2 = 1.7;
	val->fract.i_max = 50.0;
	val->fract.x = -1.0;
	val->fract.img_x = (val->fract.x2 - val->fract.x1) * zoom;
	val->fract.img_y = (val->fract.y2 - val->fract.y1) * zoom;
}

static void	ft_init_val2_burning_ship(t_values *val, double zoom)
{
	val->fract.c_r = (val->fract.x / zoom) + val->fract.x1;
	val->fract.c_i = (val->fract.y / zoom) + val->fract.y1;
	val->fract.i = -1.0;
	val->fract.z_r = 0.0;
	val->fract.z_i = 0.0;
}

void		ft_burning_ship(t_values *val, double var_x, double var_y, double zoom)
{
	(void)var_x;
	(void)var_y;
	ft_init_val1_burning_ship(val, zoom);
	while (++(val->fract.x) < val->fract.img_x)
	{
		val->fract.y = -1.0;
		while (++(val->fract.y) < val->fract.img_y)
		{
			ft_init_val2_burning_ship(val, zoom);
			while (((val->fract.z_r * val->fract.z_r)
				+ (val->fract.z_i * val->fract.z_i)) < 4.0
					&& (++(val->fract.i) < (val->fract.i_max)))
			{
				val->fract.tp = (val->fract.z_r * val->fract.z_r) - (val->fract.z_i * val->fract.z_i) + val->fract.c_r;
				val->fract.z_i = 2.0 * fabs(val->fract.z_r * val->fract.z_i) + val->fract.c_i;
				val->fract.z_r = val->fract.tp;
			}
			if (val->fract.i == val->fract.i_max)
				ft_fill_px(val, (val->fract.x), (val->fract.y), 0);
			else
				ft_fill_px(val, (val->fract.x), (val->fract.y), (val->fract.i * 255.0) * (val->fract.i_max));
		}
	}
}
