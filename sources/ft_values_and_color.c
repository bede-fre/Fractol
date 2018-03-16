/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_values_and_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:23:23 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/16 12:34:03 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_values(t_values *val)
{
	if (val->choice == 1)
	{
		val->fract.x1 = -2.1;
		val->fract.x2 = 1.1;
		val->fract.y1 = -1.2;
		val->fract.y2 = 1.2;
		val->fract.i_max = 50.0;
	}
	if (val->choice == 2)
	{
		val->fract.x1 = -1.6;
		val->fract.x2 = 1.6;
		val->fract.y1 = -1.2;
		val->fract.y2 = 1.2;
		val->fract.i_max = 150.0;
	}
	if (val->choice == 3)
	{
		val->fract.x1 = -2.0;
		val->fract.x2 = 1.2;
		val->fract.y1 = -1.7;
		val->fract.y2 = 0.7;
		val->fract.i_max = 50.0;
	}
	val->draw.zoom = 250.0;
}

int			ft_color(t_values *val)
{
	int	red;
	int	green;
	int	blue;

	red = 0;
	green = 0;
	blue = 0;
	if (val->set == 1)
	{
		red = (255 - (int)(val->fract.i * 255.0 / val->fract.i_max));
		green = (255 - (int)(val->fract.i * 255.0 / val->fract.i_max));
		blue = (255 - (int)(val->fract.i * 255.0 / val->fract.i_max));
	}
	if (val->set == 2)
		red = (int)(val->fract.i * 255.0 / val->fract.i_max);
	if (val->set == 3)
		green = (int)(val->fract.i * 255.0 / val->fract.i_max);
	if (val->set == 4)
		blue = (int)(val->fract.i * 255.0 / val->fract.i_max);
	if (val->set == 5)
		blue = (int)(val->fract.i * 255.0) * (val->fract.i_max);
	return (red << 16 | green << 8 | blue);
}

void		ft_fill_px(t_values *val, int x, int y, int color)
{
	int		px;

	px = (x * (val->draw.bpp) / 8) + (y * val->draw.sz_ln_px);
	if (px < 0 || x >= (val->draw.w_win) || y >= (val->draw.l_win) ||
		x < 0 || y < 0)
		return ;
	val->draw.s_px[px] = (unsigned char)(color);
	val->draw.s_px[px + 1] = (unsigned char)(color >> 8);
	val->draw.s_px[px + 2] = (unsigned char)(color >> 16);
	val->draw.s_px[px + 3] = (unsigned char)(color >> 24);
}

void		ft_str_fract(t_values *val)
{
	if (val->choice == 1)
	{
		mlx_string_put(val->draw.mlx, val->draw.win, 685, 10, 0xFF0000,
			"Mandelbrot");
	}
	if (val->choice == 2)
	{
		mlx_string_put(val->draw.mlx, val->draw.win, 735, 10, 0xFF0000,
			"Julia");
	}
	if (val->choice == 3)
	{
		mlx_string_put(val->draw.mlx, val->draw.win, 665, 10, 0xFF0000,
				"Burning_ship");
	}
}

void		ft_choice_fract(t_values *val)
{
	if (val->choice == 1)
		ft_mandelbrot(val);
	if (val->choice == 2)
		ft_julia(val);
	if (val->choice == 3)
		ft_burning_ship(val);
	mlx_put_image_to_window(val->draw.mlx, val->draw.win, val->draw.img, 0, 0);
	ft_str_fract(val);
}
