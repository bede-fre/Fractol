/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gradient2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 10:32:33 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/19 17:05:03 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_cl2(unsigned char red, unsigned char green, unsigned char blue,
	unsigned char alpha)
{
	(void)alpha;
	return (red << 16 | green << 8 | blue);
}

int			ft_smooth_gradient2(t_values *val)
{
	val->fract2.z_n = sqrt(val->fract2.z_r * val->fract2.z_r
		+ val->fract2.z_i * val->fract2.z_i);
	val->fract2.continuous_index = val->fract2.i
		- ((log(2.0) / val->fract2.z_n) / log(2.0));
	val->fract2.channel0 = (unsigned char)(sin(0.016
		* val->fract2.continuous_index + 6) * 100.0 + 100.0);
	val->fract2.channel1 = (unsigned char)(sin(0.013
		* val->fract2.continuous_index + 10) * 100.0 + 100.0);
	val->fract2.channel2 = (unsigned char)(sin(0.01
		* val->fract2.continuous_index + 1) * 100.0 + 100.0);
	val->fract2.channel3 = 0;
	val->fract2.color = ft_cl2(val->fract2.channel0, val->fract2.channel1,
		val->fract2.channel2, val->fract2.channel3);
	return (val->fract2.color);
}
