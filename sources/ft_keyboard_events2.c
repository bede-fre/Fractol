/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:19:58 by bede-fre          #+#    #+#             */
/*   Updated: 2019/01/24 17:01:14 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_key_iter2(int key, t_values *val)
{
	if (key == KEY_PLUS)
		val->fct2.i_max += 10.0;
	if (key == KEY_MINUS)
		val->fct2.i_max -= 10.0;
	if (key == KEY_P)
	{
		val->choice2 = TRICORN;
		ft_values(val);
		ft_tricorn(val);
		mlx_put_image_to_window(val->draw.mlx, val->draw.win2, val->draw.img2,
		0, 0);
		ft_str_fct2(val);
	}
	ft_choice_fct2(val);
}

static void		ft_move2(int key, t_values *val)
{
	if (key == KEY_LEFT)
	{
		val->fct2.x1 -= ((25.0 / val->draw.zoom2));
		val->fct2.x2 -= ((25.0 / val->draw.zoom2));
	}
	if (key == KEY_RIGHT)
	{
		val->fct2.x1 += ((25.0 / val->draw.zoom2));
		val->fct2.x2 += ((25.0 / val->draw.zoom2));
	}
	if (key == KEY_DOWN)
	{
		val->fct2.y1 += ((25.0 / val->draw.zoom2));
		val->fct2.y2 += ((25.0 / val->draw.zoom2));
	}
	if (key == KEY_UP)
	{
		val->fct2.y1 -= ((25.0 / val->draw.zoom2));
		val->fct2.y2 -= ((25.0 / val->draw.zoom2));
	}
	ft_choice_fct2(val);
}

static void		ft_set_fctal2(int key, t_values *val)
{
	if (key == KEY_8)
	{
		val->choice2 = MANDELBROT;
		ft_values2(val);
		ft_mandelbrot2(val);
	}
	if (key == KEY_9)
	{
		val->choice2 = JULIA;
		ft_values2(val);
		ft_julia2(val);
		mlx_put_image_to_window(val->draw.mlx, val->draw.win2, val->draw.img2,
		0, 0);
		mlx_hook(val->draw.win2, 6, (1L << 6), ft_mouse_cord2, val);
	}
	if (key == KEY_0)
	{
		val->choice2 = BURNING_SHIP;
		ft_values2(val);
		ft_burning_ship2(val);
	}
	mlx_put_image_to_window(val->draw.mlx, val->draw.win2, val->draw.img2, 0,
	0);
	ft_str_fct2(val);
}

static void		ft_set_color2(int key, t_values *val)
{
	if (key == KEY_1)
		val->set2 = BLACK_AND_WHITE;
	if (key == KEY_2)
		val->set2 = RED;
	if (key == KEY_3)
		val->set2 = GREEN;
	if (key == KEY_4)
		val->set2 = BLUE;
	if (key == KEY_5)
		val->set2 = PSYCHEDELIC;
	if (key == KEY_6)
		val->set2 = WHITE_AND_BLACK;
	if (key == KEY_7)
		val->set2 = SMOOTH_GRADIANT;
	ft_choice_fct2(val);
}

int				ft_deal_key2(int key, t_values *val)
{
	if (key == KEY_PLUS || key == KEY_MINUS || key == KEY_P)
		ft_key_iter2(key, val);
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_DOWN || key == KEY_UP)
		ft_move2(key, val);
	if (key == KEY_8 || key == KEY_9 || key == KEY_0 || key == KEY_P)
		ft_set_fctal2(key, val);
	if (key == KEY_1 || key == KEY_2 || key == KEY_3 || key == KEY_4
	|| key == KEY_5 || key == KEY_6 || key == KEY_7)
		ft_set_color2(key, val);
	if (key == KEY_S)
		val->stop2 = ((val->stop2 == 0) ? 1 : 0);
	if (key == KEY_SPACE)
	{
		ft_values2(val);
		ft_choice_fct2(val);
	}
	if (key == KEY_ECHAP)
	{
		free(val);
		exit(0);
	}
	return (0);
}
