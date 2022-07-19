SRC = ft_error_and_free.c ft_atoi.c simulation_philo.c philo.c start_philosophers.c utils.c

NAME = philo

FLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread

OBJ = $(patsubst %.c, %.o, $(SRC))

CC = gcc

INCLUDES = philo.h

all : $(NAME)

$(NAME) : $(OBJ) $(INCLUDES)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c philo.h Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re