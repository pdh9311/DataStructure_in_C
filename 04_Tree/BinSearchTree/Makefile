NAME = a.out

# CFLAGE = -Wall -Wextra -Werror 
SRCS = main.c BinSearchTree.c linkeddeque.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@gcc -g $(CFLAGE) $(OBJS) -I./

.c.o :
	@gcc -g $(CFLAGE) -c $? -o $@

clean :
	@rm -rf *.o
	@rm -rf a.out
