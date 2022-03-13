NAME = a.out

CFLAGE = -Wall -Wextra -Werror
SRCS = main.c bubble.c arraylist.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@gcc $(CFLAGE) $(OBJS) -I./

.c.o :
	@gcc $(CFLAGE) -c $? -o $@

clean :
	@rm -rf *.o
	@rm -rf a.out

