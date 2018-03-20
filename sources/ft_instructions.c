/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:07:16 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/20 15:38:48 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_instructions1(t_values *val)
{
	mlx_string_put(val->draw.mlx, val->draw.win3, 230, 15, 0xFF0000,
		"###  Fractol Shortcuts Instructions  ###");
	mlx_string_put(val->draw.mlx, val->draw.win3, 230, 20, 0xFF0000,
		"_______________________________________");
	mlx_string_put(val->draw.mlx, val->draw.win3, 25, 60, 0xFF0000,
		"o Keyboard shortcuts");
	mlx_string_put(val->draw.mlx, val->draw.win3, 50, 85, 0xFF0000,
		"- Color set choice");
	mlx_string_put(val->draw.mlx, val->draw.win3, 75, 100, 0xFF0000,
		"1 : Black & White");
	mlx_string_put(val->draw.mlx, val->draw.win3, 75, 115, 0xFF0000,
		"2 : Red");
	mlx_string_put(val->draw.mlx, val->draw.win3, 75, 130, 0xFF0000,
		"3 : Green");
	mlx_string_put(val->draw.mlx, val->draw.win3, 75, 145, 0xFF0000,
		"4 : Blue");
	mlx_string_put(val->draw.mlx, val->draw.win3, 75, 160, 0xFF0000,
		"5 : Psychedelic");
	mlx_string_put(val->draw.mlx, val->draw.win3, 75, 175, 0xFF0000,
		"6 : White & Black");
	mlx_string_put(val->draw.mlx, val->draw.win3, 75, 190, 0xFF0000,
		"7 : Smooth Gradient");
}

static void	ft_instructions2(t_values *val)
{
	mlx_string_put(val->draw.mlx, val->draw.win3, 50, 220, 0xFF0000,
		"- Fractal set choice");
	mlx_string_put(val->draw.mlx, val->draw.win3, 75, 235, 0xFF0000,
		"8 : Mandelbrot fractal");
	mlx_string_put(val->draw.mlx, val->draw.win3, 75, 250, 0xFF0000,
		"9 : Julia fractal");
	mlx_string_put(val->draw.mlx, val->draw.win3, 75, 265, 0xFF0000,
		"0 : Burning ship fractal");
	mlx_string_put(val->draw.mlx, val->draw.win3, 75, 280, 0xFF0000,
		"P : Tricorn fractal");
	mlx_string_put(val->draw.mlx, val->draw.win3, 50, 310, 0xFF0000,
		"- Moving");
	mlx_string_put(val->draw.mlx, val->draw.win3, 75, 325, 0xFF0000,
		"Left arrow : Move left");
	mlx_string_put(val->draw.mlx, val->draw.win3, 75, 340, 0xFF0000,
		"Right arrow : Move right");
	mlx_string_put(val->draw.mlx, val->draw.win3, 75, 355, 0xFF0000,
		"Top arrow : Move up");
	mlx_string_put(val->draw.mlx, val->draw.win3, 75, 370, 0xFF0000,
		"Bottom arrow : Move down");
}

static void	ft_instructions3(t_values *val)
{
	mlx_string_put(val->draw.mlx, val->draw.win3, 50, 400, 0xFF0000,
		"- Others");
	mlx_string_put(val->draw.mlx, val->draw.win3, 75, 415, 0xFF0000,
		"Space : Reset current fractal");
	mlx_string_put(val->draw.mlx, val->draw.win3, 75, 430, 0xFF0000,
		"S : Stop and start Julia variation");
	mlx_string_put(val->draw.mlx, val->draw.win3, 75, 445, 0xFF0000,
		"- : Decrease maximum iteration");
	mlx_string_put(val->draw.mlx, val->draw.win3, 75, 460, 0xFF0000,
		"+ : Increase maximum iteration");
	mlx_string_put(val->draw.mlx, val->draw.win3, 75, 475, 0xFF0000,
		"Esc : Quit program");
	mlx_string_put(val->draw.mlx, val->draw.win3, 75, 490, 0xFF0000,
		"H : Show/hide Shortcuts instructions");
	mlx_string_put(val->draw.mlx, val->draw.win3, 440, 60, 0xFF0000,
		"o Mouse shortcuts");
	mlx_string_put(val->draw.mlx, val->draw.win3, 465, 85, 0xFF0000,
		"- Mouse wheel : Zoom/Dezoom on");
	mlx_string_put(val->draw.mlx, val->draw.win3, 625, 100, 0xFF0000,
		"mouse cursor");
}

void		ft_display_instructions(t_values *val)
{
	val->draw.win3 = mlx_new_window(val->draw.mlx, val->draw.w_win,
		val->draw.l_win, "Shortcuts instructions");
	val->draw.img3 = mlx_new_image(val->draw.mlx, val->draw.w_win,
		val->draw.l_win);
	val->draw.s_px3 = mlx_get_data_addr(val->draw.img3, &val->draw.bpp,
		&val->draw.sz_ln_px, &val->draw.endian);
	mlx_put_image_to_window(val->draw.mlx, val->draw.win3, val->draw.img3, 0,
		0);
	ft_instructions1(val);
	ft_instructions2(val);
	ft_instructions3(val);
}

void		ft_show_and_hide_help(t_values *val)
{
	val->helpers = ((val->helpers == 0) ? 1 : 0);
	if (val->helpers == 1)
		ft_display_instructions(val);
	else if (val->draw.win3 && val->helpers == 0)
		mlx_destroy_window(val->draw.mlx, val->draw.win3);
}
