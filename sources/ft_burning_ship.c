/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:13:17 by bede-fre          #+#    #+#             */
/*   Updated: 2019/01/24 16:47:41 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_val_burning_ship(t_values *val)
{
	val->fct.c_r = (val->fct.x / val->draw.zoom) + val->fct.x1;
	val->fct.c_i = (val->fct.y / val->draw.zoom) + val->fct.y1;
	val->fct.i = -1.0;
	val->fct.z_r = 0.0;
	val->fct.z_i = 0.0;
}

static void	ft_init_val_burning_ship2(t_values *val)
{
	val->fct2.c_r = (val->fct2.x / val->draw.zoom2) + val->fct2.x1;
	val->fct2.c_i = (val->fct2.y / val->draw.zoom2) + val->fct2.y1;
	val->fct2.i = -1.0;
	val->fct2.z_r = 0.0;
	val->fct2.z_i = 0.0;
}

void		ft_burning_ship(t_values *val)
{
	val->fct.x = -1.0;
	while (++(val->fct.x) < val->draw.w_win)
	{
		val->fct.y = -1.0;
		while (++(val->fct.y) < val->draw.l_win)
		{
			ft_init_val_burning_ship(val);
			while (((val->fct.z_r * val->fct.z_r)
			+ (val->fct.z_i * val->fct.z_i)) < 4.0
			&& (++(val->fct.i) < (val->fct.i_max)))
			{
				val->fct.tp = (val->fct.z_r * val->fct.z_r)
				- (val->fct.z_i * val->fct.z_i) + val->fct.c_r;
				val->fct.z_i = 2.0 * fabs(val->fct.z_r * val->fct.z_i)
				+ val->fct.c_i;
				val->fct.z_r = val->fct.tp;
			}
			if (val->fct.i == val->fct.i_max)
				ft_fill_px(val, (val->fct.x), (val->fct.y),
				(val->set == WHITE_AND_BLACK) ? WHITE : 0);
			else
				ft_fill_px(val, (val->fct.x), (val->fct.y), (val->set ==
				SMOOTH_GRADIANT) ? ft_smooth_gradient(val) : ft_color(val));
		}
	}
}

void		ft_burning_ship2(t_values *val)
{
	val->fct2.x = -1.0;
	while (++(val->fct2.x) < val->draw.w_win)
	{
		val->fct2.y = -1.0;
		while (++(val->fct2.y) < val->draw.l_win)
		{
			ft_init_val_burning_ship2(val);
			while (((val->fct2.z_r * val->fct2.z_r)
			+ (val->fct2.z_i * val->fct2.z_i)) < 4.0
			&& (++(val->fct2.i) < (val->fct2.i_max)))
			{
				val->fct2.tp = (val->fct2.z_r * val->fct2.z_r)
				- (val->fct2.z_i * val->fct2.z_i) + val->fct2.c_r;
				val->fct2.z_i = 2.0 * fabs(val->fct2.z_r * val->fct2.z_i)
				+ val->fct2.c_i;
				val->fct2.z_r = val->fct2.tp;
			}
			if (val->fct2.i == val->fct2.i_max)
				ft_fill_px2(val, (val->fct2.x), (val->fct2.y), (val->set2 ==
				WHITE_AND_BLACK) ? WHITE : 0);
			else
				ft_fill_px2(val, (val->fct2.x), (val->fct2.y), (val->set2 ==
				SMOOTH_GRADIANT) ? ft_smooth_gradient2(val) : ft_color2(val));
		}
	}
}
