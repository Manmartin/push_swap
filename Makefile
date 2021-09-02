NAME = push_swap

SRCS =	push_swap.c \
		parser.c \
		aux.c \
		sorter.c \
		functions/swap.c functions/rotate.c functions/r_rotate.c functions/push.c

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


