NAME = a.out

CFLAGE = -Wall -Wextra -Werror -g
SRCS = main.c BinSearchTree.c linkeddeque.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@gcc $(CFLAGE) $(OBJS) -I./

.c.o :
	@gcc $(CFLAGE) -c $? -o $@

clean :
	@rm -rf *.o
	@rm -rf a.out
