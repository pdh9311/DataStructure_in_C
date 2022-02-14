.SUFFIXES : .c .o
SRCS			=	main_bank.c en_queue.c de_queue.c \
					creat_sim.c account_wait.c

OBJS			=	$(SRCS:.c=.o)

CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -g

NAME			=	test

all:			$(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(OBJS_B)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)
