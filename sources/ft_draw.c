/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:19:58 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/14 19:27:33 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_mapping(double p_s, double p_e, double mapping, int mouse)
{
	if (mouse == 4 || mouse == 2)
		return (p_s + ((p_e - p_s) * mapping));
	else
		return (p_s + ((p_e - p_s) / mapping));
}

static void		ft_zoom(t_values *val, int x, int y, int mouse)
{
	double	mapping;
	double	m_r;
	double	m_i;

	mapping = (1.0 / val->draw.coef_zoom);
	m_r = (double)x / (val->draw.w_win / (val->fract.x2 - val->fract.x1))
		+ val->fract.x1;
	m_i = (double)y / (val->draw.l_win / (val->fract.y2 - val->fract.y1))
		+ val->fract.y1;
	val->fract.x1 = ft_mapping(m_r, val->fract.x1, mapping, mouse);
	val->fract.x2 = ft_mapping(m_r, val->fract.x2, mapping, mouse);
	val->fract.y1 = ft_mapping(m_i, val->fract.y1, mapping, mouse);
	val->fract.y2 = ft_mapping(m_i, val->fract.y2, mapping, mouse);
}

int				ft_deal_mouse(int mouse, int x, int y, t_values *val)
{
	mlx_clear_window(val->draw.mlx, val->draw.win);
	if (mouse == 5 || mouse == 1)
	{
		val->fract.i_max -= 5.0;
		val->draw.zoom /= val->draw.coef_zoom;
		ft_zoom(val, x, y, mouse);
	}
	if (mouse == 4 || mouse == 2)
	{
		val->fract.i_max += 5.0;
		val->draw.zoom *= val->draw.coef_zoom;
		ft_zoom(val, x, y, mouse);
	}
	ft_choice_fract(val);
	return (0);
}

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

int				ft_deal_key(int key, t_values *val)
{
	if (key == 49)
	{
		ft_values(val);
		val->draw.zoom = 250.0;
		ft_choice_fract(val);
	}
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
	if (key == 92)
	{
		if (val->stop == 0)
			val->stop = 1;
		else
			val->stop = 0;
	}
	ft_set_color(key, val);
	mlx_put_image_to_window(val->draw.mlx, val->draw.win, val->draw.img, 0, 0);
	if (key == 53)
	{
		free(val);
		exit(0);
	}
	return (0);
}
