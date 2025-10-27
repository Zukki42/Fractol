# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bavirgil <bavirgil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 17:22:16 by bavirgil          #+#    #+#              #
#    Updated: 2025/10/24 14:27:19 by bavirgil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

SRC_DIR := src
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:.c=.o)

MLX_DIR := minilibx-linux
MLX_REPO := https://github.com/42paris/minilibx-linux.git
MLX_LIB := $(MLX_DIR)/libmlx_Linux.a

PRINTF_DIR := PrintF
PRINTF_LIB := $(PRINTF_DIR)/libftprintf.a

CC := cc
CFLAGS := -Wall -Wextra -Werror -O2 -I. -I$(MLX_DIR) -I$(PRINTF_DIR)
LDFLAGS :=
LDLIBS := -L$(MLX_DIR) -lmlx_Linux -L$(PRINTF_DIR) -lftprintf -lXext -lX11 -lm -lz -lbsd

all: $(MLX_LIB) $(PRINTF_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c fractol.h $(MLX_DIR)/mlx.h
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX_DIR)/mlx.h:
	@test -d $(MLX_DIR) || git clone --depth=1 $(MLX_REPO) $(MLX_DIR)

$(MLX_LIB): $(MLX_DIR)/mlx.h
	$(MAKE) -C $(MLX_DIR)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	$(RM) $(OBJS)
	-$(MAKE) -C $(MLX_DIR) clean 2>/dev/null || true
	-$(MAKE) -C $(PRINTF_DIR) clean 2>/dev/null || true

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
