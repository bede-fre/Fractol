/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:14:54 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/19 17:24:20 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse_cord2(int x, int y, t_values *val)
{
	if (val->stop2 == 0)
	{
		val->fract2.c_r = (double)x / (val->draw.w_win / (3.2)) - 1.6;
		val->fract2.c_i = (double)y / (val->draw.l_win / (2.4)) - 1.2;
	}
	if (val->choice2 == 2)
		ft_julia2(val);
	mlx_put_image_to_window(val->draw.mlx, val->draw.win3, val->draw.img3, 0, 0);
	ft_str_fract2(val);
	return (0);
}

void	ft_init_image2(t_values *val)
{
	val->draw.win3 = mlx_new_window(val->draw.mlx, val->draw.w_win,
		val->draw.l_win, "Fractol2");
	val->draw.img3 = mlx_new_image(val->draw.mlx, val->draw.w_win,
		val->draw.l_win);
	val->draw.s_px3 = mlx_get_data_addr(val->draw.img3, &val->draw.bpp,
		&val->draw.sz_ln_px, &val->draw.endian);
	ft_choice_fract2(val);
}
