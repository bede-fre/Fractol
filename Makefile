# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 12:44:25 by bede-fre          #+#    #+#              #
#    Updated: 2019/01/24 14:57:40 by bede-fre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
CC			= clang
SRC 		= main.c ft_burning_ship.c ft_julia.c \
			ft_mandelbrot.c ft_values_and_color.c \
			ft_mouse_events.c ft_keyboard_events.c \
			ft_gradient.c ft_values_and_color2.c ft_keyboard_events2.c \
			ft_fractal_2.c ft_tricorn.c
INCLUDES	= ./includes
LIBFT		= ./libft/libft.a
MINILIBX	= ./minilibx/libmlx.a
OBJ			= $(addprefix ./sources/, $(SRC:.c=.o))
FLAGS		= -Wall -Wextra -Werror
FRAMEWORK	= -lpthread -framework OpenGL -framework Appkit

_GREY		= "\033[30m"
_RED		= "\033[31m"
_GREEN		= "\033[32m"
_YELLOW		= "\033[33m"
_BLUE		= "\033[34m"
_PURPLE		= "\033[35m"
_CYAN		= "\033[36m"
_WHITE		= "\033[37m"
_END		= "\033[0m"
_BOLD		= "\033[1m"
_CLEAR		= "\033[2K"
_SAVE		= "\033[7"
_BACK		= "\033[8"
_HIDE_CURS	= "\033[?25l"
_SHOW_CURS	= "\033[?25h"
_UP		= "\033[A"
_CUT		= "\033[k"

.PHONY: all libft minilibx clean fclean re

all: libft minilibx $(NAME)

libft:
	@make -C libft

minilibx:
	@make -C minilibx

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(FRAMEWORK) $(OBJ) $(MINILIBX) $(LIBFT) -o $(NAME)
	@echo $(_CLEAR)$(_CYAN)"# EXECUTABLE FILE CREATION # "$(_GREEN)fractol$(_END)
	@printf $(_GREEN)"# EXECUTABLE FILE CREATED #\n"$(_END)$(_SHOW_CURS)

%.o: %.c
	@$(CC) $(FLAGS) -I $(INCLUDES) -c $^ -o $@
	@echo $(_CLEAR)$(_CYAN)"# EXECUTABLE FILE CREATION # "$(_YELLOW)$@$(_END)
	@printf $(_HIDE_CURS)$(_UP)$(_CUT)

clean:
	@make -C libft clean
	@make -C minilibx clean
	@/bin/rm -f $(OBJ)
	@echo $(_RED)"# DELETE EXECUTABLE OBJECT FILES #"$(_END)


fclean: clean
	@/bin/rm -f $(NAME) $(LIBFT)
	@echo $(_RED)"# DELETE LIBRARY FILE #"$(_END)
	@echo $(_RED)"# DELETE EXECUTABLE FILE #"$(_END)

re: fclean all
