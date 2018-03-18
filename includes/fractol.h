/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:53:11 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/16 16:54:55 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

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
	double			z_n;
	double			continuous_index;
	unsigned char	channel0;
	unsigned char	channel1;
	unsigned char	channel2;
	unsigned char	channel3;
	int				color;
}					t_fract;

typedef struct		s_draw
{
	void			*mlx;
	void			*win;
	void			*win2;
	void			*img;
	void			*img2;
	char			*s_px;
	char			*s_px2;
	int				endian;
	int				bpp;
	int				sz_ln_px;
	double			zoom;
	double			coef_zoom;
	double			l_win;
	double			w_win;
}					t_draw;

typedef struct		s_values
{
	char			choice;
	char			stop;
	char			set;
	int				red;
	int				green;
	int				blue;
	t_fract			fract;
	t_draw			draw;
}					t_values;

void				ft_fill_px(t_values *val, int x, int y, int color);
void				ft_mandelbrot(t_values *val);
void				ft_julia(t_values *val);
void				ft_burning_ship(t_values *val);
void				ft_init_values_fract(t_values *val);
int					ft_deal_key(int key, t_values *val);
int					ft_deal_mouse(int mouse, int x, int y, t_values *val);
void				ft_values(t_values *val);
int					ft_color(t_values *val);
int					ft_mouse_cord(int x, int y, t_values *val);
void				ft_choice_fract(t_values *val);
void				ft_str_fract(t_values *val);

#endif
