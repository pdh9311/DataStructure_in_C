NAME = a.out

CFLAGE = -Wall -Wextra -Werror
SRCS = main.c circularlist.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	gcc $(CFLAGE) $(OBJS) -I./

.c.o :
	gcc $(CFLAGE) -c $? -o $@

clean :
	rm -rf *.o
	rm -rf a.out

