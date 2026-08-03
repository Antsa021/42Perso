# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/11 00:00:00 by senandri          #+#    #+#              #
#    Updated: 2026/07/11 00:00:00 by senandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c \
		  ps_errors.c \
		  ps_parsing.c \
		  ps_stack.c \
		  op_swap.c \
		  op_push.c \
		  op_rotate.c \
		  op_rrotate.c \
		  adaptive.c \
		  simple.c \
		  medium_utils.c \
		  medium.c \
		  complex.c \
		  bench.c

OBJS	= $(SRCS:.c=.o)
LIBFT	= LIBFT/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C LIBFT

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C LIBFT clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C LIBFT fclean

re: fclean all

.PHONY: all clean fclean re
