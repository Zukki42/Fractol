# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bavirgil <bavirgil@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 17:22:16 by bavirgil          #+#    #+#              #
#    Updated: 2025/10/11 04:18:15 by bavirgil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler & flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -O2 -fno-math-errno -I. -I$(MLX_DIR) -I$(PRINTF_DIR)
CFLAGS += -g3 -fsanitize=address,undefined -fno-omit-frame-pointer

# Executable
NAME    = fractol

# MiniLibX (Linux)
MLX_DIR   = minilibx-linux
MLX_LIB   = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Your PrintF (ft_printf)
PRINTF_DIR   = PrintF
PRINTF_LIB   = $(PRINTF_DIR)/libftprintf.a
PRINTF_FLAGS = -L$(PRINTF_DIR) -lftprintf

# Headers
HEADERS = fractol.h

# Sources
SRCS = src/main.c \
       src/render.c \
       src/hooks.c \
       src/color.c \
       src/complex.c \
       src/mandelbrot.c \
       src/julia.c \
       src/burning_ship.c \
       src/utils.c

# Objects
OBJS = $(SRCS:.c=.o)

# Tools
RM = rm -f

# Default
all: $(NAME)

# Link (build MLX & PrintF first)
$(NAME): $(OBJS) $(MLX_LIB) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(PRINTF_FLAGS) -o $@

# Build MiniLibX
$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

# Build PrintF
$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

# Compile: each .o depends on headers
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean || true
	$(MAKE) -C $(PRINTF_DIR) clean || true

# Clean all
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean || true

# Rebuild
re: fclean all

.PHONY: all clean fclean re
