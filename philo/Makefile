NAME = philo

SRCS = philo.c \
	   philo_utils.c \
	   philo_routine.c \
	   monitoring.c \
	   init_data.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread

CC = gcc

RM = rm -f

INCLUDE = Makefile philo.h 

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lpthread

%.o: %.c $(INCLUDE)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
