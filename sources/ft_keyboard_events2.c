/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard_events2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:19:58 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/19 17:02:25 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_key_iter2(int key, t_values *val)
{
	if (key == 24)
		val->fract2.i_max += 10.0;
	if (key == 27)
		val->fract2.i_max -= 10.0;
	ft_choice_fract2(val);
}

static void		ft_move2(int key, t_values *val)
{
	if (key == 123)
	{
		val->fract2.x1 -= ((25.0 / val->draw.zoom2));
		val->fract2.x2 -= ((25.0 / val->draw.zoom2));
	}
	if (key == 124)
	{
		val->fract2.x1 += ((25.0 / val->draw.zoom2));
		val->fract2.x2 += ((25.0 / val->draw.zoom2));
	}
	if (key == 125)
	{
		val->fract2.y1 += ((25.0 / val->draw.zoom2));
		val->fract2.y2 += ((25.0 / val->draw.zoom2));
	}
	if (key == 126)
	{
		val->fract2.y1 -= ((25.0 / val->draw.zoom2));
		val->fract2.y2 -= ((25.0 / val->draw.zoom2));
	}
	ft_choice_fract2(val);
}

static void		ft_set_fractal2(int key, t_values *val)
{
	if (key == 28)
	{
		val->choice2 = 1;
		ft_values2(val);
		ft_mandelbrot2(val);
	}
	if (key == 25)
	{
		val->choice2 = 2;
		ft_values2(val);
		ft_julia2(val);
		mlx_put_image_to_window(val->draw.mlx, val->draw.win3, val->draw.img3,
			0, 0);
		mlx_hook(val->draw.win3, 6, (1L << 6), ft_mouse_cord2, val);
	}
	if (key == 29)
	{
		val->choice2 = 3;
		ft_values2(val);
		ft_burning_ship2(val);
	}
	mlx_put_image_to_window(val->draw.mlx, val->draw.win3, val->draw.img3, 0, 0);
	ft_str_fract2(val);
}

static void		ft_set_color2(int key, t_values *val)
{
	if (key == 18)
		val->set2 = 1;
	if (key == 19)
		val->set2 = 2;
	if (key == 20)
		val->set2 = 3;
	if (key == 21)
		val->set2 = 4;
	if (key == 23)
		val->set2 = 5;
	if (key == 22)
		val->set2 = 6;
	if (key == 26)
		val->set2 = 7;
	ft_choice_fract2(val);
}

int				ft_deal_key2(int key, t_values *val)
{
	if (key == 24 || key == 27)
		ft_key_iter2(key, val);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		ft_move2(key, val);
	if (key == 28 || key == 25 || key == 29)
		ft_set_fractal2(key, val);
	if (key == 18 || key == 19 || key == 20 || key == 21 || key == 23
		|| key == 22 || key == 26)
		ft_set_color2(key, val);
	if (key == 1)
		val->stop2 = ((val->stop2 == 0) ? 1 : 0);
	if (key == 49)
	{
		ft_values2(val);
		ft_choice_fract2(val);
	}
	if (key == 53)
	{
		free(val);
		exit(0);
	}
	return (0);
}
