/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:19:58 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/16 14:58:57 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_iter(int key, t_values *val)
{
	if (key == 69)
		val->fract.i_max += 10.0;
	if (key == 78)
		val->fract.i_max -= 10.0;
	ft_choice_fract(val);
}

static void		ft_move(int key, t_values *val)
{
	if (key == 123)
	{
		val->fract.x1 += ((25.0 / val->draw.zoom));
		val->fract.x2 += ((25.0 / val->draw.zoom));
	}
	if (key == 124)
	{
		val->fract.x1 -= ((25.0 / val->draw.zoom));
		val->fract.x2 -= ((25.0 / val->draw.zoom));
	}
	if (key == 125)
	{
		val->fract.y1 -= ((25.0 / val->draw.zoom));
		val->fract.y2 -= ((25.0 / val->draw.zoom));
	}
	if (key == 126)
	{
		val->fract.y1 += ((25.0 / val->draw.zoom));
		val->fract.y2 += ((25.0 / val->draw.zoom));
	}
	ft_choice_fract(val);
}

static void		ft_set_fractal(int key, t_values *val)
{
	if (key == 83)
	{
		val->choice = 1;
		ft_values(val);
		ft_mandelbrot(val);
	}
	if (key == 84)
	{
		val->choice = 2;
		ft_values(val);
		ft_julia(val);
		mlx_put_image_to_window(val->draw.mlx, val->draw.win, val->draw.img,
			0, 0);
		mlx_hook(val->draw.win, 6, (1L << 6), ft_mouse_cord, val);
	}
	if (key == 85)
	{
		val->choice = 3;
		ft_values(val);
		ft_burning_ship(val);
	}
	mlx_put_image_to_window(val->draw.mlx, val->draw.win, val->draw.img, 0, 0);
	ft_str_fract(val);
}

static void		ft_set_color(int key, t_values *val)
{
	if (key == 18)
		val->set = 1;
	if (key == 19)
		val->set = 2;
	if (key == 20)
		val->set = 3;
	if (key == 21)
		val->set = 4;
	if (key == 23)
		val->set = 5;
	if (key == 22)
		val->set = 6;
	ft_choice_fract(val);
}

int				ft_deal_key(int key, t_values *val)
{
	if (key == 69 || key == 78)
		ft_iter(key, val);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		ft_move(key, val);
	if (key == 83 || key == 84 || key == 85)
		ft_set_fractal(key, val);
	if (key == 18 || key == 19 || key == 20 || key == 21 || key == 23
		|| key == 22)
		ft_set_color(key, val);
	if (key == 92)
		val->stop = ((val->stop == 0) ? 1 : 0);
	if (key == 49)
	{
		ft_values(val);
		ft_choice_fract(val);
	}
	if (key == 53)
	{
		free(val);
		exit(0);
	}
	return (0);
}
