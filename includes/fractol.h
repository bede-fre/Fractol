/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:53:11 by bede-fre          #+#    #+#             */
/*   Updated: 2019/01/24 16:09:31 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_P 35
# define KEY_S 1
# define KEY_0 29
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 23
# define KEY_6 22
# define KEY_7 26
# define KEY_8 28
# define KEY_9 25
# define KEY_MINUS 27
# define KEY_PLUS 24
# define KEY_SPACE 49
# define KEY_ECHAP 53
# define BUTTON_SCROLLUP 4
# define BUTTON_SCROLLDOWN 5
# define WHITE 0xFFFFFF
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define TRICORN 4
# define BLACK_AND_WHITE 1
# define RED 2
# define GREEN 3
# define BLUE 4
# define PSYCHEDELIC 5
# define WHITE_AND_BLACK 6
# define SMOOTH_GRADIANT 7

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
	double			j;
	unsigned char	col0;
	unsigned char	col1;
	unsigned char	col2;
	int				color;
}					t_fract;

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
	int				helpers;
	int				red;
	int				red2;
	int				green;
	int				green2;
	int				blue;
	int				blue2;
	t_fract			fct;
	t_fract			fct2;
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
void				ft_tricorn(t_values *val);
void				ft_tricorn2(t_values *val);
void				ft_init_values_fct(t_values *val);
void				ft_init_values_fct2(t_values *val);
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
void				ft_choice_fct(t_values *val);
void				ft_choice_fct2(t_values *val);
void				ft_str_fct(t_values *val);
void				ft_str_fct2(t_values *val);
int					ft_smooth_gradient(t_values *val);
int					ft_smooth_gradient2(t_values *val);
void				ft_display_instructions(t_values *val);
void				ft_init_image2(t_values *val);
void				ft_show_and_hide_help(t_values *val);

#endif
