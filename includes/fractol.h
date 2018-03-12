/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:53:11 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/12 16:28:11 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_fract
{
	double			x;
	double			x1;
	double			x2;
	double			y;
	double			y1;
	double			y2;
	double			i;
	double			i_max;
	double			img_x;
	double			img_y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tp;
}					t_fract;

typedef struct		s_fract2
{
	double			x;
	double			x1;
	double			x2;
	double			y;
	double			y1;
	double			y2;
	double			i;
	double			i_max;
	double			img_x;
	double			img_y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tp;
}					t_fract2;

typedef struct		s_draw
{
	void			*mlx;
	void			*win;
	void			*win2;
	void			*img;
	void			*img2;
	char			*s_px;
	int				endian;
	int				bpp;
	int				sz_ln_px;
	double			zoom;
	double			zoom2;
	double			l_win;
	double			w_win;
	double			var_x;
	double			var_x2;
	double			var_y;
	double			var_y2;
	double			r;
}					t_draw;

typedef struct		s_values
{
	int				choice1;
	int				choice2;
	t_fract			fract;
	t_fract2		fract2;
	t_draw			draw;
}					t_values;

void				ft_fill_px(t_values *val, int x, int y, int color);
void				ft_mandelbrot(t_values *val, double var_x, double var_y, double zoom);
void				ft_julia(t_values *val, double var_x, double var_y, double zoom);
void				ft_burning_ship(t_values *val, double var_x, double var_y, double zoom);
int					ft_deal_key(int key, t_values *val);
int					ft_deal_mouse(int mouse, t_values *val);
int					ft_deal_key2(int key, t_values *val);
int					ft_deal_mouse2(int mouse, t_values *val);
int					ft_merge_color(unsigned char red, unsigned char green,
		unsigned char blue);

#endif
