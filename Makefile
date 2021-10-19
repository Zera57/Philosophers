NAME = philo
CFLAGS = -Wall -Wextra -Werror -g
SRCS =	./InitPhilosophers.c\
		./Logs.c\
		./main.c\
		./Parser.c\
		./PhiloAction.c\
		./PhiloActionWatcher.c\
		./Threads.c

HEAD = philo.h
OFILE = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OFILE)
	gcc -o $(NAME) $(OFILE) -lpthread

clean: 
	rm -f $(OFILE)

fclean: clean
	rm -f $(NAME)

re: fclean all

norme:
	Norminette $(SRCS) ./philo.h

.PHONY: all clean fclean re %.o