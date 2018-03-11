/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:14:54 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/08 16:14:29 by bede-fre         ###   ########.fr       */
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

static void		ft_params_window(t_values *val, char *len, char *wid)
{
	val->draw.l_win = (double)(ft_atoi(len));
	val->draw.w_win = (double)(ft_atoi(wid));
	val->draw.var_x = (val->draw.l_win / 2.0);
	val->draw.var_y = (val->draw.w_win / 2.0);
	val->draw.var_x2 = (val->draw.l_win / 2.0);
	val->draw.var_y2 = (val->draw.w_win / 2.0);
	val->draw.zoom = 100.0;
	val->draw.zoom2 = 100.0;
}

static void		ft_init_image(t_values *val)
{
	val->draw.win = mlx_new_window(val->draw.mlx, val->draw.w_win,
		val->draw.l_win, "Fractol_1");
    val->draw.img = mlx_new_image(val->draw.mlx, val->draw.w_win,
		val->draw.l_win);
    val->draw.s_px = mlx_get_data_addr(val->draw.img, &val->draw.bpp,
		&val->draw.sz_ln_px, &val->draw.endian);
    if (val->choice1 == 1)
    	ft_mandelbrot(val, val->draw.var_x, val->draw.var_y, val->draw.zoom);
    if (val->choice1 == 2)
        ft_julia(val, val->draw.var_x, val->draw.var_y, val->draw.zoom);
    if (val->choice1 == 3)
        ft_burning_ship(val, val->draw.var_x, val->draw.var_y, val->draw.zoom);
    mlx_put_image_to_window(val->draw.mlx, val->draw.win, val->draw.img, 0, 0);
	mlx_key_hook(val->draw.win, ft_deal_key, val);
}

static void		ft_init_image2(t_values *val)
{
	val->draw.win2 = mlx_new_window(val->draw.mlx, val->draw.w_win,
		val->draw.l_win, "Fractol_2");
	val->draw.img2 = mlx_new_image(val->draw.mlx, val->draw.w_win,
		val->draw.l_win);
	val->draw.s_px = mlx_get_data_addr(val->draw.img2, &val->draw.bpp,
		&val->draw.sz_ln_px, &val->draw.endian);
    if (val->choice2 == 1)
    	ft_mandelbrot(val, val->draw.var_x2, val->draw.var_y2, val->draw.zoom2);
    if (val->choice2 == 2)
        ft_julia(val, val->draw.var_x2, val->draw.var_y2, val->draw.zoom2);
    if (val->choice2 == 3)
        ft_burning_ship(val, val->draw.var_x2, val->draw.var_y2, val->draw.zoom2);
    mlx_put_image_to_window(val->draw.mlx, val->draw.win2, val->draw.img2, 0, 0);
	mlx_key_hook(val->draw.win2, ft_deal_key2, val);
}

int				main(int ac, char **av)
{
	t_values	*val;

    if (ac != 5)
		ft_usage();
    else
    {
	    if (!(val = (t_values*)ft_memalloc(sizeof(t_values))))
		    exit(1);
        val->choice1 = ft_atoi(av[1]);
        val->choice2 = ft_atoi(av[2]);
        if ((val->choice1 > 4 && val->choice1 < 1) && (val->choice2 > 4 &&
            val->choice2 < 1))
        {
		    free(val);
            ft_usage();
        }
        ft_params_window(val, av[3], av[4]);
        val->draw.mlx = mlx_init();
        ft_init_image(val);
        ft_init_image2(val);
        mlx_loop(val->draw.mlx);
    }
	return (0);
}
