# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 14:51:15 by hshimizu          #+#    #+#              #
#    Updated: 2023/09/28 20:59:50 by hshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fractol

DIR				= .
FT				= $(DIR)/libft
MLX				= $(DIR)/libmlx
INCS_DIR		= $(DIR)/incs
OBJS_DIR		= $(DIR)/objs

MAIN			= $(DIR)/main.c

SRCS			= \
	$(addprefix $(DIR)/srcs/, \
		ft_complex_basic_function.c \
		ft_complex_basic_operator.c \
		ft_complex_function.c \
		color.c \
		utils.c \
		renderer.c \
		fractol.c \
		julia.c \
		mandelbrot.c \
	)

OBJS			= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

CFLAGS			= -Wall -Wextra -Werror
CFLAGS			+= -g
IDFLAGS			= -I$(INCS_DIR)
LDFLAGS			+= -L$(FT)
IDFLAGS			+= -I$(FT)
LDFLAGS			+= -L$(MLX)
IDFLAGS			+= -I$(MLX)
LIBS			= -lft -lmlx -lm -lXext -lX11

.PHONY: all clean fclean re bonus

all: $(FT) $(MLX) $(NAME)

$(NAME): $(MAIN) $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(IDFLAGS) $^ -o $@ $(LIBS)

bonus: 
	@echo bonus

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $(IDFLAGS) $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	@make -C $(FT) fclean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: test
test: test.c $(OBJS)
	$(CC) -g $(CFLAGS) $(LDFLAGS) $(IDFLAGS) $^ -o $@ $(LIBS)

.PHONY: norm
norm: $(MAIN) $(SRCS) $(INCS_DIR)
	@norminette $^

.PHONY: $(FT)
$(FT):
	# @git submodule update --init $@
	@make -C $@ all

.PHONY: $(MLX)
$(MLX):
	@git submodule update --init $@
	@make -C $@
