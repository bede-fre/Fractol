/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:14:54 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/20 15:30:20 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_usage(t_values *val)
{
	if (val)
		free(val);
	ft_putendl_fd("Usage : ./fractol choice_fractal_1 choice_fractal_2", 2);
	ft_putendl_fd("    Mandelbrot -> 1", 2);
	ft_putendl_fd("    Julia -> 2", 2);
	ft_putendl_fd("    Burning_ship -> 3", 2);
	exit(1);
}

static void		ft_params_window(t_values *val)
{
	val->draw.l_win = 600.0;
	val->draw.w_win = 800.0;
	val->draw.zoom = 250.0;
	val->draw.zoom2 = 250.0;
	val->draw.coef_zoom = 1.25;
	val->draw.coef_zoom2 = 1.25;
	val->stop = 0;
	val->stop2 = 0;
	val->set = 1;
	val->set2 = 1;
	val->helpers = 0;
}

int				ft_mouse_cord(int x, int y, t_values *val)
{
	if (val->stop == 0)
	{
		val->fct.c_r = (double)x / (val->draw.w_win / (3.2)) - 1.6;
		val->fct.c_i = (double)y / (val->draw.l_win / (2.4)) - 1.2;
	}
	if (val->choice == 2)
		ft_julia(val);
	mlx_put_image_to_window(val->draw.mlx, val->draw.win, val->draw.img, 0, 0);
	ft_str_fct(val);
	return (0);
}

static void		ft_init_image(t_values *val)
{
	val->draw.win = mlx_new_window(val->draw.mlx, val->draw.w_win,
		val->draw.l_win, "Fractol");
	val->draw.img = mlx_new_image(val->draw.mlx, val->draw.w_win,
		val->draw.l_win);
	val->draw.s_px = mlx_get_data_addr(val->draw.img, &val->draw.bpp,
		&val->draw.sz_ln_px, &val->draw.endian);
	ft_choice_fct(val);
	mlx_mouse_hook(val->draw.win, ft_deal_mouse, val);
	mlx_key_hook(val->draw.win, ft_deal_key, val);
}

int				main(int ac, char **av)
{
	t_values	*val;

	if (ac > 3 && ac < 2)
		ft_usage(val);
	if (!(val = (t_values*)ft_memalloc(sizeof(t_values))))
		exit(1);
	val->choice = ft_atoi(av[1]);
	if (ac == 3)
		val->choice2 = ft_atoi(av[2]);
	if ((ac == 2 && (val->choice > 4 || val->choice < 1))
		|| (ac == 3 && (val->choice2 > 4 || val->choice2 < 1)))
		ft_usage(val);
	ft_params_window(val);
	val->draw.mlx = mlx_init();
	ft_values(val);
	ft_init_image(val);
	if (ac == 3)
	{
		ft_values2(val);
		ft_init_image2(val);
	}
	mlx_loop(val->draw.mlx);
	return (0);
}
