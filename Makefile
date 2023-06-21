# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 16:52:17 by hshimizu          #+#    #+#              #
#    Updated: 2023/06/22 06:21:40 by hshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS			= -Wall -Wextra -Werror
CFLAGS			+= -g

NAME			= fractol
DIR				= .
MLX				= $(DIR)/libmlx
FT_PRINTF		= $(DIR)/libftprintf
OBJS_DIR		= $(DIR)/objs
MAIN			= $(DIR)/main.c

SRCS			= \
	$(addprefix $(DIR)/, \
		fractol.c \
		mandelbrot.c \
		julia.c \
	)

OBJS			= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

LIBS			=
LIBS			+= -L$(MLX) -I$(MLX) -lmlx
LIBS			+= -L$(FT_PRINTF) -I$(FT_PRINTF) -lftprintf

.PHONY: all clean fclean re bonus

all: $(MLX) $(FT_PRINTF) $(NAME)

$(NAME): $(MAIN) $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

bonus: $(NAME)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $< -o $@ $(LIBS)

clean:
	$(RM) $(OBJS)

fclean: clean
	@make -C $(MLX) clean
	@make -C $(FT_PRINTF) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: $(MLX)
$(MLX):
	@make -C $@

.PHONY: $(FT_PRINTF)
$(FT_PRINTF):
	@make -C $@