/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:13:17 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/19 17:25:52 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_val2_burning_ship2(t_values *val)
{
	val->fract2.c_r = (val->fract2.x / val->draw.zoom2) + val->fract2.x1;
	val->fract2.c_i = (val->fract2.y / val->draw.zoom2) + val->fract2.y1;
	val->fract2.i = -1.0;
	val->fract2.z_r = 0.0;
	val->fract2.z_i = 0.0;
}

void		ft_burning_ship2(t_values *val)
{
	val->fract2.x = -1.0;
	while (++(val->fract2.x) < val->draw.w_win)
	{
		val->fract2.y = -1.0;
		while (++(val->fract2.y) < val->draw.l_win)
		{
			ft_init_val2_burning_ship2(val);
			while (((val->fract2.z_r * val->fract2.z_r)
				+ (val->fract2.z_i * val->fract2.z_i)) < 4.0
					&& (++(val->fract2.i) < (val->fract2.i_max)))
			{
				val->fract2.tp = (val->fract2.z_r * val->fract2.z_r)
					- (val->fract2.z_i * val->fract2.z_i) + val->fract2.c_r;
				val->fract2.z_i = 2.0 * fabs(val->fract2.z_r * val->fract2.z_i)
					+ val->fract2.c_i;
				val->fract2.z_r = val->fract2.tp;
			}
			if (val->fract2.i == val->fract2.i_max)
				ft_fill_px2(val, (val->fract2.x), (val->fract2.y), (val->set2 == 6)
					? 0XFFFFFF : 0);
			else
				ft_fill_px2(val, (val->fract2.x), (val->fract2.y), (val->set2 == 7)
					? ft_smooth_gradient2(val) : ft_color2(val));
		}
	}
}
