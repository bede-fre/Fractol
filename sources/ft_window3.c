/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:14:54 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/20 10:48:34 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse_cord2(int x, int y, t_values *val)
{
	if (val->stop2 == 0)
	{
		val->fct2.c_r = (double)x / (val->draw.w_win / (3.2)) - 1.6;
		val->fct2.c_i = (double)y / (val->draw.l_win / (2.4)) - 1.2;
	}
	if (val->choice2 == 2)
		ft_julia2(val);
	mlx_put_image_to_window(val->draw.mlx, val->draw.win2, val->draw.img2, 0,
		0);
	ft_str_fct2(val);
	return (0);
}

void	ft_init_image2(t_values *val)
{
	val->draw.win2 = mlx_new_window(val->draw.mlx, val->draw.w_win,
		val->draw.l_win, "Fractol2");
	val->draw.img2 = mlx_new_image(val->draw.mlx, val->draw.w_win,
		val->draw.l_win);
	val->draw.s_px2 = mlx_get_data_addr(val->draw.img2, &val->draw.bpp,
		&val->draw.sz_ln_px, &val->draw.endian);
	ft_choice_fct2(val);
	mlx_mouse_hook(val->draw.win2, ft_deal_mouse2, val);
	mlx_key_hook(val->draw.win2, ft_deal_key2, val);
}
