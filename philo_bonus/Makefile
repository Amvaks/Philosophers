SRC = ft_error_and_free_bonus.c ft_atoi_bonus.c simulation_philo_bonus.c philo_bonus.c start_philosophers_bonus.c utils_bonus.c

NAME = philo_bonus

FLAGS = -Wall -Wextra -Werror

OBJ = $(patsubst %.c, %.o, $(SRC))

CC = gcc

INCLUDES = philo_bonus.h

all : $(NAME)

$(NAME) : $(OBJ) $(INCLUDES)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(INCLUDES) philo_bonus.h Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re