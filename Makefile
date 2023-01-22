NAMESERVER = server
NAMECLIENT = client
NAMEBONUS = client_bonus
LIB = ./src/PRINTF/libftprintf.a
SRCSERVER = server.c
SRCCLIENT = client.c \
			utils.c
SRCCLIENT_BONUS = client_bonus.c \
			utils.c
FLAGS = -Wall -Wextra -Werror
CC = gcc
OBJSERVER = $(SRCSERVER:.c=.o)
OBJCLIENT = $(SRCCLIENT:.c=.o)
OBJCLIENT_BONUS = $(SRCCLIENT_BONUS:.c=.o)

all: $(LIB) $(NAMESERVER) $(NAMECLIENT) $(NAMEBONUS)

$(LIB):
	make -C ./src/PRINTF

$(NAMESERVER) : $(OBJSERVER)
	$(CC) $(OBJSERVER) -o $(NAMESERVER) $(LIB)

$(NAMECLIENT) : $(OBJCLIENT)
	$(CC) $(OBJCLIENT) -o $(NAMECLIENT) $(LIB)

$(NAMEBONUS) : $(OBJCLIENT_BONUS)
	$(CC) $(OBJCLIENT_BONUS) -o $(NAMEBONUS) $(LIB)

clean:
	rm -rf $(OBJSERVER) $(OBJCLIENT) $(OBJCLIENT_BONUS)
	rm -rf ./ft_printf/*.o

fclean: clean
	rm -rf $(NAMESERVER) $(NAMECLIENT) $(NAMEBONUS)
	rm -rf ./src/PRINTF/*.o
	rm -rf ./src/PRINTF/libftprintf.a

re:fclean all

.PHONY : re fclean clean all