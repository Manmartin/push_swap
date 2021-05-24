# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 10:37:22 by manmarti          #+#    #+#              #
#    Updated: 2021/05/24 18:11:29 by manmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c parser.c aux.c

OBJS = $(SRCS:.c=.o)


.PHONY: clean fclean re

all: $(NAME)

libft/libft.a:
	$(MAKE) -C ./libft

$(NAME): libft/libft.a $(OBJS)
	gcc -Wall -Wextra -Werror $(SRCS) libft/libft.a -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all


