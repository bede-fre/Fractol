/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gradient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 10:32:33 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/20 12:07:43 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_cl(unsigned char red, unsigned char green, unsigned char blue)
{
	return (red << 16 | green << 8 | blue);
}

int			ft_smooth_gradient(t_values *val)
{
	val->fct.z_n = sqrt(val->fct.z_r * val->fct.z_r + val->fct.z_i
		* val->fct.z_i);
	val->fct.j = val->fct.i - ((log(2.0) / val->fct.z_n) / log(2.0));
	val->fct.col0 = (unsigned char)(sin(0.016 * val->fct.j + 6)
		* 100.0 + 100.0);
	val->fct.col1 = (unsigned char)(sin(0.013 * val->fct.j + 10)
		* 100.0 + 100.0);
	val->fct.col2 = (unsigned char)(sin(0.01 * val->fct.j + 1)
		* 100.0 + 100.0);
	val->fct.color = ft_cl(val->fct.col0, val->fct.col1, val->fct.col2);
	return (val->fct.color);
}

int			ft_smooth_gradient2(t_values *val)
{
	val->fct2.z_n = sqrt(val->fct2.z_r * val->fct2.z_r + val->fct2.z_i
		* val->fct2.z_i);
	val->fct2.j = val->fct2.i - ((log(2.0) / val->fct2.z_n) / log(2.0));
	val->fct2.col0 = (unsigned char)(sin(0.016 * val->fct2.j + 6)
		* 100.0 + 100.0);
	val->fct2.col1 = (unsigned char)(sin(0.013 * val->fct2.j + 10)
		* 100.0 + 100.0);
	val->fct2.col2 = (unsigned char)(sin(0.01 * val->fct2.j + 1)
		* 100.0 + 100.0);
	val->fct2.color = ft_cl(val->fct2.col0, val->fct2.col1, val->fct2.col2);
	return (val->fct2.color);
}
