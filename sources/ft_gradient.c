/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gradient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 10:32:33 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/19 13:10:24 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_cl(unsigned char red, unsigned char green, unsigned char blue,
	unsigned char alpha)
{
	(void)alpha;
	return (red << 16 | green << 8 | blue);
}

int			ft_smooth_gradient(t_values *val)
{
	val->fract.z_n = sqrt(val->fract.z_r * val->fract.z_r
		+ val->fract.z_i * val->fract.z_i);
	val->fract.continuous_index = val->fract.i
		- ((log(2.0) / val->fract.z_n) / log(2.0));
	val->fract.channel0 = (unsigned char)(sin(0.016
		* val->fract.continuous_index + 6) * 100.0 + 100.0);
	val->fract.channel1 = (unsigned char)(sin(0.013
		* val->fract.continuous_index + 10) * 100.0 + 100.0);
	val->fract.channel2 = (unsigned char)(sin(0.01
		* val->fract.continuous_index + 1) * 100.0 + 100.0);
	val->fract.channel3 = 0;
	val->fract.color = ft_cl(val->fract.channel0, val->fract.channel1,
		val->fract.channel2, val->fract.channel3);
	return (val->fract.color);
}
