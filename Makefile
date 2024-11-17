NAME = philo

CC = cc

# CFLAGS = -g3 -fsanitize=thread -I ./includes
CFLAGS = -Wall -Wextra -Werror  -I ./includes

RM = rm -rf

SRCS = 		mandatory/main.c				\
			mandatory/parsing.c				\
			mandatory/init.c				\
			mandatory/diner.c				\
			lib_utils/ft_atoi.c				\
			lib_utils/ft_usleep.c			\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:%.c includes/philo.h
	$(CC) $(CFLAGS) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean