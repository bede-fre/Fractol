/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_values_and_color2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:23:23 by bede-fre          #+#    #+#             */
/*   Updated: 2019/01/24 16:54:53 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_values2(t_values *val)
{
	if (val->choice2 == MANDELBROT || val->choice2 == TRICORN)
	{
		val->fct2.x1 = -2.1;
		val->fct2.x2 = 1.1;
		val->fct2.y1 = -1.2;
		val->fct2.y2 = 1.2;
		val->fct2.i_max = 50.0;
	}
	if (val->choice2 == JULIA)
	{
		val->fct2.x1 = -1.6;
		val->fct2.x2 = 1.6;
		val->fct2.y1 = -1.2;
		val->fct2.y2 = 1.2;
		val->fct2.i_max = 150.0;
	}
	if (val->choice2 == BURNING_SHIP)
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
	if (val->set2 == BLACK_AND_WHITE)
	{
		val->red2 = (255 - (int)(val->fct2.i * 255.0 / val->fct2.i_max));
		val->green2 = (255 - (int)(val->fct2.i * 255.0 / val->fct2.i_max));
		val->blue2 = (255 - (int)(val->fct2.i * 255.0 / val->fct2.i_max));
	}
	if (val->set2 == RED)
		val->red2 = (int)(val->fct2.i * 255.0 / val->fct2.i_max);
	if (val->set2 == GREEN)
		val->green2 = (int)(val->fct2.i * 255.0 / val->fct2.i_max);
	if (val->set2 == BLUE)
		val->blue2 = (int)(val->fct2.i * 255.0 / val->fct2.i_max);
	if (val->set2 == PSYCHEDELIC)
		val->blue2 = (int)(val->fct2.i * 255.0) * (val->fct2.i_max);
	if (val->set2 == WHITE_AND_BLACK)
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
	if (val->choice2 == MANDELBROT)
		mlx_string_put(val->draw.mlx, val->draw.win2, 685, 10, 0xFF0000,
		"Mandelbrot");
	if (val->choice2 == JULIA)
		mlx_string_put(val->draw.mlx, val->draw.win2, 735, 10, 0xFF0000,
		"Julia");
	if (val->choice2 == BURNING_SHIP)
		mlx_string_put(val->draw.mlx, val->draw.win2, 665, 10, 0xFF0000,
		"Burning_ship");
	if (val->choice2 == TRICORN)
		mlx_string_put(val->draw.mlx, val->draw.win2, 715, 10, 0xFF0000,
		"Tricorn");
}

void		ft_choice_fct2(t_values *val)
{
	if (val->choice2 == MANDELBROT)
		ft_mandelbrot2(val);
	if (val->choice2 == JULIA)
		ft_julia2(val);
	if (val->choice2 == BURNING_SHIP)
		ft_burning_ship2(val);
	if (val->choice2 == TRICORN)
		ft_tricorn2(val);
	mlx_put_image_to_window(val->draw.mlx, val->draw.win2, val->draw.img2, 0,
	0);
	ft_str_fct2(val);
}
