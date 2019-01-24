/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:19:58 by bede-fre          #+#    #+#             */
/*   Updated: 2019/01/24 16:59:19 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_key_iter(int key, t_values *val)
{
	if (key == KEY_PLUS)
		val->fct.i_max += 10.0;
	if (key == KEY_MINUS)
		val->fct.i_max -= 10.0;
	if (key == KEY_P)
	{
		val->choice = TRICORN;
		ft_values(val);
		ft_tricorn(val);
		mlx_put_image_to_window(val->draw.mlx, val->draw.win, val->draw.img, 0,
		0);
		ft_str_fct(val);
	}
	ft_choice_fct(val);
}

static void		ft_move(int key, t_values *val)
{
	if (key == KEY_LEFT)
	{
		val->fct.x1 -= ((25.0 / val->draw.zoom));
		val->fct.x2 -= ((25.0 / val->draw.zoom));
	}
	if (key == KEY_RIGHT)
	{
		val->fct.x1 += ((25.0 / val->draw.zoom));
		val->fct.x2 += ((25.0 / val->draw.zoom));
	}
	if (key == KEY_DOWN)
	{
		val->fct.y1 += ((25.0 / val->draw.zoom));
		val->fct.y2 += ((25.0 / val->draw.zoom));
	}
	if (key == KEY_UP)
	{
		val->fct.y1 -= ((25.0 / val->draw.zoom));
		val->fct.y2 -= ((25.0 / val->draw.zoom));
	}
	ft_choice_fct(val);
}

static void		ft_set_fctal(int key, t_values *val)
{
	if (key == KEY_8)
	{
		val->choice = MANDELBROT;
		ft_values(val);
		ft_mandelbrot(val);
	}
	if (key == KEY_9)
	{
		val->choice = JULIA;
		ft_values(val);
		ft_julia(val);
		mlx_put_image_to_window(val->draw.mlx, val->draw.win, val->draw.img,
		0, 0);
		mlx_hook(val->draw.win, 6, (1L << 6), ft_mouse_cord, val);
	}
	if (key == KEY_0)
	{
		val->choice = BURNING_SHIP;
		ft_values(val);
		ft_burning_ship(val);
	}
	mlx_put_image_to_window(val->draw.mlx, val->draw.win, val->draw.img, 0, 0);
	ft_str_fct(val);
}

static void		ft_set_color(int key, t_values *val)
{
	if (key == KEY_1)
		val->set = BLACK_AND_WHITE;
	if (key == KEY_2)
		val->set = RED;
	if (key == KEY_3)
		val->set = GREEN;
	if (key == KEY_4)
		val->set = BLUE;
	if (key == KEY_5)
		val->set = PSYCHEDELIC;
	if (key == KEY_6)
		val->set = WHITE_AND_BLACK;
	if (key == KEY_7)
		val->set = SMOOTH_GRADIANT;
	ft_choice_fct(val);
}

int				ft_deal_key(int key, t_values *val)
{
	if (key == KEY_PLUS || key == KEY_MINUS || key == KEY_P)
		ft_key_iter(key, val);
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_DOWN || key == KEY_UP)
		ft_move(key, val);
	if (key == KEY_8 || key == KEY_9 || key == KEY_0 || key == KEY_P)
		ft_set_fctal(key, val);
	if (key == KEY_1 || key == KEY_2 || key == KEY_3 || key == KEY_4
	|| key == KEY_5 || key == KEY_6 || key == KEY_7)
		ft_set_color(key, val);
	if (key == KEY_S)
		val->stop = ((val->stop == 0) ? 1 : 0);
	if (key == KEY_SPACE)
	{
		ft_values(val);
		ft_choice_fct(val);
	}
	if (key == KEY_ECHAP)
	{
		free(val);
		exit(0);
	}
	return (0);
}
