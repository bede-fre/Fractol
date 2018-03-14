/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:14:54 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/14 19:25:31 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_usage(void)
{
	ft_putendl_fd("Usage : ./fractol choice_fractal", 2);
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
	val->draw.coef_zoom = 1.5;
	val->stop = 0;
	val->set = 1;
}

int				ft_mouse_cord(int x, int y, t_values *val)
{
	if (val->stop == 0)
	{
		val->fract.c_r = (double)x / (val->draw.w_win / (3.2)) - 1.6;
		val->fract.c_i = (double)y / (val->draw.l_win / (2.4)) - 1.2;
	}
	if (val->choice == 2)
		ft_julia(val);
	mlx_put_image_to_window(val->draw.mlx, val->draw.win, val->draw.img, 0, 0);
	return (0);
}

static void		ft_init_image(t_values *val)
{
	val->draw.win = mlx_new_window(val->draw.mlx, val->draw.w_win,
		val->draw.l_win, "Fractol_1");
	val->draw.img = mlx_new_image(val->draw.mlx, val->draw.w_win,
		val->draw.l_win);
	val->draw.s_px = mlx_get_data_addr(val->draw.img, &val->draw.bpp,
		&val->draw.sz_ln_px, &val->draw.endian);
	ft_choice_fract(val);
}

int				main(int ac, char **av)
{
	t_values	*val;

	if (ac != 2)
		ft_usage();
	else
	{
		if (!(val = (t_values*)ft_memalloc(sizeof(t_values))))
			exit(1);
		val->choice = ft_atoi(av[1]);
		if (val->choice > 3 || val->choice < 1)
		{
			free(val);
			ft_usage();
		}
		ft_params_window(val);
		val->draw.mlx = mlx_init();
		ft_values(val);
		ft_init_image(val);
		mlx_mouse_hook(val->draw.win, ft_deal_mouse, val);
		mlx_key_hook(val->draw.win, ft_deal_key, val);
		mlx_loop(val->draw.mlx);
	}
	return (0);
}
