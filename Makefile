NAME:= minitalk

CC:= gcc
CFLAGS:= -Wall -Werror -Wextra

all: server client client2
#all: server client

server: utils.c utils2.c utils3.c
	$(CC) $(CFLAGS) -g $^ server.c -o $@

client: utils.c utils2.c utils3.c
	$(CC) $(CFLAGS) -g $^ client.c -o $@

client2: utils.c utils2.c utils3.c
	$(CC) $(CFLAGS) -g $^ client2.c -o $@

clean:
	rm -rf server client client2 *.dSYM

fclean: clean

re: fclean all

norminette:
	norminette server.c
	norminette client.c
	norminette utils.c
	norminette -R CheckforbiddenHeader *.h

.PHONY: all clean fclean re norminette
