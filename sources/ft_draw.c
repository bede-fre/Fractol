/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:19:58 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/13 17:15:54 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

double	ft_mapping(double p_s, double p_e, double mapping, int mouse)
{
	if (mouse == 4)
		return (p_s + ((p_e - p_s) * mapping));
	else
		return (p_s + ((p_e - p_s) / mapping));
}

void	ft_zoom(t_values *val, int x, int y, int mouse, double zoom)
{
	double	mapping;
	double	m_r;
	double	m_i;

	mapping = (1.0 / zoom);
	m_r = (double)x / (val->draw.w_win / (val->fract.x2 - val->fract.x1)) + val->fract.x1;
	m_i = (double)y / (val->draw.l_win / (val->fract.y2 - val->fract.y1)) + val->fract.y1;
	val->fract.x1 = ft_mapping(m_r, val->fract.x1, mapping, mouse);
	val->fract.x2 = ft_mapping(m_r, val->fract.x2, mapping, mouse);
	val->fract.y1 = ft_mapping(m_i, val->fract.y1, mapping, mouse);
	val->fract.y2 = ft_mapping(m_i, val->fract.y2, mapping, mouse);
}

int			ft_deal_mouse(int mouse, int x, int y, t_values *val)
{
//	mlx_destroy_image(val->draw.mlx, val->draw.img);
//	val->draw.img = mlx_new_image(val->draw.mlx, val->draw.w_win, val->draw.l_win);
//	val->draw.s_px = mlx_get_data_addr(val->draw.img, &val->draw.bpp, &val->draw.sz_ln_px, &val->draw.endian);
	if (mouse == 5)
	{
		val->fract.i_max -= 5.0;
		val->draw.zoom /= 1.5;
		ft_zoom(val, x, y, mouse, 1.5);
	}
	if (mouse == 4)
	{
		val->fract.i_max += 5.0;
		val->draw.zoom *= 1.5;
		ft_zoom(val, x, y, mouse, 1.5);
	}
	if (val->choice == 1)
		ft_mandelbrot(val);
	if (val->choice == 2)
		ft_julia(val);
	if (val->choice == 3)
		ft_burning_ship(val);
	mlx_put_image_to_window(val->draw.mlx, val->draw.win, val->draw.img, 0, 0);
	return (0);
}

int			ft_deal_key(int key, t_values *val)
{
	(void)val;
	if (key == 53)
		exit(0);
	return (0);
}
