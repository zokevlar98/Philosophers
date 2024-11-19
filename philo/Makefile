
NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS = 		main.c				\
			parsing.c			\
			init.c				\
			diner.c				\
			ft_atoi.c			\
			ft_usleep.c			\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:%.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean