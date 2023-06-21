# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 16:52:17 by hshimizu          #+#    #+#              #
#    Updated: 2023/06/22 04:22:00 by hshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS			= -Wall -Wextra -Werror
CFLAGS			+= -g

NAME			= fractol
LIBMLX			= libmlx
FT_PRINTF		= libftprintf

FRACTOL			= fractol.o
FRACTOL_SRCS	= fractol.c

MAIN			= main.c
TEST			= test.c

.PHONY: all clean fclean re bonus test

all: $(NAME)

$(FRACTOL): $(FRACTOL_SRCS)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(MAIN) $(FRACTOL)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(NAME)

test: $(TEST) $(FRACTOL)
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) $(FRACTOL)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: $(LIBMLX) $(FT_PRINTF)

# $(LIBMLX):
# 	git clone https://github.com/42Paris/minilibx-linux.git $(LIBMLX)
# 	make -C $(LIBMLX)

# $(FT_PRINTF):
# 	git clone https://github.com/Neko-Sato/42cursus-ft_printf $(FT_PRINTF)
# 	make -C $(FT_PRINTF)