/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_values_and_color2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:23:23 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/20 11:03:28 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_values2(t_values *val)
{
	if (val->choice2 == 1)
	{
		val->fct2.x1 = -2.1;
		val->fct2.x2 = 1.1;
		val->fct2.y1 = -1.2;
		val->fct2.y2 = 1.2;
		val->fct2.i_max = 50.0;
	}
	if (val->choice2 == 2)
	{
		val->fct2.x1 = -1.6;
		val->fct2.x2 = 1.6;
		val->fct2.y1 = -1.2;
		val->fct2.y2 = 1.2;
		val->fct2.i_max = 150.0;
	}
	if (val->choice2 == 3)
	{
		val->fct2.x1 = -2.0;
		val->fct2.x2 = 1.2;
		val->fct2.y1 = -1.7;
		val->fct2.y2 = 0.7;
		val->fct2.i_max = 50.0;
	}
	val->draw.zoom2 = 250.0;
}

int			ft_color2(t_values *val)
{
	val->red2 = 0;
	val->green2 = 0;
	val->blue2 = 0;
	if (val->set2 == 1)
	{
		val->red2 = (255 - (int)(val->fct2.i * 255.0 / val->fct2.i_max));
		val->green2 = (255 - (int)(val->fct2.i * 255.0 / val->fct2.i_max));
		val->blue2 = (255 - (int)(val->fct2.i * 255.0 / val->fct2.i_max));
	}
	if (val->set2 == 2)
		val->red2 = (int)(val->fct2.i * 255.0 / val->fct2.i_max);
	if (val->set2 == 3)
		val->green2 = (int)(val->fct2.i * 255.0 / val->fct2.i_max);
	if (val->set2 == 4)
		val->blue2 = (int)(val->fct2.i * 255.0 / val->fct2.i_max);
	if (val->set2 == 5)
		val->blue2 = (int)(val->fct2.i * 255.0) * (val->fct2.i_max);
	if (val->set2 == 6)
	{
		val->red2 = (int)(val->fct2.i * 255.0 / val->fct2.i_max);
		val->green2 = (int)(val->fct2.i * 255.0 / val->fct2.i_max);
		val->blue2 = (int)(val->fct2.i * 255.0 / val->fct2.i_max);
	}
	return (val->red2 << 16 | val->green2 << 8 | val->blue2);
}

void		ft_fill_px2(t_values *val, int x, int y, int color)
{
	int		px;

	px = (x * (val->draw.bpp) / 8) + (y * val->draw.sz_ln_px);
	if (px < 0 || x >= (val->draw.w_win) || y >= (val->draw.l_win) ||
		x < 0 || y < 0)
		return ;
	val->draw.s_px2[px] = (unsigned char)(color);
	val->draw.s_px2[px + 1] = (unsigned char)(color >> 8);
	val->draw.s_px2[px + 2] = (unsigned char)(color >> 16);
	val->draw.s_px2[px + 3] = (unsigned char)(color >> 24);
}

void		ft_str_fct2(t_values *val)
{
	if (val->choice2 == 1)
		mlx_string_put(val->draw.mlx, val->draw.win2, 685, 10, 0xFF0000,
			"Mandelbrot");
	if (val->choice2 == 2)
		mlx_string_put(val->draw.mlx, val->draw.win2, 735, 10, 0xFF0000,
			"Julia");
	if (val->choice2 == 3)
		mlx_string_put(val->draw.mlx, val->draw.win2, 665, 10, 0xFF0000,
			"Burning_ship");
}

void		ft_choice_fct2(t_values *val)
{
	if (val->choice2 == 1)
		ft_mandelbrot2(val);
	if (val->choice2 == 2)
		ft_julia2(val);
	if (val->choice2 == 3)
		ft_burning_ship2(val);
	mlx_put_image_to_window(val->draw.mlx, val->draw.win2, val->draw.img2, 0,
		0);
	ft_str_fct2(val);
}
