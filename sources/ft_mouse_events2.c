/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_events2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:19:58 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/19 17:16:37 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_mapping2(double p_s, double p_e, double mapping, int mouse)
{
	if (mouse == 4)
		return (p_s + ((p_e - p_s) * mapping));
	else
		return (p_s + ((p_e - p_s) / mapping));
}

static void		ft_zoom2(t_values *val, int x, int y, int mouse)
{
	double	mapping;
	double	m_r;
	double	m_i;

	mapping = (1.0 / val->draw.coef_zoom2);
	m_r = (double)x / (val->draw.w_win / (val->fract2.x2 - val->fract2.x1))
		+ val->fract2.x1;
	m_i = (double)y / (val->draw.l_win / (val->fract2.y2 - val->fract2.y1))
		+ val->fract2.y1;
	val->fract2.x1 = ft_mapping2(m_r, val->fract2.x1, mapping, mouse);
	val->fract2.x2 = ft_mapping2(m_r, val->fract2.x2, mapping, mouse);
	val->fract2.y1 = ft_mapping2(m_i, val->fract2.y1, mapping, mouse);
	val->fract2.y2 = ft_mapping2(m_i, val->fract2.y2, mapping, mouse);
}

int				ft_deal_mouse2(int mouse, int x, int y, t_values *val)
{
	mlx_clear_window(val->draw.mlx, val->draw.win3);
	if (mouse == 5)
	{
		val->fract2.i_max -= 5.0;
		val->draw.zoom2 /= val->draw.coef_zoom2;
		ft_zoom2(val, x, y, mouse);
	}
	if (mouse == 4)
	{
		val->fract2.i_max += 5.0;
		val->draw.zoom2 *= val->draw.coef_zoom2;
		ft_zoom2(val, x, y, mouse);
	}
	ft_choice_fract2(val);
	return (0);
}
