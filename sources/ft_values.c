/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_values.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:23:23 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/13 17:32:52 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	ft_values(t_values *val)
{
	if (val->choice == 1)
	{
		val->fract.x1 = -2.1;
		val->fract.x2 = 1.1;
		val->fract.y1 = -1.2;
		val->fract.y2 = 1.2;
		val->fract.i_max = 50.0;
	}
	if (val->choice == 2)
	{
		val->fract.x1 = -1.6;
		val->fract.x2 = 1.6;
		val->fract.y1 = -1.2;
		val->fract.y2 = 1.2;
		val->fract.i_max = 150.0;
	}
	if (val->choice == 3)
	{
		val->fract.x1 = -2.0;
		val->fract.x2 = 1.2;
		val->fract.y1 = -1.7;
		val->fract.y2 = 0.7;
		val->fract.i_max = 50.0;
	}
}
