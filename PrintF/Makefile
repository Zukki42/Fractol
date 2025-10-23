# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bavirgil <bavirgil@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 17:45:30 by bavirgil          #+#    #+#              #
#    Updated: 2025/08/10 20:49:30 by bavirgil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c simple.c complex.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar -rcs
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)
	
clean: 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re