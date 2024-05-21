SRC_CLIENT = client.c client_utils.c
SRC_SERVER = server.c server_utils.c

OBJC=$(SRC_CLIENT:.c=.o)
OBJS=$(SRC_SERVER:.c=.o)

NAME_CLIENT = client
NAME_SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJC) minitalk.h
	make -C ../printf
	$(CC) $(CFLAGS) $(OBJC) ../printf/libftprintf.a -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS) minitalk.h
	$(CC) $(CFLAGS) $(OBJS) ../printf/libftprintf.a -o $(NAME_SERVER)

clean:
	make clean -C ../printf
	$(RM) $(OBJC) $(OBJS)

fclean: clean
	make fclean -C ../printf
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all