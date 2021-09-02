NAME = push_swap

SRCS =	push_swap.c \
		parser.c \
		aux.c \
		sorter.c \
		functions/swap.c functions/rotate.c functions/r_rotate.c functions/push.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = gcc

.PHONY: clean fclean re

all: $(NAME)

libft/libft.a:
	$(MAKE) -C ./libft

$(NAME): libft/libft.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) fclean -C ./libft

fclean: clean
	rm -f $(NAME)

re: fclean all


