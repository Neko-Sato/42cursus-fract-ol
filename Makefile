# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 16:52:17 by hshimizu          #+#    #+#              #
#    Updated: 2023/06/22 04:31:34 by hshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS			= -Wall -Wextra -Werror
CFLAGS			+= -g

NAME			= fractol
LIBMLX			= libmlx
FT_PRINTF		= libftprintf
OBJS_DIR		= objs

SRCS			= \
	main.c \
	fractol.c \

OBJS			= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

objs/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $< -o $@

bonus: $(NAME)

clean:
	$(RM) $(FRACTOL)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: $(LIBMLX) $(FT_PRINTF)

# $(LIBMLX):
# 	git submodule add https://github.com/42Paris/minilibx-linux.git $(LIBMLX)
# 	make -C $(LIBMLX)

# $(FT_PRINTF):
# 	git submodule add https://github.com/Neko-Sato/42cursus-ft_printf $(FT_PRINTF)
# 	make -C $(FT_PRINTF)