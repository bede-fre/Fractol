/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:19:58 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/12 18:19:26 by bede-fre         ###   ########.fr       */
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

static void	ft_move_zoom(int key, t_values *val)
{
	if (key == 35)
		val->draw.zoom += 5;
	if (key == 41)
		val->draw.zoom -= 5;
	if (key == 31)
		val->draw.zoom2 += 5;
	if (key == 37)
		val->draw.zoom2 -= 5;
	if (key == 123)
		val->draw.var_x -= 10;
	if (key == 124)
		val->draw.var_x += 10;
	if (key == 125)
		val->draw.var_y += 10;
	if (key == 126)
		val->draw.var_y -= 10;
	if (key == 0)
		val->draw.var_x2 -= 10;
	if (key == 1)
		val->draw.var_x2 += 10;
	if (key == 2)
		val->draw.var_y2 += 10;
	if (key == 3)
		val->draw.var_y2 -= 10;
}
/*
int			ft_deal_mouse(int mouse, t_values *val)
{
	(void)val;
	ft_putnbr(mouse);
	ft_putstr("\n");
	ft_julia(val, val->draw.var_x, val->draw.var_y, val->draw.zoom);
	mlx_put_image_to_window(val->draw.mlx, val->draw.win, val->draw.img, 0, 0);
	return (0);
}*/
/*
int			ft_deal_mouse2(int mouse, t_values *val)
{
	(void)val;
	ft_putnbr(mouse);
	ft_putstr("\n");
	ft_julia(val, val->draw.var_x, val->draw.var_y, val->draw.zoom);
	mlx_put_image_to_window(val->draw.mlx, val->draw.win2, val->draw.img2, 0, 0);
	return (0);
}*/

int			ft_deal_key(int key, t_values *val)
{
	mlx_clear_window(val->draw.mlx, val->draw.win);
	mlx_destroy_image(val->draw.mlx, val->draw.img);
	val->draw.img = mlx_new_image(val->draw.mlx, val->draw.w_win,
		val->draw.l_win);
	val->draw.s_px = mlx_get_data_addr(val->draw.img, &val->draw.bpp,
		&val->draw.sz_ln_px, &val->draw.endian);
	if (key == 123 || key == 124 || key == 125 || key == 126 || key == 35
		|| key == 41)
		ft_move_zoom(key, val);
	if (val->choice1 == 1)
		ft_mandelbrot(val, val->draw.var_x, val->draw.var_y, val->draw.zoom);
	if (val->choice1 == 2)
		ft_julia(val, val->draw.var_x, val->draw.var_y, val->draw.zoom);
	if (val->choice1 == 3)
		ft_burning_ship(val, val->draw.var_x, val->draw.var_y, val->draw.zoom);
	mlx_put_image_to_window(val->draw.mlx, val->draw.win, val->draw.img, 0, 0);
	if (key == 53)
		exit(0);
	return (0);
}

int			ft_deal_key2(int key, t_values *val)
{
	mlx_clear_window(val->draw.mlx, val->draw.win2);
	mlx_destroy_image(val->draw.mlx, val->draw.img2);
	val->draw.img2 = mlx_new_image(val->draw.mlx, val->draw.w_win,
		val->draw.l_win);
	val->draw.s_px = mlx_get_data_addr(val->draw.img2, &val->draw.bpp,
			&val->draw.sz_ln_px, &val->draw.endian);
	if (key == 1 || key == 2 || key == 3 || key == 0 || key == 37
		|| key == 31)
		ft_move_zoom(key, val);
	if (val->choice2 == 1)
		ft_mandelbrot(val, val->draw.var_x2, val->draw.var_y2, val->draw.zoom2);
	if (val->choice2 == 2)
		ft_julia(val, val->draw.var_x2, val->draw.var_y2, val->draw.zoom2);
	if (val->choice2 == 3)
		ft_burning_ship(val, val->draw.var_x2, val->draw.var_y2, val->draw.zoom2);
	mlx_put_image_to_window(val->draw.mlx, val->draw.win2, val->draw.img2, 0, 0);
	if (key == 53)
		exit(0);
	return (0);
}
