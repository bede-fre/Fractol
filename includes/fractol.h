/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:53:11 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/19 17:31:17 by bede-fre         ###   ########.fr       */
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
	double			z_n;
	double			continuous_index;
	unsigned char	channel0;
	unsigned char	channel1;
	unsigned char	channel2;
	unsigned char	channel3;
	int				color;
}					t_fract2;

typedef struct		s_draw
{
	void			*mlx;
	void			*win;
	void			*win2;
	void			*win3;
	void			*img;
	void			*img2;
	void			*img3;
	char			*s_px;
	char			*s_px2;
	char			*s_px3;
	int				endian;
	int				bpp;
	int				sz_ln_px;
	double			zoom;
	double			zoom2;
	double			coef_zoom;
	double			coef_zoom2;
	double			l_win;
	double			w_win;
}					t_draw;

typedef struct		s_values
{
	char			choice;
	char			choice2;
	char			stop;
	char			stop2;
	char			set;
	char			set2;
	int				red;
	int				red2;
	int				green;
	int				green2;
	int				blue;
	int				blue2;
	t_fract			fract;
	t_fract			fract2;
	t_draw			draw;
}					t_values;

void				ft_fill_px(t_values *val, int x, int y, int color);
void				ft_fill_px2(t_values *val, int x, int y, int color);
void				ft_mandelbrot(t_values *val);
void				ft_mandelbrot2(t_values *val);
void				ft_julia(t_values *val);
void				ft_julia2(t_values *val);
void				ft_burning_ship(t_values *val);
void				ft_burning_ship2(t_values *val);
void				ft_init_values_fract(t_values *val);
void				ft_init_values_fract2(t_values *val);
int					ft_deal_key(int key, t_values *val);
int					ft_deal_key2(int key, t_values *val);
int					ft_deal_mouse(int mouse, int x, int y, t_values *val);
int					ft_deal_mouse2(int mouse, int x, int y, t_values *val);
void				ft_values(t_values *val);
void				ft_values2(t_values *val);
int					ft_color(t_values *val);
int					ft_color2(t_values *val);
int					ft_mouse_cord(int x, int y, t_values *val);
int					ft_mouse_cord2(int x, int y, t_values *val);
void				ft_choice_fract(t_values *val);
void				ft_choice_fract2(t_values *val);
void				ft_str_fract(t_values *val);
void				ft_str_fract2(t_values *val);
int					ft_smooth_gradient(t_values *val);
int					ft_smooth_gradient2(t_values *val);
void				ft_display_instructions(t_values *val);
void				ft_init_image2(t_values *val);

#endif
