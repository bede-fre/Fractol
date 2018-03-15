/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:19:58 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/15 18:24:54 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_set_color(int key, t_values *val)
{
	if (key == 86)
	{
		val->set = 1;
		ft_choice_fract(val);
	}
	if (key == 87)
	{
		val->set = 2;
		ft_choice_fract(val);
	}
	if (key == 88)
	{
		val->set = 3;
		ft_choice_fract(val);
	}
	if (key == 89)
	{
		val->set = 4;
		ft_choice_fract(val);
	}
	if (key == 82)
	{
		val->set = 5;
		ft_choice_fract(val);
	}
}

static void		ft_set_fractal(int key, t_values *val)
{
	if (key == 83)
	{
		mlx_clear_window(val->draw.mlx, val->draw.win);
		val->choice = 1;
		ft_values(val);
		ft_mandelbrot(val);
	}
	if (key == 84)
	{
		mlx_clear_window(val->draw.mlx, val->draw.win);
		val->choice = 2;
		ft_values(val);
		ft_julia(val);
		mlx_put_image_to_window(val->draw.mlx, val->draw.win, val->draw.img,
			0, 0);
		mlx_hook(val->draw.win, 6, (1L << 6), ft_mouse_cord, val);
	}
	if (key == 85)
	{
		mlx_clear_window(val->draw.mlx, val->draw.win);
		val->choice = 3;
		ft_values(val);
		ft_burning_ship(val);
	}
	mlx_put_image_to_window(val->draw.mlx, val->draw.win, val->draw.img, 0, 0);
	ft_str_fract(val);
}

int				ft_deal_key(int key, t_values *val)
{
	mlx_clear_window(val->draw.mlx, val->draw.win);
	if (key == 123)
	{
		val->draw.var_x -= 10.0;
		ft_choice_fract(val);
	}
	if (key == 124)
	{
		val->draw.var_x += 10.0;
		ft_choice_fract(val);
	}
	if (key == 125)
	{
		val->draw.var_y += 10.0;
		ft_choice_fract(val);
	}
	if (key == 126)
	{
		val->draw.var_y -= 10.0;
		ft_choice_fract(val);
	}
	if (key == 49)
	{
		ft_values(val);
		val->draw.zoom = 250.0;
		val->draw.var_x = val->draw.con_x;
		val->draw.var_y = val->draw.con_y;
		ft_choice_fract(val);
	}
	if (key == 83 || key == 84 || key == 85)
		ft_set_fractal(key, val);
	if (key == 92)
		val->stop = ((val->stop == 0) ? 1 : 0);
	ft_set_color(key, val);
	if (key == 53)
	{
		free(val);
		exit(0);
	}
	return (0);
}
