/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:13:17 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/08 16:15:00 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(t_values *val)
{
	double	x;
	double	x1;
	double	x2;
	double	y;
	double	y1;
	double	y2;
	double	iter_max;
	double	img_x;
	double	img_y;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	i;
	double	tmp;

	x1 = -2.1;
	x2 = 0.6;
	y1 = -1.2;
	y2 = 1.2;
	iter_max = 50.0;
	x = -1.0;
	img_x = (x2 - x1) * val->draw.zoom;
	img_y = (y2 - y1) * val->draw.zoom;

	while (++x < img_x)
	{
		y = -1;
		while (++y < img_y)
		{
			c_r = (x / val->draw.zoom) + x1;
			c_i = (y / val->draw.zoom) + y1;
			i = -1;
			z_r = 0.0;
			z_i = 0.0;
			while (((z_r * z_r) + (z_i * z_i)) < 4.0 && (++i < iter_max))
			{
				tmp = z_r;
				z_r = (z_r * z_r) - (z_i * z_i) + c_r;
				z_i = (2.0 * z_i * tmp) + c_i;
			}
			if (i == iter_max)
				ft_fill_px(val, x, y, (i * 255) / iter_max);
			//	ft_fill_px(val, x, y, 16711680);
			else
				ft_fill_px(val, x, y, 0);
		}
	}
}
