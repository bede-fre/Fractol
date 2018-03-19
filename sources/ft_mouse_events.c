/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:19:58 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/19 14:48:03 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_mapping(double p_s, double p_e, double mapping, int mouse)
{
	if (mouse == 4)
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
	if (mouse == 5)
	{
		val->fract.i_max -= 5.0;
		val->draw.zoom /= val->draw.coef_zoom;
		ft_zoom(val, x, y, mouse);
	}
	if (mouse == 4)
	{
		val->fract.i_max += 5.0;
		val->draw.zoom *= val->draw.coef_zoom;
		ft_zoom(val, x, y, mouse);
	}
	ft_choice_fract(val);
	return (0);
}
