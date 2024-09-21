NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror  -fsanitize=address -g -I ./includes

RM = rm -rf

SRCS = 		mandatory/philo.c				\
			mandatory/parsing.c				\
			mandatory/init.c				\
			lib_utils/ft_atoi.c				\
			lib_utils/ft_usleep.c			\
			lib_utils/utils.c				\
			lib_utils/test.c				\


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:%.c includes/philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean