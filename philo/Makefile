NAME = philo

SRC = philo.c \
      philo_utils.c \
      parsing.c \
	  data_init.c \
	  threads.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror #-pthread

CC = cc

RM = -rm -f

INCLUDE = philo.h Makefile

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: re all clean fclean
