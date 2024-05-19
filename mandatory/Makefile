SRC_CLIENT = client.c client_utils.c
SRC_SERVER = server.c

NAME_CLIENT = client
NAME_SERVER = server

CC = cc
CFLAGS =
RM = rm -f

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(SRC_CLIENT) client.h
	$(CC) $(CFLAGS) $(SRC_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER): $(SRC_SERVER)
	$(CC) $(CFLAGS) $(SRC_SERVER) -o $(NAME_SERVER)

fclean:
	$(RM) $(NAME_CLIENT) $(NAME_SERVER) 