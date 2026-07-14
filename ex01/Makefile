CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes
AR = ar
ARFLAGS = rcs
SRCS = src/ft_putchar.c src/ft_putstr.c src/ft_strlen.c src/ft_strcmp.c src/ft_swap.c
OBJS = $(SRCS:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
