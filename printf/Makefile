SRCS = ft_putchar.c ft_putnbr.c ft_putstr.c ft_printf.c ft_putung.c ft_putx.c ft_putp.c\

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:  clean re fclean all
