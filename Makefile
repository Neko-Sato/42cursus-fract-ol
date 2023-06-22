# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 16:52:17 by hshimizu          #+#    #+#              #
#    Updated: 2023/06/23 03:06:50 by hshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fractol
DIR				= .
MLX				= $(DIR)/libmlx
FT				= $(DIR)/libft
FT_PRINTF		= $(DIR)/libftprintf
OBJS_DIR		= $(DIR)/objs
MAIN			= $(DIR)/main.c

SRCS			= \
	$(addprefix $(DIR)/, \
		ft_complex_basic_operator.c \
		ft_complex_basic_func.c \
		ft_complex_func.c \
		ft_atof.c \
		fractol.c \
		mandelbrot.c \
		julia.c \
		error.c \
	)

OBJS			= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

CC				= clang
CFLAGS			= -Wall -Wextra -Werror
CFLAGS			+= -g
LDFLAGS			= -L$(MLX) -L$(FT) -L$(FT_PRINTF)
IDFLAGS			= -I$(MLX) -I$(FT) -I$(FT_PRINTF)
LIBS			= -lXext -lX11 -lm -lmlx -lft -lftprintf

.PHONY: all clean fclean re bonus

all: $(MLX) $(FT) $(FT_PRINTF) $(NAME)

$(NAME): $(MAIN) $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(IDFLAGS) $^ -o $@ $(LIBS)

bonus: $(NAME)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $(IDFLAGS) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	@make -C $(MLX) clean
	@make -C $(FT) fclean
	@make -C $(FT_PRINTF) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: test
test: test.c $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(IDFLAGS) $^ -o $@ $(LIBS)

.PHONY: norm
norm: $(SRCS)
	@norminette $^

.PHONY: $(MLX)
$(MLX):
	@make -C $@

.PHONY: $(FT)
$(FT):
	@make -C $@

.PHONY: $(FT_PRINTF)
$(FT_PRINTF):
	@make -C $@
